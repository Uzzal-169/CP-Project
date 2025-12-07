#include "employee.h"
#include <stdlib.h>
#include <string.h>

static void ensure_capacity(EmployeeList *list) {
    if (list->size >= list->capacity) {
        size_t newcap = list->capacity == 0 ? 8 : list->capacity * 2;
        Employee *tmp = realloc(list->data, newcap * sizeof(Employee));
        if (!tmp) return;
        list->data = tmp;
        list->capacity = newcap;
    }
}

void init_employee_list(EmployeeList *list) {
    list->data = NULL;
    list->size = 0;
    list->capacity = 0;
}

void free_employee_list(EmployeeList *list) {
    free(list->data);
    list->data = NULL;
    list->size = list->capacity = 0;
}

Employee *add_employee(EmployeeList *list, Employee emp) {
    ensure_capacity(list);
    if (list->size >= list->capacity) return NULL;
    list->data[list->size++] = emp;
    return &list->data[list->size - 1];
}

Employee *find_employee_by_id(EmployeeList *list, int id) {
    for (size_t i = 0; i < list->size; ++i)
        if (list->data[i].id == id) return &list->data[i];
    return NULL;
}

Employee *find_employee_by_name(EmployeeList *list, const char *name) {
    for (size_t i = 0; i < list->size; ++i)
        if (strcmp(list->data[i].name, name) == 0) return &list->data[i];
    return NULL;
}

bool update_employee(EmployeeList *list, int id, Employee updated) {
    Employee *e = find_employee_by_id(list, id);
    if (!e) return false;
    *e = updated;
    return true;
}

bool delete_employee(EmployeeList *list, int id) {
    for (size_t i = 0; i < list->size; ++i) {
        if (list->data[i].id == id) {
            for (size_t j = i; j + 1 < list->size; ++j)
                list->data[j] = list->data[j + 1];
            list->size--;
            return true;
        }
    }
    return false;
}