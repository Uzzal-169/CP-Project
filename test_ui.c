#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"
#include "employee.h"  // Assuming this defines Employee and NAME_LEN

#define MAX_EMPLOYEES 100

int main() {
    Employee employees[MAX_EMPLOYEES];
    int employee_count = 0;

    int choice;

    do {
        show_main_menu();
        choice = get_menu_choice();

        switch(choice) {
            case 1:  // Add Employee
                if(employee_count < MAX_EMPLOYEES) {
                    employees[employee_count] = get_employee_input();
                    employee_count++;
                    printf("\nEmployee added successfully!\n");
                } else {
                    printf("\nEmployee list is full!\n");
                }
                break;

            case 2:  // Display All Employees
                if(employee_count == 0) {
                    printf("\nNo employees to display.\n");
                } else {
                    printf("\n=== Employee List ===\n");
                    for(int i = 0; i < employee_count; i++) {
                        Employee e = employees[i];
                        printf("ID: %d, Name: %s, Age: %d, Position: %s, Salary: %.2lf\n",
                               e.id, e.name, e.age, e.position, e.salary);
                    }
                }
                break;

            case 0:  // Exit
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }

    } while(choice != 0);

    return 0;
}