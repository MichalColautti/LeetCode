#include  <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int size = nums1Size + nums2Size;
    int *tabSum = (int *) calloc(size, sizeof(int));
    int count1 = 0;
    int count2 = 0;

    // adds nums1 and nums2 sorted
    for (int i = 0; i < size; ++i) {
        // when all numbers used from nums1
        if(count1 >= nums1Size) {
            *(tabSum + i) = *(nums2 + count2);
            count2++;
            continue;
        }

        // when all numbers used from nums1
        if(count2 >= nums2Size) {
            *(tabSum + i) = *(nums1 + count1);
            count1++;
            continue;
        }

        // add nums1 and nums2 sorted
        if(*(nums1 + count1) < *(nums2 + count2)) {
            *(tabSum + i) = *(nums1 + count1);
            count1++;
        }
        else {
            *(tabSum + i) = *(nums2 + count2);
            count2++;
        }
    }

    bool sizeIsEven = size % 2 == 0;

    if(sizeIsEven) {
        return (double)(*(tabSum + (size/2 - 1)) + *(tabSum + (size/2)))/2;
    }
    else {
        return *(tabSum + (size - 1)/2);
    }
}