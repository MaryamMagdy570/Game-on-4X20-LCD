/*file instead of these line    >>   #include <avr/io.h>
all of these addreses like : *((u8*)0X3A) we get it from datasheet section"register summry" */

#ifndef _DIO_REGISTER_H_
#define _DIO_REGISTER_H_

#define DDRA_REG  	*((volatile u8*)0x3A)
#define DDRB_REG  	*((volatile u8*)0x37)
#define DDRC_REG  	*((volatile u8*)0x34)
#define DDRD_REG  	*((volatile u8*)0x31)

#define PINA_REG   	*((volatile u8*)0x39)
#define PINB_REG   	*((volatile u8*)0x36)
#define PINC_REG   	*((volatile u8*)0x33)
#define PIND_REG   	*((volatile u8*)0x30)

#define PORTA_REG  	*((volatile u8*)0x3B)
#define PORTB_REG  	*((volatile u8*)0x38)
#define PORTC_REG  	*((volatile u8*)0x35)
#define PORTD_REG  	*((volatile u8*)0x32)


#endif
