/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : Smart_Home_System                                     */
/* File          : app.c                                                 */
/* Date          : Sep 10, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "app.h"

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

	/* Switches and EXTI Init */

	/* Keypad Init */

	/* LCD Init */

	/* UART Init */

}

uint8 Read_Password(void){
	/*
	 * Read password from keypad
	 * If password is correct, return 0
	 * If password is incorrect, return 1
	 */
	return 0;
}

uint8 Get_Temperature_Value(void){
	uint8 ret_val = 50; // Dummy Initialization

	return ret_val;
}

uint16 Get_LDR_Value(void){
	uint16 ret_val = 512; // Dummy Initialization

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
	while(1);
}
