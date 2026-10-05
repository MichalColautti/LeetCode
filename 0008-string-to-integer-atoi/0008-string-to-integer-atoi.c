#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

int myAtoi(char* s) {
    int counter = 0;
    if(*(s + counter) == '\0') {
        return 0;
    }

    while(*(s + counter) == ' ') {
        counter++;
        if(*(s + counter) == '\0') {
            return 0;
        }
    }

    bool isNegative = false;
    if (*(s + counter) == '-') {
        isNegative = true;
        counter++;
    }    else if (*(s + counter) == '+') {
        counter++;
    }


    int result = 0;
    while (*(s + counter) >= '0' && *(s + counter) <= '9') {
        if(result > (INT_MAX - (*(s + counter) - '0'))/10) {
            return isNegative ? INT_MIN : INT_MAX;
        }
        result *= 10;
        printf("char %c\n", *(s+counter));
        result += *(s + counter) - '0';
        counter++;
    }

    return isNegative ? result * -1 : result;;
}