#include <math.h>
#include <stdio.h>

int isPalindrome(int x) {
    if (x < 0) {
        return 0;
    }

    // find the number of digits
    int num_digits = 0;
    int temp = x;
    while (temp > 0) {
        temp /= 10;
        num_digits++;
    }

    // compare the digits, left must be equal to right
    int left = 0;
    int right = num_digits - 1;
    while (left < right) {
        int left_digit = (x / (int)pow(10, left)) % 10;
        int right_digit = (x / (int)pow(10, right)) % 10;
        if (left_digit != right_digit) {
            return 0;
        }
        left++;
        right--;
    }

    return 1;
}

void main() {
    int x = 334433;
    int res = isPalindrome(x);
    printf("%d\n", res);
}