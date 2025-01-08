
#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    int current_lowest_price = 999999;
    int current_highest_price = 0;

    int current_profit = 0;
    int max_profit = 0;

    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < current_lowest_price) {
            current_lowest_price = prices[i];
        }
        current_profit = prices[i] - current_lowest_price;
        if (current_profit > max_profit) {
            max_profit = current_profit;
        }
    }

    if (max_profit < 0) {
        max_profit = 0;
    }
    return max_profit;
}

//void main() {
//    int* test1[6];
//    test1[0] = 7;
//    test1[1] = 1;
//    test1[2] = 5;
//    test1[3] = 3;
//    test1[4] = 6;
//    test1[5] = 4;
//
//    int mp = maxProfit(test1, 6);
//    printf("%d", mp);
//}