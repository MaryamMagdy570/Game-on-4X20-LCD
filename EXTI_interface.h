#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_


void EXTI_voidInit(void);

void EXTI0_voidEnable(void);
void EXTI0_voidDisable(void);

void EXTI1_voidEnable(void);
void EXTI1_voidDisable(void);

void EXTI2_voidEnable(void);
void EXTI2_voidDisable(void);

void __vector_1(void) __attribute__((signal,used,externally_visible));  //to avoid optimization
void __vector_1(void);
void EXTI0_CallBack(void(*Ptr)(void));

void __vector_2(void) __attribute__((signal,used,externally_visible));  //to avoid optimization
void __vector_2(void);
void EXTI1_CallBack(void(*Ptr)(void));

void __vector_3(void) __attribute__((signal,used,externally_visible));  //to avoid optimization
void __vector_3(void);
void EXTI2_CallBack(void(*Ptr)(void));
#endif
