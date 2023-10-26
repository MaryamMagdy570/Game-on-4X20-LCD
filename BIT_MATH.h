#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_



#define  SET_BIT(res,index) res=res|(1<<index)
#define  TOGGLE_BIT(res,index) res=res^(1<<index)
#define  CLR_BIT(res,index) res=res&(~(1<<index))
#define  GET_BIT(res,index) ((res>>index)&1)



#define CONC_HELPER(X7,X6,X5,X4,X3,X2,X1,X0) 0b##X7##X6##X5##X4##X3##X2##X1##X0
#define CONC(X7,X6,X5,X4,X3,X2,X1,X0) CONC_HELPER(X7,X6,X5,X4,X3,X2,X1,X0)




#endif 
