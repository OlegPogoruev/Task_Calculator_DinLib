
#include <stdio.h>

#define MAX_LEN_NAME 32

struct descriptor_plugin{
    int number_operation;
    char name_make_func[MAX_LEN_NAME];
    char name_printf_func[MAX_LEN_NAME];
};

void func_division(float* rezult, int* param_1, int* param_2);
void func_division_printf(void);


