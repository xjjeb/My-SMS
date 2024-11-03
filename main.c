#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int log_init();
void page_init();
int code_valid(int code);

struct admin_info
{
    char name[40];
    char password[12];
};

struct student_info
{
    char name[40];
    char gender;
    char nationality[20];
    float gpa;
};

int main()
{
    printf("%d", log_init());
    return 0;
}

int log_init()
{
    int operation_code;
    int cnt = 0;
    printf("-----------------------------\n");
    printf("Welcome to the Student Management System\n");
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

void page_init()
{
    ;
}