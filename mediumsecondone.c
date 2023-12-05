#include <stdio.h>
#include <stdlib.h>

int* majorityElement(int* nums, int numsSize, int* returnSize) {
    int candidate1 = 0, count1 = 0;
    int candidate2 = 0, count2 = 0;

    // Voting process to find potential candidates
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1) {
            count1++;
        } else if (nums[i] == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = nums[i];
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = nums[i];
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    // Count occurrences of potential candidates
    count1 = count2 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1) {
            count1++;
        } else if (nums[i] == candidate2) {
            count2++;
        }
    }

    // Check if candidates appear more than ⌊ n/3 ⌋ times
    int* result = (int*)malloc(sizeof(int) * 2);
    *returnSize = 0;

    if (count1 > numsSize / 3) {
        result[(*returnSize)++] = candidate1;
    }

    if (count2 > numsSize / 3 && candidate1 != candidate2) {
        result[(*returnSize)++] = candidate2;
    }

    return result;
}

int main() {
    // Test cases
    int nums1[] = {3, 2, 3};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int returnSize1;

    int* result1 = majorityElement(nums1, size1, &returnSize1);
    for (int i = 0; i < returnSize1; i++) {
        printf("%d ", result1[i]);  // Output: 3
    }
    printf("\n");

    free(result1);

    int nums2[] = {1};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int returnSize2;

    int* result2 = majorityElement(nums2, size2, &returnSize2);
    for (int i = 0; i < returnSize2; i++) {
        printf("%d ", result2[i]);  // Output: 1
    }
    printf("\n");

    free(result2);

    int nums3[] = {1, 2};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    int returnSize3;

    int* result3 = majorityElement(nums3, size3, &returnSize3);
    for (int i = 0; i < returnSize3; i++) {
        printf("%d ", result3[i]);  // Output: 1 2
    }
    printf("\n");

    free(result3);

    return 0;
}
