#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void display(unordered_map<int,int> hash){
    for(auto &i :hash){
        cout << i .first << " " ;
    }
    cout << endl;
    for(auto &i :hash){
        cout << i .second << " " ;
    }
    cout << endl;
}

int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++)
    {
        hash[nums[i]]++;
    }

    display(hash);

    for(auto & i : hash){
        if(i.second>(nums.size()/2)){
            return i.first;
        }
    }
    return 0;
}
int main()
{
    vector<int> vec = {3, 2, 3};
    cout << majorityElement(vec) << endl;

    return 0;
}