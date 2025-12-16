int romanDigitToInt(char c) {
    switch(c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
    }

    return -1;
}

int romanToInt(char* s) {
    int len = strlen(s);
    int num = 0;
    
    for(int i = 0; i < len - 1; i++) {
        int currentNum = romanDigitToInt(*(s + i));
        int nextNum = romanDigitToInt(*(s + i + 1));
        if(currentNum < nextNum) {
            num -= currentNum;
        }
        else {
            num += currentNum;
        }
    }

    num += romanDigitToInt(*(s + len - 1));
    return num;
}