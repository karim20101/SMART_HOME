/*
 * INEEPROM_Interface.h
 *
 *  Created on: Jul 24, 2023
 *      Author: karim
 */

#ifndef INCLUDES_INEEPROM_INTERFACE_H_
#define INCLUDES_INEEPROM_INTERFACE_H_

void EEPROM_vWriteByteToAddress(const u16 u16Address, const u8 u8Data);
u8 EEPROM_ui8ReadByteFromAddress(const u16 u16Address);
#endif /* INCLUDES_INEEPROM_INTERFACE_H_ */
