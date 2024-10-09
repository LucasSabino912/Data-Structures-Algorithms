// https://github.com/LucasSabino912

/*
    https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

    You are given an array prices where prices[i] is the price of a given stock on the ith day.

    You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0
*/

#include <stdio.h>
#include <math.h>

int maxProfit(int* prices, int pricesSize) {
    int buy = INT_MAX; // Define buy like upper bound
    int todayProfit = 0, maxProfit = 0;

    if(pricesSize == 0){
        return 0;
    }

    for(int i = 0; i < pricesSize; i++){
        // Checking for the best day to buy (minimum value of the array)
        if(prices[i] < buy){
            buy = prices[i];
        }

        // Profit calc
        todayProfit = prices[i] - buy;

        if(todayProfit > maxProfit){
            maxProfit = todayProfit;
        }
    }

    return maxProfit;
}