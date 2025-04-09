#include <iostream>
#include <vector>
using namespace std;

/*
---------------------------------------------------------
GAS STATION PROBLEM
---------------------------------------------------------

GOAL:
We have gas stations in a circle.
- Each station gives us some gas (gas[i])
- We need some gas to reach the next station (cost[i])

We want to find one station to start from and go around
the circle once without running out of fuel.

RULES:
- Start with an empty tank
- Visit every station exactly once (circular journey)
- Return the index of the station to start from
- If not possible, return -1

---------------------------------------------------------
STEP-BY-STEP:

1. Calculate total gas and total cost:
   - If total gas < total cost → Impossible to complete
     → return -1

2. Use a greedy approach to find the correct starting point:
   - Start with fuel = 0 and index = 0
   - Move station by station:
     • Add gas[i] - cost[i] to fuel
     • If fuel < 0, we can't reach next station
       → Restart from next station (i + 1)
       → Reset fuel = 0

3. After full loop, return the starting index

WHY GREEDY WORKS?
Because if we fail between two stations,
no station in between can be a valid starting point.
We skip them and try from the next one.

---------------------------------------------------------
TIME COMPLEXITY:
- O(n) → only one pass through the array

---------------------------------------------------------
*/

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int totalGas = 0;
    int totalCost = 0;

    for (int i = 0; i < gas.size(); i++)
    {
        totalGas += gas[i];
        totalCost += cost[i];
    }
    if (totalCost > totalGas)
    {
        return -1;
    }
    int fuelLeft = 0;
    int i = 0;

    for (int j = 0; j < gas.size(); j++)
    {
        fuelLeft = fuelLeft + gas[j] - cost[j];
        if (fuelLeft < 0)
        {
            i = j;
            i++;
            fuelLeft = 0;
        }
    }
    return i;
}

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    cout << canCompleteCircuit(gas, cost) << endl;
    return 0;
}
//! TIME->O(N^2); because of inner loop
// bool flag = false;
// for (i; i < cost.size(); i++)
// {
//     flag = false;
//     if (cost[i] <= gas[i])
//     {
//         for (int j = i; j < cost.size(); j++)
//         {
//             fuelLeft = fuelLeft + gas[j] - cost[j];
//             if (fuelLeft < 0)
//             {
//                 flag = true;
//                 break;
//             }
//         }
//         fuelLeft = 0;
//         if (!flag)
//         {
//             return i;
//         }
//     }
// }
// return i;
// int fuelLeft = 0;
// int i = 0;