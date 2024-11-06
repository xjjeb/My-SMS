int log_init()
{
    int operation_code;
    int cnt = 0;
    printf("Please input 0 if you are logging in\n");
    printf("Please input 1 if you are signing up\n");
    printf("Please input -1 if you are quitting the system:\n");
    scanf("%d", &operation_code);
    if (!code_valid(operation_code)){
        while (!code_valid(operation_code)){
            printf("Your Input is Invalid! Please Input Again:");
            scanf("%d", &operation_code);
            if (cnt > 10){
                printf("You are so STUPID. Bye Bye!!!");
                operation_code = -1;
                break;
            }
            if (code_valid(operation_code)){
                break;
            }
            cnt ++;
        }
    }
    getchar();
    return operation_code;
}

int code_valid(int code)
{
    if (code == 0 || code == -1 || code == 1){
        return 1;
    }
    else{
        return 0;
    }
}

int admin_sign_up(struct admin_info ** admin_list, int* len_of_admin)
{
    char name[41];
    char password[13];
    char conf_password[13];
    int flag = 1;
    while (flag){
        printf("Please input your user name(less than 40 words):");
        get_str(name, 41);
        printf("Please input your password(less than 12 words):");
        get_str(password, 41);
        printf("Please confirm your password:");
        get_str(conf_password, 41);
        if (!strcmp(password, conf_password)){
            flag = 0;
            printf("Please Confirm:\n");
            printf("Your Username is %s\n", name);
            printf("Your Password: %s", password);
        }
        else{
            printf("the password you input are not equal! Please sign up again.");
        }
    }
    if (*admin_list == NULL){
        *admin_list = (struct admin_info *)malloc(sizeof(struct admin_info));
        *len_of_admin = 1;
    }
    else{
        *admin_list = (struct admin_info *)realloc(*admin_list, *len_of_admin + 1);
        *len_of_admin ++;
    }
    strcpy((*admin_list + *len_of_admin - 1)->name, name);
    strcpy((*admin_list + *len_of_admin - 1)->password, password);//password is actually a pointer, it cannot be put into a data unit storing strings.
    printf("Sign Up Succeeded!");
    return 0;
}

int admin_log_in(struct admin_info * ptr)
{
    
}

void get_str(char * str, int len)
{
    char tmp;
    for (int i = 0; i < len; i ++){
        scanf("%c", &tmp);
        if (tmp == '\n' || tmp == '\0'){
            str[i] = '\0';
            break;
        }
        else{
            str[i] = tmp;
        }
    }
}

void page_init()
{
    printf("-----------------------------\n");
    printf("Welcome to the Student Management System\n");
}