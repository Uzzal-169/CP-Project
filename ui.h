#ifndef UI_H
#define UI_H
#include "employee.h"

void show_main_menu(void);
int get_menu_choice(void);
Employee get_employee_input(void);
int get_int_input(const char *prompt);
char *get_string_input(const char *prompt, char *buffer, size_t bufsize);

#endif