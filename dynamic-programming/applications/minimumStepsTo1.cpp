#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int _Minimum_Steps_To_1_(int n)
{
    if (n <= 0)
    {
        return -1;
    }
    int steps = 0;
    while (n != 1)
    {
        if (n % 3 == 0)
        {
            n /= 3;
        }
        else if (n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n -= 1;
        }
        steps++;
    }
    return steps;
}

/*
if we take example of 10 according to _Minimum_Steps_To_1_ function
10->5->4->2->1 total 4 steps, but the minimum should be 10->9->3->1 = 3 steps
thats why the minStepsUsingRec is more accurate then the above one
because first we are calculating all three and then taking minimum of all result and move forward from that result
*/

int minStepsUsingRec(int n)
{
    if (n <= 1)
    { // base case
        return 0;
    }

    // here we will do all 3 checks store answer of all three and take minimum of all
    int first = minStepsUsingRec(n - 1);
    int second = INT8_MAX, third = INT8_MAX; //?why int_max because if we declare them with 0, in final answer the minimum will come 0 that should wrong
    if (n % 3 == 0)
    {
        second = minStepsUsingRec(n / 3);
    }
    if (n % 2 == 0)
    {
        third = minStepsUsingRec(n / 2);
    }

    int finalAns = min(first, min(second, third)) + 1;
    // We are adding 1 because each recursive call represents one step taken to reduce n to 1.

    return finalAns;

    /*
    minSteps(4) calls minSteps(3) first
        minSteps(3) calls minSteps(2) first
            minSteps(2) calls minSteps(1) first
                minSteps(1) → Base case, returns 0
            Now minSteps(2) computes: min(1) + 1 = 1, returns 1
        Now minSteps(3) computes: min(2, 1) + 1 = 1, returns 1
    Now minSteps(4) computes: min(3, 2) + 1 = 2, returns 2
TIME:-(2^n)
    */
}

int minStepUsing__DP(int n, vector<int> &vec)
{ // Now the time is O(N)
    if (n <= 1)
    {
        return 0; // base
    }

    // With the help of memoization we can directly give Answer in O(1)
    if (vec[n] != -1)
    {
        return vec[n];
    }
    int first = minStepUsing__DP(n - 1, vec);
    int second = INT16_MAX;
    int third = INT16_MAX;
    if (n % 3 == 0)
    {
        second = minStepUsing__DP(n / 3, vec);
    }
    if (n % 2 == 0)
    {
        third = minStepUsing__DP(n / 2, vec);
    }
    int finalAnswer = min(first, min(second, third)) + 1; //+1 for the step took

    // doing memoization
    vec[n] = finalAnswer;
    return finalAnswer;
}

int minStepsDP_Iterative(int n)
{
    // from the minStepUsing__DP method we can find the relation that is
    // if we are going from ith number to 1 then we need to go i-1
    // index and if i divide by 2 then i/2th index else i/3th index , then take minimum of that and add 1
    vector<int> dp(n + 1, 0);
    // first add 0,1 index because every time they are 0
    dp[0] = 0;
    dp[1] = 0;

    // now traverse and fill the array first according to relation
    for (int i = 2; i <= n; i++)
    {
        int first = dp[i - 1]; // we always take that step
        int second = INT8_MAX;
        int third = INT8_MAX;
        if (i % 2 == 0) 
        {
            second = dp[i / 2];
        }
        if (i % 3 == 0)
        {
            third = dp[i / 3];
        }
        int finalAns = min(first, min(second, third)) + 1;

        // now update the current index
        dp[i] = finalAns;
    }
    return dp[n];
}

int main()
{
    // cout << _Minimum_Steps_To_1_(10) << endl;

    // cout << minStepsUsingRec(10) << endl;

    //--------DP----------
    // int n = 10;
    // vector<int> vec(n + 1, -1);
    // cout << minStepUsing__DP(n, vec) << endl;
    // return 0;
    //------------DP------------

    /*
    The reason we allocate n+1 elements in the vector is to avoid out-of-bounds errors when accessing vec[n].

    Problem with vector<int> vec(n, -1);
    If we declare:
    vector<int> vec(n, -1);  //  Incorrect if we need to access vec[n]
    This creates a vector of size n.
    Valid indices are 0 to n-1.
    But in our function, we access vec[n], which is out of bounds.

    Example Issue
    If n = 10:
    vector<int> vec(10, -1); creates a vector of size 10 with indices 0 to 9.
    But we call vec[10] inside minStepUsing__DP(10, vec), which does not exist in this case.
    This results in undefined behavior (segmentation fault or garbage values).

    */

    cout << minStepsDP_Iterative(10) << endl;
}