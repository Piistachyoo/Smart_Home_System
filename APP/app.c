/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : Smart_Home_System                                     */
/* File          : app.c                                                 */
/* Date          : Sep 10, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "app.h"
#include "../HAL/KPD/KPD_INT.h"
#include "../HAL/LCD/LCD_INT.h"
#include "../HAL/LM35/LM35_Interface.h"
#include "../HAL/LDR/LDR_Interface.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include <util/delay.h>

#define SYSTEM_PSW		1234

void SW1_Callback(void){
	/*
	 * Check for SW1 status,
	 * if pressed -> turn on motor
	 * if not pressed -> turn off motor
	 */

}

void SW2_Callback(void){
	/*
	 * Check for SW2 status,
	 * if pressed -> turn on lamp
	 * if not pressed -> turn off lamp
	 */
}

void app_init(void){
	/* Motor Pins Init */

	/* Lamp Pin Init */

	/* ADC Init */
	MADC_vInit();

	/* Switches and EXTI Init */

	/* Keypad Init */
	HKPD_Init();

	/* LCD Init */
	HLCD_vInit();

	/* UART Init */

}

u8 Read_Password(void){
	/*
	 * Read password from keypad
	 * If password is correct, return 0
	 * If password is incorrect, return 1
	 */
    u8 str[] = "Your Password: ";
    //u8 strinvalid[] = "invalid character";
    u8 keypad_entry;
    u32 password = 0;
    HLCD_vSendString(str);
	HLCD_vSetCursorPosition(2, 1);

    while (1) {
        keypad_entry = HKPD_U8GetPressedKey();

        if (keypad_entry == '=') {
            break;
        } else if ((keypad_entry >= '0') && (keypad_entry <= '9')) {
            HLCD_vSendData(keypad_entry);
            _delay_ms(50);
            password = (password * 10) + (keypad_entry - '0');
        } else {
            // Handle invalid characters (e.g., display an error message)
        	//HLCD_vSendString(strinvalid);
        }
    }

    password /= 10;

    // Check if the entered password is correct
    u8 ret_val = (password == SYSTEM_PSW) ? 1 : 0;
    u8 strEntr[] = "Entered: ";
    u8 strExp[]  = "Expected: ";
    HLCD_vDisplayClear();
    HLCD_vSetCursorPosition(1, 1); // Adjust the cursor position
    HLCD_vSendString(strEntr);
    HLCD_vSendNumber(password);
    _delay_ms(500);
    HLCD_vDisplayClear();
    HLCD_vSetCursorPosition(1, 1); // Adjust the cursor position
    HLCD_vSendString(strExp);
    HLCD_vSendNumber(SYSTEM_PSW);
    _delay_ms(500);
    HLCD_vDisplayClear();
    return ret_val;

}

u8 Get_Temperature_Value(void){
	u8 ret_val = HLM35_vCallValue();

	return ret_val;
}

u16 Get_LDR_Value(void){
	u16 ret_val = HLDR_vCallValue();

	return ret_val;
}

void Set_Lamp_Value(enu_LampControl _val){

}

void Set_Motor_Value(enu_MotorControl _val){

}

void Halt_System(void){
	/*
	 * Freeze LCD and UART
	 * De-Init all hardware except LCD
	 * Halt system
	 */
	u8 str[] = "System is Halt!";
	HLCD_vSendString(str);
	while(1);
}
