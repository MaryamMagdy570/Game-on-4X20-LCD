#ifndef _CLCD_INTERFACE_H_
#define _CLCD_INTERFACE_H_


#define CLCD_CMD_CLEAR_DISPLAY			0b00000001
#define	CLCD_CMD_RETURN_HOME			0b00000010
#define CLCD_CMD_ENTRY_MODE_SET			CONC(0,0,0,0,0,1,CMD_ID_BIT,CMD_SH_BIT)
#define CLCD_CMD_DISPLAY_ON_OFF_CTRL	CONC(0,0,0,0,1,CMD_D_BIT,CMD_C_BIT,CMD_B_BIT)
#define CLCD_CMD_SHIFT_DISPLAY_RIGHT	0b00011100
#define CLCD_CMD_SHIFT_DISPLAY_LEFT		0b00011000
#define CLCD_CMD_SHIFT_CURSOR_RIGHT		0b00010100
#define CLCD_CMD_SHIFT_CURSOR_LEFT		0b00010000
#define CLCD_CMD_FUNCTION_SET			CONC(0,0,1,CMD_DL_BIT,CMD_N_BIT,CMD_F_BIT,0,0)



void CLCD_voidClearDisplay();

void CLCD_voidInit(void);

void CLCD_voidSendCommand(u8 Copy_u8Command);

void CLCD_voidSendData(u8 Copy_u8Data);

void CLCD_voidSendString(const char* Copy_PtrString);

void CLCD_voidSendInteger(u16 Copy_Number);

void CLCD_voidSendDecimalNumber(f32 Copy_Number);

/*rows 0:3 , columns 0:19*/
void CLCD_voidGoToRowColumn(u8 Copy_u8xPosition, u8 Copy_u8yPosition);

void CLCD_voidSendSpecialCharacter(const u8* Copy_u8Arr, u8 Copy_u8PatternNumber);

void CLCD_voidDisplaySpecialCharacter(u8 Copy_u8PatternNumber,u8 Copy_u8XPosition,u8 Copy_u8YPosition);



#endif
