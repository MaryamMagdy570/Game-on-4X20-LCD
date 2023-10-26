#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "CLCD_private.h"
#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "DIO_interface.h"


void CLCD_voidClearDisplay()
{
	CLCD_voidSendCommand(CLCD_CMD_CLEAR_DISPLAY);
}

void CLCD_voidInit(void)
{

	_delay_ms(40);

	CLCD_voidSendCommand(CLCD_CMD_RETURN_HOME);

	/*Function Set Command
	 * 8 bit mode
	 * Activate the 2 lines
	 * Font Type is 5x8 (5x7) */
	CLCD_voidSendCommand(CLCD_CMD_FUNCTION_SET);

	/*Display ON/OFF Control Command
	 *set display: ON
	 *Cursor is Disabled
	 *Cursor Blinking is OFF  */
	CLCD_voidSendCommand(CLCD_CMD_DISPLAY_ON_OFF_CTRL);

	/*Clearing LCD Display*/
	CLCD_voidSendCommand(CLCD_CMD_CLEAR_DISPLAY);

	/*Entry mode Set*/
	CLCD_voidSendCommand(CLCD_CMD_ENTRY_MODE_SET);

}


void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/*SET RS PIN TO LOW*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);


	#if CLCD_MODE == 8

	/*READING THE COMMAD FROM DATA PORT*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);

	/*ENABLE PULSE*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	_delay_ms(2);

	#elif CLCD_MODE == 4

	/*READING THE COMMAD FROM DATA PORT*/
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D4,GET_BIT(Copy_u8Command,4));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D5,GET_BIT(Copy_u8Command,5));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D6,GET_BIT(Copy_u8Command,6));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D7,GET_BIT(Copy_u8Command,7));


	/*ENABLE PULSE*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	_delay_ms(2);
	/*READING THE COMMAD FROM DATA PORT*/
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D4,GET_BIT(Copy_u8Command,0));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D5,GET_BIT(Copy_u8Command,1));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D6,GET_BIT(Copy_u8Command,2));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D7,GET_BIT(Copy_u8Command,3));

	/*ENABLE PULSE*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	_delay_ms(2);
	#else
	#endif

}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	/*SET RS PIN TO HIGH*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);

	#if CLCD_MODE == 8
	/*READING THE COMMAD FROM DATA PORT*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);

	/*ENABLE PULSE*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	_delay_ms(2);

	#elif CLCD_MODE == 4
	/*READING THE COMMAD FROM DATA PORT*/
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D4,GET_BIT(Copy_u8Data,4));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D5,GET_BIT(Copy_u8Data,5));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D6,GET_BIT(Copy_u8Data,6));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D7,GET_BIT(Copy_u8Data,7));


	/*ENABLE PULSE*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	_delay_ms(2);
	/*READING THE COMMAD FROM DATA PORT*/
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D4,GET_BIT(Copy_u8Data,0));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D5,GET_BIT(Copy_u8Data,1));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D6,GET_BIT(Copy_u8Data,2));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_D7,GET_BIT(Copy_u8Data,3));

	/*ENABLE PULSE*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	_delay_ms(2);

	#else

	#endif

}


void CLCD_voidSendString(const char* Copy_PtrString)
{
	for (u8 i = 0; Copy_PtrString[i] !='\0'; i++)
	{
		CLCD_voidSendData(Copy_PtrString[i]);
	}
}



void CLCD_voidSendInteger(u16 Copy_Number)
{
	if (!Copy_Number)
		CLCD_voidSendData('0');
	//reversing number
	u16 Local_u16Number = Copy_Number;
	u8 Local_u8Array[5];
	u8 Local_i1, Local_i2;
	for (Local_i1=0; Local_u16Number!=0; Local_i1++)
	{
		Local_u8Array[Local_i1] = Local_u16Number % 10;
		Local_u16Number /=10;
	}
	for (Local_i2 = Local_i1; Local_i2!=0; Local_i2--)
	{
		CLCD_voidSendData(Local_u8Array[Local_i2-1]+'0');
	}

}

void CLCD_voidSendDecimalNumber(f32 Copy_Number)
{
	if (!Copy_Number)
		CLCD_voidSendData('0');
	//reversing number
	f32 Local_f32Number = Copy_Number;
	u8 Local_u8Array[10];
	u8 Local_i1, Local_i2;
	u8 Local_NumOfTens=0;

	while (Local_f32Number-(u32)Local_f32Number)
	{
		Local_f32Number*=10;
		Local_NumOfTens++;
	}

	//casting
	u32 Local_u32Number = Local_f32Number;

	for (Local_i1=0; Local_u32Number!=0; Local_i1++)
	{
		Local_u8Array[Local_i1] = Local_u32Number % 10;
		Local_u32Number /=10;
	}

	if (Local_i1 == Local_NumOfTens)
		CLCD_voidSendData('0');

	for (Local_i2 = Local_i1; Local_i2!=0; Local_i2--)
	{
		if (Local_i2 == Local_NumOfTens)
			CLCD_voidSendData('.');
		CLCD_voidSendData(Local_u8Array[Local_i2-1]+'0');
	}

	if (Local_NumOfTens == 0)
	{
		CLCD_voidSendData('.');
		CLCD_voidSendData('0');
	}
}


void CLCD_voidGoToRowColumn(u8 Copy_u8xPosition, u8 Copy_u8yPosition)
{
	u8 Local_u8Adress;
	switch(Copy_u8xPosition)
	{
		case 0:  Local_u8Adress = Copy_u8yPosition;  		break;
		case 1:  Local_u8Adress = Copy_u8yPosition + 0x40;  break;
		case 2:  Local_u8Adress = Copy_u8yPosition + 0x14;  break;
		case 3:  Local_u8Adress = Copy_u8yPosition + 0x54;	break;
		default: break;
	}

	/* setting the last bit ,As the command is (1 bit[7] , Address counter bits[6:0])*/
	SET_BIT(Local_u8Adress,7);

	CLCD_voidSendCommand(Local_u8Adress);
}



void CLCD_voidSendSpecialCharacter(const u8* Copy_u8Arr, u8 Copy_u8PatternNumber)
{
	u8 Local_u8CGRAMAddress = 0;
	Local_u8CGRAMAddress = Copy_u8PatternNumber*8;
	SET_BIT(Local_u8CGRAMAddress,6);

	/*moving to CGRAM to write the special character inside it*/
	CLCD_voidSendCommand(Local_u8CGRAMAddress);

	/* writing the special character*/
	for (u8 i = 0; i<8; i++)
	{
		CLCD_voidSendData(Copy_u8Arr[i]);
	}

	/* switching again to DDRAM */
	CLCD_voidGoToRowColumn (0,0);  // 0,0 can be changed
}

void CLCD_voidDisplaySpecialCharacter(u8 Copy_u8PatternNumber,u8 Copy_u8XPosition,u8 Copy_u8YPosition)
{
	CLCD_voidGoToRowColumn (Copy_u8XPosition,Copy_u8YPosition);
	CLCD_voidSendData(Copy_u8PatternNumber);
}
