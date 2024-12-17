#include <string.h>
#include "stringutils.h"

void trimString(char *str) {
    int start = 0, end = strlen(str) - 1;
    
    // Remove leading special characters
    while (start <= end && (str[start] == ' ' || str[start] == '-' || str[start] == ',')) {
        start++;
    }
    
    // Remove trailing special characters
    while (end >= start && (str[end] == ' ' || str[end] == '-' || str[end] == ',')) {
        end--;
    }
    
    // Shift the string
    int i;
    for (i = 0; start <= end; start++, i++) {
        str[i] = str[start];
    }
    str[i] = '\0';
}