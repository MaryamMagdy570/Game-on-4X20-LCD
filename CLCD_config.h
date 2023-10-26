#ifndef _CLCD_CONFIG_H_
#define _CLCD_CONFIG_H_



#define CLCD_DATA_PORT		DIO_u8PORTB

#define CLCD_D4				DIO_u8PIN0
#define CLCD_D5				DIO_u8PIN1
#define CLCD_D6				DIO_u8PIN2
#define CLCD_D7				DIO_u8PIN4

#define CLCD_CTRL_PORT		DIO_u8PORTA

#define CLCD_RS_PIN			DIO_u8PIN3
#define CLCD_E_PIN			DIO_u8PIN2

#define CLCD_MODE 			4
/* 4 for 4bit mode , 8 for 8 bit mode */



/********************************************************/
/******************** COMMANDS **************************/
/********************************************************/

#define CMD_ID_BIT			1
/* moving direction of cursor and display
 * i -> increase(ID =1) , d-> decrease(ID =0)
 */

#define CMD_SH_BIT			0
/* shift the entire display
 * enable shift (SH =1) , disable shift (SH =0)
 */

#define CMD_D_BIT			1
/* entire display is ON (D=1), OFF (D=0)
 * the display data remains in the DDRAM even ON or OFF
 */

#define CMD_C_BIT			0
/* cursor display ON (C=1), OFF(C=0)
 */
#define CMD_B_BIT			0
/* cursor blinking Enabled (B =1), Disabled (B=0)
 */


//cursor or display shift
//#define CLCD_SC_BIT
//#define CLCD_RL_BIT


#define CMD_DL_BIT		0
/* interface data length
 * 8 BIT MODE (DL =1)
 * 4 BIT MODE (DL =0)
 */

#define CMD_N_BIT		1
/* NUMBER OF LINES
 * ONE LINE (N=0)
 * TWO LINES (N=1)
 */

#define CMD_F_BIT		0
/* SET CHARACTER FONT
 * (5X8)5X7 DOTS  (F=0)
 * (5X11)5X10 DOTS  (F=1)
 */



#endif
