#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <stdbool.h>
#include <stddef.h>
#define NAME_LEN 100

typedef struct {
    int id;
    char name[NAME_LEN];
    int age;
    char position[NAME_LEN];
    double salary;
} Employee;

typedef struct {
    Employee *data;
    size_t size;
    size_t capacity;
} EmployeeList;

void init_employee_list(EmployeeList *list);
void free_employee_list(EmployeeList *list);
Employee *add_employee(EmployeeList *list, Employee emp);
Employee *find_employee_by_id(EmployeeList *list, int id);
Employee *find_employee_by_name(EmployeeList *list, const char *name);
bool update_employee(EmployeeList *list, int id, Employee updated);
bool delete_employee(EmployeeList *list, int id);

#endif