/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : ITI_AVR_Drivers                                    	 */
/* File          : STD_LIB.h                           					 */
/* Date          : Aug 19, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef SERVICES_STD_LIB_H_
#define SERVICES_STD_LIB_H_

typedef unsigned char u8;
typedef signed char s8;

typedef unsigned short int u16;
typedef unsigned long int u32;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;
typedef long double f96;


typedef enum{
	RET_OK = 0,
	RET_NOT_OK = 1
}Std_Returntype;

#ifndef NULL
#define NULL	0
#endif

typedef enum{
	pollingEnable,
	pollingDisable
}polling_t;

#endif /* SERVICES_STD_LIB_H_ */
