#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H
#include "employee.h"
#include <stdbool.h>

bool save_employees_to_file(const char *filename, EmployeeList *list);
bool load_employees_from_file(const char *filename, EmployeeList *list);

#endif