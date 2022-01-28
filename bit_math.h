#ifndef BIT_MATH_H
#define BIT_MATH_H


#define SET_BIT(register,bit_no) 	(register|=(1<<bit_no) )
#define CLEAR_BIT(register,bit_no) 	(register&=~(1<<bit_no) )
#define TOGGLE_BIT(register,bit_no) 	(register^=(1<<bit_no) )

/*this is the best way to make the function as macro to make the return true or 
false, it's not changing the value of the register and doesn't resturn the binary 
value of the register in contrast to (register&(1<<bit_no)) or (register&=(1<<bit_no))
*/
#define GET_BIT(register,bit_no)	((register&(1<<bit_no))!=0)

#endif