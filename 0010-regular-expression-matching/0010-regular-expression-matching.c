#include <stdio.h>

bool nextStar(char *s) {
    if (*s == '\0') {
        return false;
    }
    if (*(s + 1) == '*') {
        return true;
    }
    return false;
}

bool isMatch(char* s, char* p) {
    if (*p == '\0') {
        return *s == '\0';
    }

    bool matching = false;
    if(*s != '\0' &&  (*p == '.' || *p == *s)) {
        matching = true;
    }

    if(nextStar(p)) {
        if (isMatch(s, p + 2)) {
            return true;
        }

        if(matching && isMatch(s+1,p)) {
            return true;
        }

        return false;
    }
    else {
        return matching ? isMatch(s + 1, p + 1) : false;
    }
}