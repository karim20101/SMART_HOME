/*
 * ADC_program.c
 *
 *  Created on: Dec 23, 2022
 *      Author: abdelrahmanhossam
 */




#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "ADC_Cfg.h"


void MADC_voidInit(void)
{
	/********************************/
	/* 1- Select Vref = AVCC		*/
	/* 2- Right Adjustment			*/
	/* 3- Disable Auto Trigger		*/
	/* 4- Select prescaler CLK/64	*/
	/* 5- Enable ADC				*/
	/********************************/

	// 1- Select Vref = AVCC
	CLR_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);

	// 2- Right Adjustment
	CLR_BIT(ADMUX,ADMUX_ADLAR);

	// 3- Disable Auto Trigger
	CLR_BIT(ADCSRA,ADCSRA_ADATE);

	// 4- Select prescaler CLK/64
	CLR_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);

	// 5- Enable ADC
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}


u16 MADC_u16GetDigiitalValue (const u8 A_u8Channel)
{
	u16 local_u16DigitalValue = 0;

	/********************************/
	/* 1- I/P validation			*/
	/* 2- select Channel			*/
	/* 3- start conversion  		*/
	/* 4- Polling on complete flag	*/
	/* 5- Clear INT Flag        	*/
	/* 6- Read Conversion Value     */
	/* 7- Return Conversion Value   */
	/********************************/

	// 1- I/P validation
	if (A_u8Channel<32)
	{
		// 2- select Channel

		// clear the channel 5 bits
		ADMUX &= ADC_CHANNEL_MASK;
		// select channel
		ADMUX |= A_u8Channel;

		// 3- start conversion
		SET_BIT(ADCSRA,ADCSRA_ADSC);

		// 4- Polling on complete flag
		while (GET_BIT(ADCSRA,ADCSRA_ADIF)==0);

		// 5- Clear INT Flag
		SET_BIT(ADCSRA,ADCSRA_ADIF);

		// 6- Read Conversion Value
		local_u16DigitalValue = ADCLH;
	}

	// 7- Return Conversion Value
	return local_u16DigitalValue;

}
