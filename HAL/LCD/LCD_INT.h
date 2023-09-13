/****************************************************/
/******** Author     : Shadi Bahaa   ****************/
/******** File name  : LCD_INT.h  ****************/
/******** Date       : Aug 20, 2023       ****************/
/******** Version    : V1            ****************/
/******** Desc       : ...           ****************/
/****************************************************/
#ifndef LCD_INT_H_
#define LCD_INT_H_

#define CONTROL_PORT PORT_D
#define RS 4
#define RW 5
#define EN 6

#define DATA_PORT PORT_C

#define FUNCTION_SET 0b00111000
#define DISPLAY_ON 0b00001111
#define DISPLAY_CLEAR 0x01
#define ENTRY_MODE_SET 0b00000110

#define ROW1_Address	0x80 // Set DDRAM address command + row 1 address
#define ROW2_Address	0xC0// Set DDRAM address command�+�row�2�address

void HLCD_vInit(void);
void HLCD_vSendCommand(u8 A_u8Command);
void HLCD_vSendData(u8 A_u8Data);
void HLCD_vSendString(u8 * A_ptrToString);
void HLCD_vDisplayClear(void);
void HLCD_vMoveTo(u8 A_u8Row, u8 A_u8Col);
void HLCD_vSendNumber(s32 A_s32Number);
void HLCD_vSetCursorPosition(s32 A_s32RowNumber,s32 A_s32ColumnNumber);
void HLCD_vSendString_pos(s8 *A_s8String ,s32 A_s32RowNumber,s32 A_s32ColumnNumber);

#endif /* LCD_INT_H_ */
