/*
 * APP.c
 *
 *  Created on: Jul 25, 2023
 *      Author: karim
 */


// Built in Library
#include <util/delay.h>

// Library Layer
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
// MCAL
#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/MCAL/EXTI/EXTI_Interface.h"
#include "../include/MCAL/GI/GI_Interface.h"
#include "../include/MCAL/TIMERS/TIMERS_Interface.h"
#include "../include/MCAL/UART/UART_Interface.h"
#include "../include/MCAL/UART/UART_Interface.h"
#include "../include/MCAL/TWI/TWI_Interface.h"
#include "../include/MCAL/ADC/ADC_Interface.h"
// HAL
#include "../include/HAL/KEYPAD/Keypad_Interface.h"
#include "../include/HAL/LCD/LCD_Interface.h"
#include "../include/HAL/EEPROM/EEPROM_Interface.h"

#define PASS_LOCATION 800
#define PASS_CODE   0xff


void admin_mode();


void admin_mode(){

		u8 presseKey;
		u8 statues;
		u8 flag=0;
		u8 flag2=0;
		u8 flag3=0;
		u8 flag4=0;
		u8 arr[4]={0};
		u8 counter=0;
		while(counter !=3){
			flag2=0;
			flag=0;
			HLCD_voidClearDisplay();
			HLCD_voidSendString((u8 *)"      WELCOME");
			HLCD_voidGoToPos(2,1);
			HLCD_voidSendString((u8 *)"LOGIN:");

			for(int i=0;i<4;i++){
						while(1){
								presseKey=getpressedkey();
								if(presseKey!=NOT_PRESSED){break;}
								}
			arr[i]=presseKey;
			_delay_ms(50);
			HLCD_voidGoToPos(2,7+i);
			HLCD_voidSendString((u8 *)"*");

					        	}

			if(arr[0]==EEPROM_u8ReadDataByte(0) &&arr[1]==EEPROM_u8ReadDataByte(10) &&arr[2]==EEPROM_u8ReadDataByte(20)
					&& arr[3]==EEPROM_u8ReadDataByte(30)){

				while(flag2==0){
						 HLCD_voidClearDisplay();
						 flag=0;
						 flag3=0;
						HLCD_voidSendString((u8 *)"1:Room1  2:Room2");
								HLCD_voidGoToPos(2,1);
							HLCD_voidSendString((u8 *)"3:More   4:Ret");

							while(1){
									presseKey=getpressedkey();
									if(presseKey!=NOT_PRESSED){break;}
									}
							switch(presseKey){
									case '1':while(flag==0){
										     HLCD_voidClearDisplay();
								             statues= MDIO_u8GetPinValue(DIO_PORTA,PIN0);
								             if(statues==1){
									         HLCD_voidSendString((u8 *)"THE LIGHT IS ON");
								             HLCD_voidGoToPos(2,1);
								             HLCD_voidSendString((u8 *)"0:OFF   1:RET");}
								             else{
								             HLCD_voidSendString((u8 *)"THE LIGHT IS OFF");
								             HLCD_voidGoToPos(2,1);
								             HLCD_voidSendString((u8 *)"0:ON   1:RET");
							         		         }
								             presseKey=NOT_PRESSED;
								             while(1){
								             				presseKey=getpressedkey();
								             				if(presseKey!=NOT_PRESSED){break;}
								             			    }
								             switch(presseKey){
								             case '0':MDIO_voidTogglePin(DIO_PORTA,PIN0);break;
								             case '1':flag=1;break;
								             }
									}
									break;


									case '2':while(flag==0){
									     HLCD_voidClearDisplay();
							             statues= MDIO_u8GetPinValue(DIO_PORTA,PIN1);
							             if(statues==1){
								         HLCD_voidSendString((u8 *)"THE LIGHT IS ON");
							             HLCD_voidGoToPos(2,1);
							             HLCD_voidSendString((u8 *)"0:OFF   1:RET");}
							             else{
							             HLCD_voidSendString((u8 *)"THE LIGHT IS OFF");
							             HLCD_voidGoToPos(2,1);
							             HLCD_voidSendString((u8 *)"0:ON   1:RET");
						        		         }
							             presseKey=NOT_PRESSED;
							             while(1){
							             				presseKey=getpressedkey();
							             				if(presseKey!=NOT_PRESSED){break;}
							             			    }
							             switch(presseKey){
							             case '0':MDIO_voidTogglePin(DIO_PORTA,PIN1);break;
							             case '1':flag=1;break;
							             }
								}
								break;
									case '3':while(flag3 ==0){
										flag4=0;
										HLCD_voidClearDisplay();
									   	HLCD_voidSendString((u8 *)"1:Room3 2:AIRCON");
										HLCD_voidGoToPos(2,1);
										HLCD_voidSendString((u8 *)"3:Pass Res.4:Ret");
										while(1){
										presseKey=getpressedkey();
									    if(presseKey!=NOT_PRESSED){break;}
												 }
										switch(presseKey){
										case '1':while(flag4==0){

								        HLCD_voidClearDisplay();
								   statues= MDIO_u8GetPinValue(DIO_PORTA,PIN2);
						           if(statues==1){
								 HLCD_voidSendString((u8 *)"THE LIGHT IS ON");
								 HLCD_voidGoToPos(2,1);
								 HLCD_voidSendString((u8 *)"0:OFF   1:RET");}
								 else{
								 HLCD_voidSendString((u8 *)"THE LIGHT IS OFF");
										 HLCD_voidGoToPos(2,1);
								 HLCD_voidSendString((u8 *)"0:ON   1:RET");
										 }
	                                   presseKey=NOT_PRESSED;
											 while(1){
															presseKey=getpressedkey();
															if(presseKey!=NOT_PRESSED){break;}
															}
											 switch(presseKey){
											 case '0':MDIO_voidTogglePin(DIO_PORTA,PIN2);break;
											 case '1':flag4=1;break;
											 }
									}
									break;
										case '2':while(flag4==0){
										u16	local_u16DigitalValue;
										u16	local_u16AnalogValue;
											 HLCD_voidClearDisplay();
											 statues= MDIO_u8GetPinValue(DIO_PORTA,PIN3);
											 if(statues==1){
											 HLCD_voidSendString((u8 *)"THE AIR IS ON");
											 HLCD_voidGoToPos(2,1);
											 HLCD_voidSendString((u8 *)"0:OFF   1:RET");}
											 else{
											 HLCD_voidSendString((u8 *)"THE AIR IS OFF");
											 HLCD_voidGoToPos(2,1);
											 HLCD_voidSendString((u8 *)"0:ON   1:RET");
													 }
											 presseKey=NOT_PRESSED;
											 while(1){
															presseKey=getpressedkey();
															if(presseKey!=NOT_PRESSED){break;}
															}
											 switch(presseKey){
											 case '0':
//												 MDIO_voidTogglePin(DIO_PORTA,PIN3);
												 local_u16DigitalValue = MADC_u16GetDigiitalValue(ADC4);
												 local_u16AnalogValue = (local_u16DigitalValue * 500UL)/1024;
												 if(local_u16AnalogValue <25 ){
													 MDIO_voidSetPinValue(DIO_PORTA,PIN3,DIO_LOW);
													 HLCD_voidClearDisplay();
													 HLCD_voidSendString((u8 *)"THE TEMP IS LOW");
													 HLCD_voidGoToPos(2,1);
													 HLCD_voidSendString((u8 *)"U CANT ON THE AIR");
													 _delay_ms(1500);

												 }
												 else if(statues==1){
													 MDIO_voidSetPinValue(DIO_PORTA,PIN3,DIO_LOW);
												 }
												 else{
													 MDIO_voidSetPinValue(DIO_PORTA,PIN3,DIO_HIGH);
												 }
												 break;
											    case '1':flag4=1;break;
											     }
										         }

										    case '3':

										    	while(flag4==0){
										    		u8 s=0;
										    		u8 arrl[4]={0};

												HLCD_voidClearDisplay();
												 HLCD_voidSendString((u8 *)"RESET PASSWORD?");
												 HLCD_voidGoToPos(2,1);
												 HLCD_voidSendString((u8 *)"0:OK   1:RET");

											   presseKey=NOT_PRESSED;
													 while(1){
													presseKey=getpressedkey();
													if(presseKey!=NOT_PRESSED){break;}
													}
													 switch(presseKey){
													 case '0':
														 HLCD_voidClearDisplay();
														 HLCD_voidSendString((u8 *)"SET PASS:");
														 	for(int i=0;i<4;i++){
														 	            while(1){
																		presseKey=getpressedkey();
																		if(presseKey!=NOT_PRESSED){break;}
																		}
														 	arrl[i]=presseKey;
														 	_delay_ms(20);
														 	HLCD_voidGoToPos(1,10+i);
														 	HLCD_voidSendString((u8 *)"*");

														 	}
														 	for(int j=0;j<4;j++){
														 		EEPROM_voidSendDataByte(s,arrl[j]);
														 		s+=10;
														 		_delay_ms(15);
														 	}
														 	HLCD_voidClearDisplay();
														 	HLCD_voidSendString((u8 *)"PASS RESET DONE!:");
														 	_delay_ms(1000);
														 	flag4=1;

														 break;
													 case '1':flag4=1;break;
													 }
											}



										    	break;
										    case '4':   flag3=1;    break;
										}
									}break;



									case '4':flag2=1;break;}

							}

					}
					else{
						 HLCD_voidClearDisplay();
						HLCD_voidSendString((u8 *)"    Wrong Pass");
						HLCD_voidGoToPos(2,1);
						HLCD_voidSendString((u8 *)"    Try Again");
						_delay_ms(1500);
						counter++;
						if(counter==3){
							 HLCD_voidClearDisplay();
							HLCD_voidSendString((u8 *)"System Blocked");

							_delay_ms(3000);

						}
					   }
		}


}

void setpassword(){

	u8 presseKey;
	u8 arr[4]={0};
	u8 c=0;
	HLCD_voidClearDisplay();
	HLCD_voidSendString((u8 *)"    WELCOME");
	HLCD_voidGoToPos(2,1);
	HLCD_voidSendString((u8 *)"SET UR PASS:");
	for(int i=0;i<4;i++){
	            while(1){
						presseKey=getpressedkey();
						if(presseKey!=NOT_PRESSED){break;}
					    }
	arr[i]=presseKey;
	_delay_ms(20);
	HLCD_voidGoToPos(2,13+i);
	HLCD_voidSendString((u8 *)"*");

	}
	for(int j=0;j<4;j++){
		EEPROM_voidSendDataByte(c,arr[j]);
		c+=10;
		_delay_ms(15);
	}
	EEPROM_voidSendDataByte(PASS_LOCATION,1);

}

int main(void){
	MDIO_voidInit();
	HLCD_voidInit();
	TWI_voidInitMaster(0);
	MADC_voidInit();
	u8 local_u8passlocation;
	local_u8passlocation=EEPROM_u8ReadDataByte(PASS_LOCATION);
	if(local_u8passlocation==PASS_CODE){
		setpassword();
	}





	while (1){

		admin_mode();
	}
}




