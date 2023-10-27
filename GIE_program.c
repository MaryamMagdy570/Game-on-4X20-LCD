
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_register.h"
#include "GIE_config.h"
#include "GIE_private.h"
#include "GIE_interface.h"



void GIE_voidEable(void)
{
  SET_BIT (SREG,7);
}

void GIE_voidDisable(void)
{
  CLR_BIT (SREG,7);
}

