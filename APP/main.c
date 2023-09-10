/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : Smart_Home_System                                     */
/* File          : main.c                           					 */
/* Date          : Sep 10, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "app.h"

int main(void){
	uint8 login_tries = 0;
	uint8 temp_value;
	uint16 ldr_value;
	app_init();
	while(1){
		if(Read_Password()){
			login_tries++;
			if(MAX_LOGIN_TRIES <= login_tries)
				Halt_System();
			else
				continue;
		}
		else
			break;
	}

	while(1){
		temp_value = Get_Temperature_Value();
		ldr_value = Get_LDR_Value();
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
