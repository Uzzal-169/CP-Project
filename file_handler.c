#include "employee.h"
#include "file_handler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool save_employees_to_file(const char *filename, EmployeeList *list) {
    FILE *f = fopen(filename, "w");
    if (!f) return false;

    for (size_t i = 0; i < list->size; i++) {
        Employee *e = &list->data[i];
        fprintf(f, "%d,%s,%d,%s,%.2f\n", e->id, e->name, e->age, e->position, e->salary);
    }

    fclose(f);
    return true;
}

bool load_employees_from_file(const char *filename, EmployeeList *list) {
    FILE *f = fopen(filename, "r");
    if (!f) return false;

    char line[256];
    while (fgets(line, sizeof(line), f)) {
        Employee e;
        char name[NAME_LEN];
        char pos[NAME_LEN];

        if (sscanf(line, "%d,%99[^,],%d,%99[^,],%lf",
                   &e.id, name, &e.age, pos, &e.salary) == 5) {
            strcpy(e.name, name);
            strcpy(e.position, pos);
            add_employee(list, e);
        }
    }

    fclose(f);
    return true;
}