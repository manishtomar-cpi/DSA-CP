#include <iostream>
#include <vector>
using namespace std;

vector<int> find_duplicates(vector<int> nums)
{

    vector<int> hash(nums.size() + 1, 0);
    vector<int> missing;

    if (nums.size() == 2)  
    {
        if (nums.at(0) == nums.at(1))
        {
            missing.push_back(nums.at(0));
        }
        return missing;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums.at(i);
        hash.at(nums.at(i)) += 1;
        cout << hash.at(nums.at(i));
    }

    for (int i = 0; i < hash.size(); i++)
    {
        if (hash.at(i) > 1)
        {
            missing.push_back(i);
        }
    }

    for(auto i :missing){
        cout<< i << " "; 
    }
    cout << endl;
    return missing; 
}

int main ()
{
    vector<int>vec = {10,2,5,10,9,1,1,4,3,7};

    find_duplicates(vec);

}