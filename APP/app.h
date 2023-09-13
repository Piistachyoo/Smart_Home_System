/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : Smart_Home_System                                     */
/* File          : app.h                                                 */
/* Date          : Sep 10, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef APP_APP_H_
#define APP_APP_H_

//----------------------------------------------
// Section: Includes
//----------------------------------------------
#include "../LIB/STD_LIB.h"

//----------------------------------------------
// Section: User type definitions
//----------------------------------------------
typedef enum{
	Lamp_OFF,
	Lamp_ON
}enu_LampControl;

typedef enum{
	Motor_OFF,
	Motor_ON
}enu_MotorControl;

//----------------------------------------------
// Section: Macros Configuration
//----------------------------------------------

#define MAX_LOGIN_TRIES		3
#define TEMP_THRESHOLD		30
#define LDR_THRESHOLD		511
#define MAX_SIZEOFPASSWORD  4

/*
 * =============================================
 * APIs Supported by "APP"
 * =============================================
 */

void app_init(void);
u8 Read_Password(void);
u8 Get_Temperature_Value(void);
u16 Get_LDR_Value(void);
void Set_Lamp_Value(enu_LampControl _val);
void Set_Motor_Value(enu_MotorControl _val);
void Halt_System(void);


#endif /* APP_APP_H_ */
