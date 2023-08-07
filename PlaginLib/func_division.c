
#include "func_division.h"


struct descriptor_plugin descriptor_lib =
{
    4,
    {"func_division"},
    {"func_division_printf"}
};

void func_division(float* rezult, int* param_1, int* param_2)
{
    float rez = (*param_1);
    
    rez = rez/(*param_2);
    printf("The division of %d and %d is %f \n",(*param_1),(*param_2),rez);
}

void func_division_printf(void)
{
    printf(" %d.Division\n", descriptor_lib.number_operation);
}
