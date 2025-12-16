int strStr(char* haystack, char* needle) {
    int hayLen = strlen(haystack);
    int needleLen = strlen(needle);

    for(int i = 0; i < hayLen - needleLen + 1; i++) {
        for(int j = 0; j < needleLen; j++) {
            if(*(haystack + i + j) != *(needle + j)) {
                break;
            }
            if(j == needleLen - 1) {
                return i;
            }
        }
    }

    return -1;
}