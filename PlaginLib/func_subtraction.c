
#include "func_subtraction.h"


struct descriptor_plugin descriptor_lib =
{
    2,
    {"func_subtraction"},
    {"func_subtraction_printf"}
};

void func_subtraction(int* rezult, int* param_1, int* param_2)
{
    (*rezult) = (*param_1) - (*param_2);
    printf("The Subtraction of %d and %d is %d \n",(*param_1),(*param_2),(*rezult));
}

void func_subtraction_printf(void)
{
    printf(" %d.Subtraction\n", descriptor_lib.number_operation);
}
