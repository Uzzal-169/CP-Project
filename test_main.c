#include <stdio.h>
#include <stdlib.h>

/*
    This test file simulates user input for main.c
    using freopen() to redirect stdin from a file.
*/

int main(void) {
    printf("===== Running Employee Management System Test =====\n");

    /* Redirect input from test_input.txt */
    if (freopen("test_input.txt", "r", stdin) == NULL) {
        perror("Failed to open test_input.txt");
        return 1;
    }

    /* Run the actual program */
    system("./ems");   // ems is the compiled executable of main.c

    printf("\n===== Test Completed =====\n");
    return 0;
}