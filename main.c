#include <stdio.h>
#include <string.h>
#include "employee.h"
#include "file_handler.h"
#include "ui.h"

int main(void) {
    EmployeeList list;
    init_employee_list(&list);
    char filename[100] = "employees.csv";

    while (1) {
        show_main_menu();
        int choice = get_menu_choice();

        if (choice == 1) {
            Employee e = get_employee_input();
            add_employee(&list, e);
            printf("Employee added.\n");
        }
        else if (choice == 2) {
            for (size_t i = 0; i < list.size; i++) {
                Employee *e = &list.data[i];
                printf("%d | %s | %d | %s | %.2f\n", e->id, e->name, e->age, e->position, e->salary);
            }
        }
        else if (choice == 3) {
            int id = get_int_input("Enter ID: ");
            Employee *e = find_employee_by_id(&list, id);
            if (e)
                printf("Found: %s\n", e->name);
            else
                printf("Not found.\n");
        }
        else if (choice == 4) {
            char name[100];
            get_string_input("Enter Name: ", name, sizeof(name));
            Employee *e = find_employee_by_name(&list, name);
            if (e)
                printf("Found: %d\n", e->id);
            else
                printf("Not found.\n");
        }
        else if (choice == 5) {
            int id = get_int_input("Enter ID: ");
            Employee *e = find_employee_by_id(&list, id);
            if (!e) { printf("Not found.\n"); continue; }
            *e = get_employee_input();
            printf("Updated.\n");
        }
        else if (choice == 6) {
            int id = get_int_input("Enter ID: ");
            if (delete_employee(&list, id)) printf("Deleted.\n");
            else printf("Not found.\n");
        }
        else if (choice == 7) {
            save_employees_to_file(filename, &list);
            printf("Saved.\n");
        }
        else if (choice == 8) {
            free_employee_list(&list);
            init_employee_list(&list);
            load_employees_from_file(filename, &list);
            printf("Loaded.\n");
        }
        else if (choice == 0) {
            break;
        }
        else printf("Invalid.\n");
    }

    free_employee_list(&list);
    return 0;
}