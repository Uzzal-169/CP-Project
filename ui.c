#include "ui.h"
#include <stdio.h>
#include <string.h>

void show_main_menu(void) {
    printf("\n=== Employee Management System ===\n");
    printf("1. Add Employee\n");
    printf("3. Search Employee by ID\n");
    printf("4. Search Employee by Name\n");
    printf("5. Update Employee\n");
    printf("6. Delete Employee\n");
    printf("7. Save to file\n");
    printf("8. Load from file\n");
    printf("0. Exit\n");
}

int get_menu_choice(void) {
    int c;
    printf("Enter choice: ");
    scanf("%d", &c);
    getchar();
    return c;
}

Employee get_employee_input(void) {
    Employee e;
    printf("Enter ID: "); scanf("%d", &e.id); getchar();

    printf("Enter Name: "); fgets(e.name, NAME_LEN, stdin);
    e.name[strcspn(e.name, "\n")] = 0;

    printf("Enter Age: "); scanf("%d", &e.age); getchar();

    printf("Enter Position: "); fgets(e.position, NAME_LEN, stdin);
    e.position[strcspn(e.position, "\n")] = 0;

    printf("Enter Salary: "); scanf("%lf", &e.salary); getchar();

    return e;
}

int get_int_input(const char *prompt) {
    int n;
    printf("%s", prompt);
    scanf("%d", &n);
    getchar();
    return n;
}

char *get_string_input(const char *prompt, char *buffer, size_t bufsize) {
    printf("%s", prompt);
    fgets(buffer, bufsize, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    return buffer;
}