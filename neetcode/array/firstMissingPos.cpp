#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>
using namespace std;

int missing(vector<int> &nums)
{
    int start = 0;
    vector<int> positive;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums.at(i) > 0)
        {
            start = i;
            break;
        }
    }
    for (int i = start; i < nums.size(); i++)
    {
        positive.push_back(nums.at(i));
        cout << positive[i] << " from positive" << endl;
    }

    unordered_map<int, int> hash;
    for (int i = 0; i < positive.size(); i++)
    {
        hash[positive[i]]++;
        cout << hash[1] << " when make hash" << endl;
        cout << hash[1000] << " when make hash" << endl;
    }

     if(positive.size()==1){
        if(positive[0]==1){
            return 2;
        }
        else{
            return hash[positive[0]];
        }
        }

    for (int i = 0; i < positive.size(); i++)
    {
       
        cout << "checking hash " << hash[i] << endl;
        if (hash[i+1] ==0)
        {
            return i+1;
            break;
        }
    }
    return (positive.at(positive.size() - 1) + 1);
    // return 0;
}
int main()
{
    vector<int> vec = {1,1000};
    cout << missing(vec) << endl;

    return 0;
}