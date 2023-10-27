#include "STD_TYPES.h"
#include "BIT_MATH.h"
 
#include "DIO_interface.h"

#include "EXTI_register.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"


void EXTI_voidInit(void)
{
	//EXTI 0 SENSING  MODE
#if EXTI0_SENSING_MODE == LOW_LENEL
	CLR_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
#elif  EXTI0_SENSING_MODE == ANY_LOGIC
	SET_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
#elif  EXTI0_SENSING_MODE == FALLING_EDGE
	CLR_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
#elif EXTI0_SENSING_MODE == RISING_EDGE
	SET_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
#endif

	//EXTI 1 SENSING  MODE
#if EXTI1_SENSING_MODE == LOW_LENEL
	CLR_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);
#elif  EXTI1_SENSING_MODE == ANY_LOGIC
	SET_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);
#elif  EXTI1_SENSING_MODE == FALLING_EDGE
	CLR_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
#elif EXTI1_SENSING_MODE == RISING_EDGE
	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
#endif

	//EXTI 0 SENSING  MODE
#if EXTI2_SENSING_MODE == FALLING_EDGE
	CLR_BIT(MCUCSR,ISC2);
#elif  EXTI2_SENSING_MODE == RISING_EDGE
	SET_BIT(MCUCSR,ISC2);
#endif

}


void EXTI0_voidEnable(void)
{
	SET_BIT(GICR,EXTI0_EN);
}

void EXTI0_voidDisable(void)
{
	CLR_BIT(GICR,EXTI0_EN);
}

void EXTI1_voidEnable(void)
{
	SET_BIT(GICR,EXTI1_EN);
}

void EXTI1_voidDisable(void)
{
	CLR_BIT(GICR,EXTI1_EN);
}

void EXTI2_voidEnable(void)
{
	SET_BIT(GICR,EXTI2_EN);
}

void EXTI2_voidDisable(void)
{
	CLR_BIT(GICR,EXTI2_EN);
}




void (*EXTI0_Ptr)(void);

void EXTI0_CallBack(void(*Ptr)(void))
{
	EXTI0_Ptr = Ptr;
}

void __vector_1(void) __attribute__((signal,used,externally_visible));  //to avoid optimization
void __vector_1(void)
{
	if(EXTI0_Ptr!= NULL)
		EXTI0_Ptr();
}




void (*EXTI1_Ptr)(void);

void EXTI1_CallBack(void(*Ptr)(void))
{
	EXTI1_Ptr = Ptr;
}

void __vector_2(void) __attribute__((signal,used,externally_visible));  //to avoid optimization
void __vector_2(void)
{
	if(EXTI1_Ptr!= NULL)
		EXTI1_Ptr();
}



void (*EXTI2_Ptr)(void) = NULL;

void EXTI2_CallBack(void(*Ptr)(void))
{
	EXTI2_Ptr = Ptr;
}

void __vector_3(void) __attribute__((signal,used,externally_visible));  //to avoid optimization
void __vector_3(void)
{
	if(EXTI2_Ptr!= NULL)
		EXTI2_Ptr();
}


