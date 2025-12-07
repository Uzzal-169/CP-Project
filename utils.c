#include "utils.h"
#include <ctype.h>
#include <string.h>

void trim(char *s) {
    if (!s) return;
    int end = strlen(s) - 1;
    while (end >= 0 && isspace(s[end])) s[end--] = '\0';

    int start = 0;
    while (s[start] && isspace(s[start])) start++;

    if (start > 0) memmove(s, s + start, strlen(s + start) + 1);
}