#include <iostream>
#include <vector>
using namespace std;

/*
    - We use two pointers, 'i' to mark the buying day and 'j' to track current day prices.
    - We iterate through the prices using index 'k'. At each step:
        - If the current price is less than the price at index 'i' (our last buy)
          or less than the previous day's price, we assume the price has dropped.
          So, we sell the current stock (by storing the max profit so far) and buy again at the new low price.
    - We calculate profit as the difference between the current price and the buy price.
    - We update the maximum profit during this window.
    - After the loop, if there's any remaining profit not yet added (last upward trend),
      we store that too.
    - Finally, we sum all profits from the stored transactions and return the total profit.
*/
int maxProfit(vector<int> &prices)
{                        //! TIME: O(N), SPACE: O(N) ->because of extra vector
    vector<int> profits; // store the profits on each sell
    int i = 0;
    int j = 0;           // used to track the previos stock value(k) if next stock value is lesser then previos then its time to sell and buy again
    int maxProfit = 0;   // used for max profit of current bought stock
    int totalProfit = 0; // for total profit in trading
    for (int k = 0; k < prices.size(); k++)
    {
        if (prices[k] < prices[i] || prices[k] < prices[j])
        {          // if current stock value is lesser then previos bought value or lesser the previos stock value i> its time to sell and but again
            i = k; // buy the current stock
            j = k;
            profits.push_back(maxProfit); // store the current profit
            maxProfit = 0;                // for next stock profit made it 0
        }
        j = k;
        int profit = prices[k] - prices[i]; // calculate the profit from current stock value
        maxProfit = max(maxProfit, profit); // update max profit accordingly
    }

    // After the loop, if there's any remaining profit not yet added (last upward trend) we store that too.
    if (maxProfit > 0)
    {
        profits.push_back(maxProfit);
    }

    // calculating all sold stock profit
    for (auto i : profits)
    {
        totalProfit += i;
    }
    return totalProfit;

    //! SPACE OPTIMIZED to O(1)
    //? immediately capturing profit whenever the stock price increases from one day to the next.
    // int totalPro = 0;
    // for (int i = 1; i < prices.size(); i++)
    // {
    //     if (prices[i] > prices[i - 1])
    //     {
    //         totalPro += prices[i] - prices[i - 1];
    //     }
    // }
    // return totalPro;
}

int main()
{
    vector<int> prices = {1, 2, 3, 4, 5};
    cout << maxProfit(prices) << endl;

    return 0;
}