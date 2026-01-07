#include <stdlib.h>

int checkPalindrome(const char *s, int left, int right, int len) {
    while (left >= 0 && right < len && *(s + left) == *(s + right)) {
        left--;
        right++;
    }

    return right - left - 1;
}

char* longestPalindrome(const char* s) {
    if (s == NULL || *s == '\0') {
        return "";
    }

    int longest = 0;
    int start = 0;
    char *res;
    int length = 0;

    // get length
    while(*(s + length) != '\0') {
        length++;
    }

    for (int i = 0; i < length; ++i) {
        // check even palindrome
        int len1 = checkPalindrome(s,i,i+1,length);

        // check odd palindrome
        int len2 = checkPalindrome(s,i,i,length);

        int current = 0;
        if(len1 > len2) {
            current = len1;
        }
        else {
            current = len2;
        }

        if(current > longest) {
            longest = current;
            start = i - (current -1)/2;
        }
    }

    res = (char *)malloc(sizeof(char) * (longest + 1));
    if(res == NULL) {
        return "";
    }

    for (int i = 0; i < longest; ++i) {
        *(res + i) = *(s + start + i);
    }
    *(res + longest) = '\0';

    return res;
}