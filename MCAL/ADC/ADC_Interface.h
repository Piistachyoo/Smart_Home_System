/*
 * ADC_Interface.h
 *
 *  Created on: Sep 11, 2023
 *      Author: hp
 */

#ifndef COTS_MCAL_ADC_ADC_INTERFACE_H_
#define COTS_MCAL_ADC_ADC_INTERFACE_H_

void MADC_vInit(void);
u16 MADC_u8GetDigitalValue(u8 A_u8Channel);

#endif /* COTS_MCAL_ADC_ADC_INTERFACE_H_ */
