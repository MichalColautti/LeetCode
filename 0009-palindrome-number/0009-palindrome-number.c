bool isPalindrome(int x) {
    if(x < 0) {
        return false;
    }

    int numLen = 0;
    int tmp = x;
    while(tmp > 0) {
        tmp /= 10;
        numLen++;
    }

    for(int i = 0; i < numLen/2; i++) {
        int num1 = x % (int) pow(10,(i + 1));
        int num2 = x % (int) pow(10,(numLen - i));
        if(num1 < pow(10,(i + 1 - 1))) {
            num1 = 0;
        }
        else {
            for(int j = 0; j < i; j++) {
                num1 /= 10;
            }
        }
        
        if(num2 < pow(10,(numLen - i - 1))) {
            num2 = 0;
        }
        else {
            for(int j = 0; j < numLen - i - 1; j++) {
                num2 /= 10;
            }
        }

        if(num1 != num2) {
            return false;
        }
    }

    return true;
}