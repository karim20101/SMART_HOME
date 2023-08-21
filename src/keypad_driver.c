/*
* keypad_driver.c
*
* Created: 2/24/2018 4:06:22 PM
*  Author: Mohamed Zaghlol
*/


#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include <util/delay.h>
#include "../include/MCAL/DIO/DIO_Interface.h"

#include "..\include\HAL\KEYPAD\keypad_Interface.h"
#include "..\include\HAL\KEYPAD\KEYPAD_Cfg.h"


#define NOT_PRESSED 0xff

u8 getpressedkey(void)
{
	u8 arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}}; //keypad buttons
	u8 row; //which indicate the given output  pin
	u8 coloumn; //which indicate the given input pin
	u8 key_pressed_indicator; //the variable  which contain the key pressed
	
	u8 returnval=NOT_PRESSED; //the variable contain the value which will be returned which will be key pressed or not pressed in case of no key pressed
	for(row=0;row<4;row++)
	{
		/*stop the work of keypad firstly*/
		MDIO_voidSetPinValue(KEYPAD_PORT,PIN0,DIO_HIGH);
		MDIO_voidSetPinValue(KEYPAD_PORT,PIN1,DIO_HIGH);
		MDIO_voidSetPinValue(KEYPAD_PORT,PIN2,DIO_HIGH);
		MDIO_voidSetPinValue(KEYPAD_PORT,PIN3,DIO_HIGH);
		/*************************************/
		_delay_ms(20); 
		MDIO_voidSetPinValue(KEYPAD_PORT,row,DIO_LOW);//write 0 to the first pin in keypad (output pin from MC)
		
		for(coloumn=0;coloumn<4;coloumn++)
		{
			key_pressed_indicator=MDIO_u8GetPinValue(KEYPAD_PORT,(coloumn+4)); // read the input pins of MC which connected to keypad
			if(key_pressed_indicator==0)// will be 0 only if any key pressed
			{
				_delay_ms(200);
				returnval=arr[row][coloumn]; //put the selected pressed key to the retrurnval
				break; // break from the loop
			}
		}
	}
	return returnval ; //return the pressed key in case of key pressed or return 0xff in case of no key pressed
}
