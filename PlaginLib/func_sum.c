/*
#include <stdio.h>

#define MAX_LEN_NAME 32

struct descriptor_plugin{
    int number_operation;
    char name_make_func[MAX_LEN_NAME];
    char name_printf_func[MAX_LEN_NAME];
};
*/

#include "func_sum.h"


struct descriptor_plugin descriptor_lib =
{
    1,
    {"func_add"},
    {"func_add_printf"}
};

void func_add(int* rezult, int* param_1, int* param_2)
{
//    int ret = 0;
    (*rezult) = (*param_1) + (*param_2);
    printf("The sum of %d and %d is %d \n",(*param_1),(*param_2),(*rezult));
//    return ret;
}

void func_add_printf(void)
{
    printf(" %d.Addition\n", descriptor_lib.number_operation);
}
