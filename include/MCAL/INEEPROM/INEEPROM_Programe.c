/*
 * INEEPROM_Programe.c
 *
 *  Created on: Jul 24, 2023
 *      Author: karim
 */

#include <util/delay.h>

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "INEEPROM_Interface.h"
#include "INEEPROM_Private.h"
#include "INEEPROM_Cfg.h"

void EEPROM_vWriteByteToAddress(const u16 u16Address, const u8 u8Data){
//
	EEARL=(u8)u16Address;
	EEARH=0b00000000;
	EEARH= EEARH |(u8)(u16Address>>8);

	EEDR=u8Data;

	CLR_BIT(EECR,3);
	SET_BIT(EECR,2);
	SET_BIT(EECR,1);
	_delay_ms(10);

	/* Wait for completion of previous write */

//	while(EECR & (1<<1))
//	;
//	EECR=0;
//
//	/* Set up address and data registers */
//	EEAR = u16Address;
//	EEDR = u8Data;
//	/* Write logical one to EEMWE */
//	EECR |= (1<<2);
//	/* Start eeprom write by setting EEWE */
//	EECR |= (1<<1);
//
//	_delay_ms(15);

}

u8 EEPROM_ui8ReadByteFromAddress(const u16 u16Address){

u8 local;

//
//	EEARL=(u8)u16Address;
//	EEARH=0b00000000;
//	EEARH= EEARH |(u8)(u16Address>>8);
//
//
//
//	CLR_BIT(EECR,3);
//	CLR_BIT(EECR,2);
//	SET_BIT(EECR,0);
//
//	return EEDR;
//	_delay_ms(10);

	/* Wait for completion of previous write */
//	while(EECR & (1<<1))
//	;
	/* Set up address register */
	EEAR = u16Address;
	/* Start eeprom read by writing EERE */
	EECR |= (1<<0);
	/* Return data from data register */
	local= EEDR;

	_delay_ms(15);
	return local;

}
