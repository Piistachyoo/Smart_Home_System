/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : Smart_Home_System                                     */
/* File          : main.c                           					 */
/* Date          : Sep 10, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "app.h"
#include "../HAL/LCD/LCD_INT.h"
#include "../HAL/KPD/KPD_INT.h"
#include "../HAL/LM35/LM35_Interface.h"
#include "../HAL/LDR/LDR_Interface.h"
#include <util/delay.h>

int main(void){
	u8 login_tries = 0;
	u8 temp_value;
	u16 ldr_value;
	u8 str[] = "Try Again!";
	u8 strAcsess[] = "You can Access!";
	app_init();
	while(1){
		if(Read_Password()){
			login_tries++;
			if(MAX_LOGIN_TRIES <= login_tries)
				Halt_System();
			else{
				HLCD_vDisplayClear();
				HLCD_vSendString(str);
				_delay_ms(300);
				HLCD_vDisplayClear();
				continue;
			}
		}
		else{
			HLCD_vDisplayClear();
			HLCD_vSendString(strAcsess);
			_delay_ms(300);
			HLCD_vDisplayClear();
			break;
		}

	}

	while(1){
		u8 strtemp[] = "Temperature: ";
		u8 strldr[] =  "Sensor LDR: ";
		u8 strspace[] = "   ";
		temp_value = Get_Temperature_Value();
		ldr_value = Get_LDR_Value();
		HLCD_vSendString(strtemp);
		HLCD_vSendNumber(temp_value);
		HLCD_vSendData('C');
		HLCD_vSetCursorPosition(2, 1);
		HLCD_vSendString(strldr);
		HLCD_vSendNumber(ldr_value);
		HLCD_vSendData('C');
		_delay_ms(1000);
		HLCD_vSendString_pos(strspace, 1, 14);
		HLCD_vSendString_pos(strspace, 2, 13);
		_delay_ms(1000);
		if(TEMP_THRESHOLD < temp_value)
			Set_Motor_Value(Motor_ON);
		else
			Set_Motor_Value(Motor_OFF);
		if(LDR_THRESHOLD < ldr_value)
			Set_Lamp_Value(Lamp_ON);
		else
			Set_Lamp_Value(Motor_OFF);
	}
	return 0;
}
