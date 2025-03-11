#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

int helperKnapsack(vector<int> &weight, int currentIndexOfWeight, vector<int> &price, int currentIndexOfPrice, int totalWeight)
{
    // base case -> when we reach at the end of the any array
    if (currentIndexOfPrice < 0 || currentIndexOfWeight < 0)
    {
        return 0;
    }

    // if current Weight is extra then ignore
    if (weight[currentIndexOfWeight] > totalWeight)
    {
        return helperKnapsack(weight, currentIndexOfWeight - 1, price, currentIndexOfPrice - 1, totalWeight);
    }

    // if inside the weight then first take that one
    int onTaking = price[currentIndexOfPrice] + helperKnapsack(weight, currentIndexOfWeight - 1, price, currentIndexOfPrice - 1, totalWeight - weight[currentIndexOfWeight]);

    // also ignore that
    int notTaking = 0 + helperKnapsack(weight, currentIndexOfWeight - 1, price, currentIndexOfPrice - 1, totalWeight);

    // now takign the maximum in taking and not taking
    int finalAnswer = max(onTaking, notTaking);

    return finalAnswer;
}

int Kanpsack_DP_helper(vector<int> &weight, int currentIndex, vector<int> &price, int totalWeight, unordered_map<string, int> hash)
{
    // base case -> when we reach at the end of the any array
    if (currentIndex < 0 || currentIndex < 0)
    {
        return 0;
    }

    // using memoization

    //! below method for storing the key value is not work because we can have more then one same weights inside the weight array
    // if (hash[weight[currentIndexOfWeight]] != 0)
    // {
    //     return hash[weight[currentIndexOfWeight]];
    // }

    //? creating a unique key for memoization (index + remainingWeight) becaue if the weight ia same then the remaining weight should not same
    string key = to_string(currentIndex) + "_" + to_string(totalWeight);
    if (hash.find(key) != hash.end())
    {
        return hash[key];
    }

    // If the current item's weight exceeds remaining weight, skip it
    if (weight[currentIndex] > totalWeight)
    {
        return helperKnapsack(weight, currentIndex - 1, price, currentIndex - 1, totalWeight);
    }

    // Case 1: Include the current item
    int onTaking = price[currentIndex] + helperKnapsack(weight, currentIndex - 1, price, currentIndex - 1, totalWeight - weight[currentIndex]);

    // Case 2: Exclude the current item
    int notTaking = 0 + helperKnapsack(weight, currentIndex - 1, price, currentIndex - 1, totalWeight);

    // now takign the maximum in taking and not taking
    int finalAnswer = max(onTaking, notTaking);

    //! storing for current weight again not correct same as above
    // hash[weight[currentIndexOfWeight]] = finalAnswer;

    // string storingKey = to_string(currentIndex) + "_" + to_string(totalWeight); -> insted of this we can use above key to make code clean
    hash[key] = finalAnswer;

    return finalAnswer;
}

int Knapsack(vector<int> &weight, vector<int> &price, int totalWight)
{

    return helperKnapsack(weight, weight.size() - 1, price, price.size() - 1, totalWight);
}

int kanpsack_DP(vector<int> &weight, vector<int> &price, int totalWight, unordered_map<string, int> hash)
{
    return Kanpsack_DP_helper(weight, weight.size() - 1, price, totalWight, hash);
    
}

int kanpsack_DP_iterative(const vector<int>&weight, vector<int>&price, const int totalWeight){

     int n = price.size(); //total number of rows we find from this 
     //int dp[n+1][totalWeight+1]; //! called VSA (variable size array) not works in vs code that why create from vector
     vector<vector<int>> dp(n + 1, vector<int>(totalWeight + 1, 0)); //creating 2D array matrix from vector

     //fill the db table
    //  for(int i =0; i<=n;i++){
    //     int j=0;
    //  }
}

int main()
{
    vector<int> weight = {10, 20, 30};
    vector<int> price = {60, 100, 120};
    int totalWeight = 50;

    unordered_map<string, int> hash;
    // cout << Knapsack(weight, price, totalWeight) << endl;
    cout << kanpsack_DP(weight, price, totalWeight, hash) << endl;

    return 0;
}