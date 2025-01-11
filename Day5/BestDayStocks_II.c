
#include <stdio.h>


int maxProfit_II(int* prices, int pricesSize) {

    int current_profit = 0;

    for (int i = 0; i < pricesSize-1; i++) {
        if (prices[i] < prices[i + 1]) {
            current_profit += prices[i + 1] - prices[i];
            //printf("current profit %d; buy %d sell %d\n", current_profit, prices[i], prices[i + 1]);
        }
    }
    return current_profit;
}

//
//void main() {
//    int* test1[6];
//    test1[0] = 7;
//    test1[1] = 1;
//    test1[2] = 5;
//    test1[3] = 3;
//    test1[4] = 6;
//    test1[5] = 4;
//
//    int mp = maxProfit_II(test1, 6);
//    printf("%d", mp);
//}