/*
 * main.c
 *
 *  Created on: Oct 27, 2023
 *      Author: maryam Magdy
 */


#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"


#define SHIFT() do{ char temp1 = ObstcaleArray1[0];					\
					char temp2 = ObstcaleArray2[0];					\
				    for(u8 i =0; i <19 ; i++){						\
					    ObstcaleArray1[i] = ObstcaleArray1[i+1];  	\
					    ObstcaleArray2[i] = ObstcaleArray2[i+1];} 	\
					ObstcaleArray1[19] = temp1;			\
					ObstcaleArray2[19] = temp2;			\
					ObstcaleArray1[20] ='\0';						\
					ObstcaleArray2[20] ='\0';						\
				  }while(0)

//#define ARR1 "|   |    |   | ||| |"
//#define ARR2 "  |   ||   |        "

u8 CarRowPosition = 1;
u8 CarColPosition = 6;
u8 UpSwitch,DownSwitch;

char ObstcaleArray1[]= "|   |    |   ||     ";
char ObstcaleArray2[]= "  |   ||   |     || ";



void EXTI0_ISR(); //UP
void EXTI1_ISR(); //DOWN

void main (void)
{
	DIO_voidInit();
	CLCD_voidInit();

	GIE_voidEable();
	EXTI0_voidEnable();
	EXTI1_voidEnable();

	EXTI0_CallBack(EXTI0_ISR);
	EXTI1_CallBack(EXTI1_ISR);

	u8 Car[8]     ={0b00000000,0b00000000,0b00010100,0b00011110,0b00010100,0b00000000,0b00000000};
	u8 Obstacle[8]={0b00000000,0b00000000,0b00001110,0b00001110,0b00001110,0b00000000,0b00000000};
	u8 NoObstacle[8]={0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000};
	u8 Wall[8]= {0b00000000,0b00000000,0b00011111,0b00011111,0b00011111,0b00000000,0b00000000};
	u8 Dead[8]    ={0b00011111,0b00011111,0b00011111,0b00011111,0b00011111,0b00011111,0b00011111};

	CLCD_voidSendSpecialCharacter(Car,0);
	CLCD_voidSendSpecialCharacter(Obstacle,1);
	CLCD_voidSendSpecialCharacter(NoObstacle,2);
	CLCD_voidSendSpecialCharacter(Wall,3);
	CLCD_voidSendSpecialCharacter(Dead,4);


	CLCD_voidDisplaySpecialCharacter(0,CarRowPosition,CarColPosition);

	//THE WALL
	for(u8 i =0; i<20; i++)
	{
		CLCD_voidDisplaySpecialCharacter(3,0,i);
		CLCD_voidDisplaySpecialCharacter(3,3,i);
	}

	CLCD_voidDisplaySpecialCharacter(0,CarRowPosition,CarColPosition);

	while (1) //gameover condition
	{
/*
		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN6,DIO_u8PIN_LOW);

		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN7,&UpSwitch);
		if (!UpSwitch)
		{

		}
		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN7,&DownSwitch);
		if (!DownSwitch)
		{

		}
*/
		CLCD_voidGoToRowColumn(1,0);
		CLCD_voidSendString("                   ");
		CLCD_voidGoToRowColumn(2,0);
		CLCD_voidSendString("                   ");
		CLCD_voidDisplaySpecialCharacter(0,CarRowPosition,CarColPosition);
		CLCD_voidGoToRowColumn(1,0);
		CLCD_voidSendString(ObstcaleArray1);
		CLCD_voidGoToRowColumn(2,0);
		CLCD_voidSendString(ObstcaleArray2);
		CLCD_voidDisplaySpecialCharacter(0,CarRowPosition,CarColPosition);
		_delay_ms(700);



		GIE_voidDisable();
		if((CarRowPosition==1 && ObstcaleArray1[6]=='|')||(CarRowPosition==2 && ObstcaleArray2[6]=='|'))
		{
			CLCD_voidDisplaySpecialCharacter(3,CarRowPosition,CarColPosition);
			CLCD_voidGoToRowColumn(3,5);
			CLCD_voidSendString("Game Over");
			_delay_ms(1000);
			while(1);
		}

		SHIFT();

		GIE_voidEable();
	}

}

void EXTI0_ISR()
{
	if (ObstcaleArray2[CarColPosition] != '|')
	{
		CLCD_voidGoToRowColumn(CarRowPosition,CarColPosition);
		CLCD_voidSendData(' ');
	}
	CarRowPosition = 1;
	CLCD_voidDisplaySpecialCharacter(0,CarRowPosition,CarColPosition);
}

void EXTI1_ISR()
{
	if (ObstcaleArray1[CarColPosition] != '|')
	{
		CLCD_voidGoToRowColumn(CarRowPosition,CarColPosition);
		CLCD_voidSendData(' ');
	}
	CarRowPosition = 2;
	CLCD_voidDisplaySpecialCharacter(0,CarRowPosition,CarColPosition);
}

