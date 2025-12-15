#include <stdio.h>
#include <string.h>
#include "employee.h"

int main() {
    EmployeeList list;
    init_employee_list(&list);

    // Add Employees
    Employee e1 = {101, "Alice", 30, "Manager", 50000};
    Employee e2 = {102, "Bob", 25, "Developer", 40000};

    add_employee(&list, e1);
    add_employee(&list, e2);

    printf("Added Employees:\n");
    for (size_t i = 0; i < list.size; i++) {
        Employee e = list.data[i];
        printf("ID: %d, Name: %s, Age: %d, Position: %s, Salary: %.2lf\n",
               e.id, e.name, e.age, e.position, e.salary);
    }

    // Find by ID
    int search_id = 102;
    Employee *found = find_employee_by_id(&list, search_id);
    if (found) {
        printf("\nFound Employee by ID %d: %s\n", search_id, found->name);
    } else {
        printf("\nEmployee with ID %d not found.\n", search_id);
    }

    // Update Employee
    Employee updated = {102, "Bob Smith", 26, "Senior Developer", 45000};
    if (update_employee(&list, 102, updated)) {
        printf("\nEmployee updated successfully.\n");
    } else {
        printf("\nEmployee update failed.\n");
    }

    // Delete Employee
    if (delete_employee(&list, 101)) {
        printf("\nEmployee with ID 101 deleted successfully.\n");
    } else {
        printf("\nEmployee deletion failed.\n");
    }

    // Final Employee List
    printf("\nFinal Employee List:\n");
    for (size_t i = 0; i < list.size; i++) {
        Employee e = list.data[i];
        printf("ID: %d, Name: %s, Age: %d, Position: %s, Salary: %.2lf\n",
               e.id, e.name, e.age, e.position, e.salary);
    }

    free_employee_list(&list);
    return 0;
}