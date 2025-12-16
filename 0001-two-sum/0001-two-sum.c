int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for(int i = 0; i < numsSize - 1; i++) {
        for(int j = 0; j < numsSize; j++) {
            if(j == i) {
                continue;
            }

            if(*(nums + i) + *(nums + j) == target) {
                int *result = (int *)calloc(2, sizeof(int));
                *(result + 0) = i;
                *(result + 1) = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}