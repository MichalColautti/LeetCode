#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* convert(char* s, int numRows) {
    if(s == NULL || *s == '\0' || numRows <= 0) {
        return "";
    }
    if(numRows == 1) {
        return s;
    }

    int len = 0;
    while(*(s + len) != '\0') {
        len++;
    }

    char *res = (char *)malloc((len + 1) * sizeof(char));
    if(res == NULL) {
        return "";
    }
    *(res + len) = '\0';

    int counter = 0;
    int distance = numRows + numRows - 2;
    for (int i = 0; i < numRows; ++i) {
        for (int j = i; j < len; j += distance) {
            // add straight column
            *(res + counter) = *(s + j);
            counter++;

            // add diagonal
            if(i != 0 && i != numRows - 1) {
                if(j + distance - 2 * i < len) {
                    *(res + counter) = *(s + j + distance - 2 * i);
                    counter++;
                }
            }
        }
    }

    return res;
}