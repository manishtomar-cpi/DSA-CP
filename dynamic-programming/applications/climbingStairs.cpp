#include <iostream>
#include <vector>
using namespace std;

int climbingStairs(int n)
{ //! TIME = exponential
    // base case
    if (n == 1 || n == 0)
    {
        return 1;
    }

    // now we are calculating total steps from 1 and total steps from 2 jump then add both and get total ways
    int fromOne = climbingStairs(n - 1);
    int fromTwo = climbingStairs(n - 2);

    int totalSteps = (fromOne + fromTwo);

    return totalSteps;
}

// using DP
int climbingStairsDP(int n, vector<int> &vec)
{ //? TIME is linear O(N) :)
    if (n == 1 || n == 0)
    {
        return 1;
    }

    // from memoization directly
    if (vec[n] != -1)
    {
        return vec[n];
    }

    int fromOne = climbingStairs(n - 1);
    int fromTwo = climbingStairs(n - 2);

    int totalSteps = (fromOne + fromTwo);

    // doing memoization by storing new result
    vec[n] = totalSteps;
    return totalSteps;
}

int climbingStairsIterativeDP(int n)
{//? TIME :- LINEAR -> O(N)
    vector<int> vec(n + 1, -1);
    // relation is :- f(n) = f(n-1) + f(n-2) -> then fill base cases
    vec[0] = 1;
    vec[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        // fill all the steps in one iteration according to relation
        vec[i] = vec[i - 1] + vec[i - 2];
    }

    // return the answer
    return vec[n];
}

int main()
{
    // cout << climbingStairs(3) << endl;

    //++++DP++++
    int n = 3;
    vector<int> vec(n + 1, -1); // why n+1, because if we want to access n[3] we will no go out of bound

    cout << climbingStairsDP(n, vec) << endl;

    //++++ITERATIVE DP++++
    cout << climbingStairsIterativeDP(3) << endl;

    return 0;
}