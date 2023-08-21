/*
 * INEEPROM_Private.h
 *
 *  Created on: Jul 24, 2023
 *      Author: karim
 */

#ifndef INCLUDES_INEEPROM_PRIVATE_H_
#define INCLUDES_INEEPROM_PRIVATE_H_

#define EEARL	(*((volatile u8 *)0x3E))
#define EEARH	(*((volatile u8 *)0x3F))
#define EEAR    (*((volatile u16 *)0x3E))
#define EEDR	(*((volatile u8 *)0x3D))
#define EECR	(*((volatile u8 *)0x3C))
#define SPMCR	(*((volatile u8 *)0x57))
#endif /* INCLUDES_INEEPROM_PRIVATE_H_ */
