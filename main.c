#include "ref.h"
#include "functions.h"

int main()
{
    page_init();
    int op_code = log_init();
    int * admin_len_pt = (int *)malloc(sizeof(int));//len_pt is a pointing to the length of admin_list
    struct admin_info * admin_list = NULL;
    if (op_code == -1){
        printf("Good Bye!");
        return 0;
    }
    else{
        while (op_code != -1){
            if (op_code == 1){
                admin_sign_up(&admin_list, admin_len_pt);
                op_code = log_init();
            }
            else{
                op_code = admin_log_in(admin_list);
                while (op_code == -1){
                    op_code = admin_log_in(admin_list);
                }
            }
        }
        printf("Good Bye!");
        return 0;
    }
}