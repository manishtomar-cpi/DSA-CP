#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void func(vector<int> &vec)
{
    unordered_map<int, int> hash; // hashtable
    vector<int> res;
    for (int i = 0; i < vec.size(); i++)
    {
        if (hash[vec[i]] == 0)
        {
            res.push_back(vec[i]);
            hash[vec[i]]++;
        }
    }

    //! making hash empty
    for (auto &i : hash)
    {
        i.second = 0; // making all the key's value to zero //!including -ve also
    }
}