#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* return_value = (int*)malloc(2 * sizeof(int));

    int* diff_vec = (int*)malloc(numsSize * sizeof(int));
    int* sorted_index_vec = (int*)malloc(numsSize * sizeof(int));
    int smallest_diff = 0;
    int smallest_diff_index = 0;

    int current_sorted_index = 0;

    // Find the smallest difference in diff_vec and sort indices
    for (int i = 0; i < numsSize; i++) {
        diff_vec[i] = target - nums[i];
        if (i == 0) {
            smallest_diff = diff_vec[i];
            smallest_diff_index = i;
            sorted_index_vec[0] = i;
            current_sorted_index++;
        } else {
            int j = current_sorted_index - 1;
            while (j >= 0 && abs(diff_vec[sorted_index_vec[j]]) > abs(diff_vec[i])) {
                sorted_index_vec[j + 1] = sorted_index_vec[j];
                j--;
            }
            sorted_index_vec[j + 1] = i;
            current_sorted_index++;
        }
    }

    // Find the second number by comparing subtracting the smallest difference from the target
    // in case it is not found move to the next smallest difference
    int current_smallest_diff_index = 0;
    for (int i = 0; i < numsSize; i++) {
        current_smallest_diff_index = sorted_index_vec[i];
        for (int j = 0; j < numsSize; j++) {
            if (nums[j] == target - nums[current_smallest_diff_index] && j != current_smallest_diff_index) {
                return_value[0] = j;
                return_value[1] = current_smallest_diff_index;
                break;
            }
        }
    }

    free(diff_vec);
    free(sorted_index_vec);

    *returnSize = 2;

    return return_value;
}

void main() {
    int nums[] = { 2, 7 ,11, 15 };
    int numsSize = 4;
    int target = 9;
    int* returnSize = NULL;
    twoSum(nums, numsSize, target, returnSize);
    printf("Indices: %d, %d\n", returnSize[0], returnSize[1]);
    free(returnSize);
}