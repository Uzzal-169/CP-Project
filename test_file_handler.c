#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "employee.h"
#include "file_handler.h"

int main() {
    EmployeeList list;

    /* initialize employee list */
    init_employee_list(&list);

    /* create some test employees */
    Employee e1 = {1, "Alice", 25, "Software Engineer", 50000.0};
    Employee e2 = {2, "Bob", 30, "Project Manager", 65000.0};
    Employee e3 = {3, "Charlie", 28, "QA Engineer", 45000.0};

    add_employee(&list, e1);
    add_employee(&list, e2);
    add_employee(&list, e3);

    /* save to file */
    if (save_employees_to_file("employees_test.csv", &list)) {
        printf("Employees saved successfully.\n");
    } else {
        printf("Failed to save employees.\n");
    }

    /* clear list */
    free_employee_list(&list);

    /* load from file */
    init_employee_list(&list);
    if (load_employees_from_file("employees_test.csv", &list)) {
        printf("Employees loaded successfully.\n");
    } else {
        printf("Failed to load employees.\n");
        return 1;
    }

    /* print loaded employees */
    printf("\nLoaded Employees:\n");
    for (size_t i = 0; i < list.size; i++) {
        Employee *e = &list.data[i];
        printf("ID: %d | Name: %s | Age: %d | Position: %s | Salary: %.2f\n",
               e->id, e->name, e->age, e->position, e->salary);
    }

    /* cleanup */
    free_employee_list(&list);

    return 0;
}