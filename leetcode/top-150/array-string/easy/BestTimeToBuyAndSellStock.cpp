#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
    //! BF Approach : TIME: O(N^2), SPACE:O(1)
    // int maxProfit = 0;
    // for (int i = 0; i < prices.size(); i++)
    // {
    //     for (int j = i + 1; j < prices.size(); j++)
    //     {
    //         int profit = prices[j] - prices[i];
    //         maxProfit = max(profit, maxProfit);
    //     }
    // }
    // return maxProfit;

    //! SLIDING WINDOW + TWO POINTER APPROACH: TIME O(N), SPACE O(1)
    /*
    Try buying on day i, and selling on every day after i.
    Calculate the profit and update maxProfit if it’s better.
    */
    int left = 0;
    int right = 1;
    int maxProfit = 0;
    while (right < prices.size())
    {
        if (prices[right] >
            prices[left])
        { // means we can sell the stock here
            int profit = prices[right] - prices[left];
            maxProfit = max(profit, maxProfit); // taking maximum of current profit and previos profit
        }
        else
        {
            left = right; // time to buy a stock again because the value goes down as compared to previos bought value
        }
        right++;
    }
    return maxProfit;
}

int main()
{
    vector<int> vec = {7, 1, 5, 3, 6, 4};

    cout << maxProfit(vec) << endl;
    ;

    return 0;
}
