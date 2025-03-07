#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


bool k_sorted(vector<int> &vec, int k)
{
    //! from MAP
    // unordered_map<int, int> withoutSort;
    // // unordered_map<int, int> sorted;
    // for (int i = 0; i < vec.size(); i++)
    // {

    //     withoutSort[vec[i]] = i;
    // }

    // // auto it = withoutSort.begin();
    // // while (it != withoutSort.end())
    // // {
    // //     cout << "key: " << it->first << " value: " << it->second << endl;
    // //     it++;
    // // }

    // sort(vec.begin(), vec.end());    // Ascending order
    // reverse(vec.begin(), vec.end()); // Reverse to descending order

    // // for (int i = 0; i < vec.size(); i++)
    // // {

    // //     sorted[vec[i]] = i;
    // // }
    // // auto it1 = sorted.begin();
    // // while (it1 != sorted.end())
    // // {
    // //     cout << "key: " << it1->first << " value: " << it1->second << endl;
    // //     it1++;
    // // }

    // for (int i = 0; i < vec.size(); i++)
    // {
    //     int diff = withoutSort[vec[i]] - i;
    //     cout << vec[i] << endl;
    //     if (diff >= k)
    //     {
    //         return false;
    //     }
    // }
    // return true;

    //! with PQ
    priority_queue<int> order;
    bool flag = false;
    for (int i = 0; i < vec.size(); i++)
    {
        order.push(vec[i]);
    }

    for (int i = 0; i < vec.size(); i++)
    {
        for (int i = 0; i < k; i++)
        {
            if (vec[i] == order.top())
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            flag = false;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void k_smallest(vector<int> &vec, int k)
{
    priority_queue<int> smallest;
    /*
    STEP 1:- Store the first K elements of vector in PQ
    STEP2:- loop over vector from index equal the size of PQ
    STEP3:- if any element lesser then top, pop the top and add the lesser in PQ. Otherwise, do nothing! Because the top one is the heighest element in the queue,
    if the current element in array is greator then top it should greater then rest of the elements in the queue.
    */

    //?STEP1
    for (int i = 0; i < k; i++)
    {
        smallest.push(vec[i]);
    }

    //?STEP2
    for (int j = smallest.size(); j < vec.size(); j++)
    {

        //?STEP3
        if (vec[j] < smallest.top())
        {
            smallest.pop();
            smallest.push(vec[j]);
        }
    }
    while (!smallest.empty())
    {
        cout << smallest.top() << endl;
        smallest.pop();
    }
}

int main()
{
    vector<int> vec = {10, 12, 6, 15, 9};
    int k = 3;

    cout << boolalpha;
    cout << k_sorted(vec, k) << endl;

    vector<int> vec = {5, 6, 9, 12, 3, 13, 2};
    k_smallest(vec, 3);

    return 0;
}