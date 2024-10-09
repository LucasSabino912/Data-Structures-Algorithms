// https://github.com/LucasSabino912

/*
    https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

    You are given an array prices where prices[i] is the price of a given stock on the ith day.

    You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0
*/

func maxProfit(prices []int) int {
    buy := prices[0] // Initialize with first element
    todayProfit, maxProfit := 0, 0 // Tracking maximum and today's profit

    // Return 0 if the array is empty
    if len(prices) == 0 {
        return 0 
    }

    // Iterate through the array
    for _, price := range prices {
        if price < buy {
            buy = price
        }

        todayProfit = price - buy

        if todayProfit > maxProfit {
            maxProfit = todayProfit
        }
    }

    return maxProfit
}