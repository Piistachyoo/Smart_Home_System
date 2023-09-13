/*
 * KPD_INT.h
 *
 *  Created on: Sep 6, 2023
 *      Author: hp
 */

#ifndef KPD_INT_H_
#define KPD_INT_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_LIB.h"

#define KPD_PORT PORT_B

void HKPD_Init(void);
u8 HKPD_U8GetPressedKey(void);

#endif /* KPD_INT_H_ */
