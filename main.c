
#include <dlfcn.h>  // обязательно подключать для плагинов

#include "main.h"

#define MAX_NUMBER_DESCRIPTOR 255

struct descriptor_plugin descriptor_number[MAX_NUMBER_DESCRIPTOR];
void *handle[MAX_NUMBER_DESCRIPTOR];
//void (*plug_make_func[MAX_NUMBER_DESCRIPTOR])(void, void);
void (*plug_make_func[MAX_NUMBER_DESCRIPTOR])(void*, void*, void*);
void (*plug_printf_func[MAX_NUMBER_DESCRIPTOR])(void);

void print_invalid_operation(void*, void*, void*);
void init_plugin(void);

int main()
{
    int a,b,c, n;
    char *error;
    
    /*
    void *handle_temp;
    struct descriptor_plugin *descriptor_temp;

    handle_temp = dlopen("libfunc_add.so",  RTLD_LAZY);
    if (!handle_temp) {
       fprintf(stderr, "%s\n", dlerror());
        return 1;
    }
    dlerror();    // Clear any existing error 
    */
//    descriptor_temp = /*(int (*)(int))*/ dlsym(handle_temp, "descriptor_add");
    /*
    handle[descriptor_temp->number_operation] = handle_temp;
    
    plug_printf_func[descriptor_temp->number_operation] = dlsym(handle_temp, descriptor_temp->name_printf_func);
    plug_printf_func[descriptor_temp->number_operation]();
    
//    printf("%d \n", descriptor_temp->number_operation);
//    printf("%s \n", descriptor_temp->name_make_func);
//    printf("%s \n", descriptor_temp->name_printf_func);
    
    plug_make_func[descriptor_temp->number_operation] = dlsym(handle_temp, descriptor_temp->name_make_func);
    
    a = 5;
    b = 6;
    plug_make_func[descriptor_temp->number_operation](&c, &a, &b);
    
    printf("c = %d \n", c);
//    printf("%d", descriptor_temp->number_operation);
//    printf("%s", descriptor_temp->name_make_func);
//    printf("%s", descriptor_temp->name_printf_func);
    */
    
    
    for(unsigned int i = 0; i < MAX_NUMBER_DESCRIPTOR; ++i)
    {
        descriptor_number[i].number_operation = 0;
        plug_make_func[i] = print_invalid_operation;
    }
    init_plugin();
    /*
    plug_printf_func[1]();
    a = 5;
    b = 6;
    plug_make_func[1](&c, &a, &b);
    printf("c = %d \n", c);
    */
    printf("Enter two numbers:");
    scanf("%d %d",&a,&b);
    printf("Enter your choice:\n");
    
    for(unsigned int i = 0; i < MAX_NUMBER_DESCRIPTOR; ++i)
    {
        if(0 != descriptor_number[i].number_operation)
        {
            plug_printf_func[i]();
        }
    }
    
    
    scanf("%d",&n);
    plug_make_func[n](&c, &a, &b);
    /*
    switch(n)
    {
        case 1:
//            printf("The sum of %d and %d is %d \n",a,b,a+b);
            plug_make_func[1](&c, &a, &b);
        break;
        case 2:
//            printf("The Subtraction of %d and %d is %d \n",a,b,a-b);
            plug_make_func[2](&c, &a, &b);
        break;
        case 3:
            printf("The multiplication of %d and %d is %d \n",a,b,a*b);
        break;
        case 4:
            printf("The division of %d and %d is %d \n",a,b,a-b);
        break;
        case 5:
            printf("The Subtraction of %d and %d is %d \n",a,b,a-b);
        break;
        default:
            printf("Invalid operation \n");
    }
    */
    
    for(unsigned int i = 0; i < MAX_NUMBER_DESCRIPTOR; ++i)
    {
        if(0 != descriptor_number[i].number_operation)
        {
            dlclose(handle[i]);
        }
    }
    
    return 0;
}

void print_invalid_operation(void* aa, void* bb, void* cc)
{
    printf("Invalid operation \n");
}



void init_plugin(void)
{
    void *handle_temp;
    struct descriptor_plugin *descriptor_temp;

    handle_temp = dlopen("libfunc_sum.so",  RTLD_LAZY);
    if (!handle_temp) {
       fprintf(stderr, "%s\n", dlerror());
//        return 1;
    }
    dlerror();    // Clear any existing error 
    
    descriptor_temp = dlsym(handle_temp, "descriptor_lib");
    
    descriptor_number[descriptor_temp->number_operation] = (*descriptor_temp);
    
    handle[descriptor_temp->number_operation] = handle_temp;
    plug_printf_func[descriptor_temp->number_operation] = dlsym(handle_temp, descriptor_temp->name_printf_func);
    plug_make_func[descriptor_temp->number_operation] = dlsym(handle_temp, descriptor_temp->name_make_func);
    
//    a = 5;
//    b = 6;
//    plug_make_func[descriptor_temp->number_operation](&c, &a, &b);
    
//    printf("c = %d \n", c);
//    printf("%d \n", descriptor_temp->number_operation);
//    printf("%s \n", descriptor_temp->name_make_func);
//    printf("%s \n", descriptor_temp->name_printf_func);
    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    
    
    handle_temp = dlopen("libfunc_subtraction.so",  RTLD_LAZY);
    if (!handle_temp) {
       fprintf(stderr, "%s\n", dlerror());
    }
    dlerror();    // Clear any existing error 
    
    descriptor_temp = dlsym(handle_temp, "descriptor_lib");
    
    descriptor_number[descriptor_temp->number_operation] = (*descriptor_temp);
    
    handle[descriptor_temp->number_operation] = handle_temp;
    plug_printf_func[descriptor_temp->number_operation] = dlsym(handle_temp, descriptor_temp->name_printf_func);
    plug_make_func[descriptor_temp->number_operation] = dlsym(handle_temp, descriptor_temp->name_make_func);
    
    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    
    
    handle_temp = dlopen("libfunc_multiplication.so",  RTLD_LAZY);
    if (!handle_temp) {
       fprintf(stderr, "%s\n", dlerror());
    }
    dlerror();    // Clear any existing error 
    
    descriptor_temp = dlsym(handle_temp, "descriptor_lib");
    
    descriptor_number[descriptor_temp->number_operation] = (*descriptor_temp);
    
    handle[descriptor_temp->number_operation] = handle_temp;
    plug_printf_func[descriptor_temp->number_operation] = dlsym(handle_temp, descriptor_temp->name_printf_func);
    plug_make_func[descriptor_temp->number_operation] = dlsym(handle_temp, descriptor_temp->name_make_func);
    
    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    
    
    handle_temp = dlopen("libfunc_division.so",  RTLD_LAZY);
    if (!handle_temp) {
       fprintf(stderr, "%s\n", dlerror());
    }
    dlerror();    // Clear any existing error 
    
    descriptor_temp = dlsym(handle_temp, "descriptor_lib");
    
    descriptor_number[descriptor_temp->number_operation] = (*descriptor_temp);
    
    handle[descriptor_temp->number_operation] = handle_temp;
    plug_printf_func[descriptor_temp->number_operation] = dlsym(handle_temp, descriptor_temp->name_printf_func);
    plug_make_func[descriptor_temp->number_operation] = dlsym(handle_temp, descriptor_temp->name_make_func);
    
    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    
    
    
}



