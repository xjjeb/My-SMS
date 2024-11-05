#include "ref.h"
#include "functions.h"

int main()
{
    page_init();
    int op_code = log_init();
    int * len_pt = (int *)malloc(sizeof(int));
    struct admin_info * admin_list = NULL;
    switch(op_code){
    case -1:
        printf("GoodBye!");
        return 0;
    case 0:
        ;
    case 1:
        admin_sign_up(&admin_list, len_pt);
    }
    return 0;
}