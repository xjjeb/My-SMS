#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int code_valid(int code);
int log_init();
int admin_sign_up(struct admin_info ** ptr, int * len_of_admin);
int admin_log_in(struct admin_info * ptr);
void page_init();
void get_str(char * str, int len);

struct admin_info
{
    char name[41];
    char password[13];
};

struct student_info
{
    char name[40];
    char gender;
    char nationality[20];
    float gpa;
};