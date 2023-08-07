
#include "func_multiplication.h"


struct descriptor_plugin descriptor_lib =
{
    3,
    {"func_multiplication"},
    {"func_multiplication_printf"}
};

void func_multiplication(long* rezult, int* param_1, int* param_2)
{
    (*rezult) = (*param_1)*(*param_2);
    printf("The multiplication of %d and %d is %ld \n",(*param_1),(*param_2),(*rezult));
}

void func_multiplication_printf(void)
{
    printf(" %d.Multiplication\n", descriptor_lib.number_operation);
}
