#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
void display(vector<int> &vec)
{
    cout << "[ ";
    for (auto &i : vec)
    {
        cout << i << " | ";
    }
    cout << "]" << endl;
}
void removeDuplicate(vector<int> &vec)
{
    unordered_map<int, int> myMap;
    vector<int> res; // for result
    for (int i = 0; i < vec.size(); i++)
    {
        // checking occur
        if (myMap[vec[i]] < 1)
        {
            res.push_back(vec[i]);
            myMap[vec[i]]++;
        }
    }
    display(res);
}

int main()
{
    vector<int> vec = {1, 8, 2, 3, 1, 2, 3, 4, 5, 1, 4, 3};
    removeDuplicate(vec);

    return 0;
}