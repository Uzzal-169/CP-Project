#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "utils.h"

/* helper function to test trim */
void test_trim(const char *input, const char *expected) {
    char buffer[256];

    strcpy(buffer, input);
    trim(buffer);

    printf("Input:    \"%s\"\n", input);
    printf("Trimmed:  \"%s\"\n", buffer);
    printf("Expected: \"%s\"\n\n", expected);

    assert(strcmp(buffer, expected) == 0);
}

int main() {
    printf("Running trim() tests...\n\n");

    /* leading and trailing spaces */
    test_trim("   Hello World   ", "Hello World");

    /* only leading spaces */
    test_trim("      Hello", "Hello");

    /* only trailing spaces */
    test_trim("Hello      ", "Hello");

    /* no spaces */
    test_trim("Hello", "Hello");

    /* tabs and newlines */
    test_trim("\t\tHello World\n", "Hello World");

    /* mixed whitespace */
    test_trim(" \n\t  Hello\t \n", "Hello");

    /* empty string */
    test_trim("", "");

    /* string with only spaces */
    test_trim("     ", "");

    /* single character */
    test_trim(" A ", "A");

    printf("All trim() tests passed successfully ✅\n");
    return 0;
}