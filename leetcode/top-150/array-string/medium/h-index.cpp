#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
---------------------------------------
What is H-Index?

The H-Index tells us:
"How many of a researcher's papers were cited at least that many times?"

For example:
If 3 papers were each cited at least 3 times,
then h-index = 3

---------------------------------------
Why Sort in Descending Order?

We want to find the biggest number h such that:
   → h papers have at least h citations

So we:
1. Sort the citations from highest to lowest
2. Check for each position (i):
   → if citations[i] >= i + 1
   → count how many times this is true

The highest such value of i+1 is the h-index.

---------------------------------------
Easy to remember:
"How many good papers are there with at least that many citations?"
---------------------------------------
*/

int hIndex(vector<int> &citations)
{
    int h_index = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    for (int i = 0; i < citations.size(); i++)
    {
        if (citations[i] >= i + 1)
        {
            h_index++;
        }
    }
    return h_index;
}

int main()
{
    vector<int> vec = {3, 0, 6, 1, 5};

    cout << hIndex(vec) << endl;

    return 0;
}
