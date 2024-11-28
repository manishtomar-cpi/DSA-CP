#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isDup(vector<int> &nums)
{
    // BF approach
    // for (int i =0; i< nums.size();i++){
    //     for(int j = i+1; j <nums.size();j++){
    //         if(nums.at(i)== nums.at(j)){
    //             return true;
    //             break;
    //         }
    //     }
    //}

    // HASH
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++)
    {
        hash[nums[i]]++;
        if (hash[nums[i]] > 1)
        {
            return true; // Duplicate found
        }
    }
    // here nums[i] is the key in map and the apprearence is the value

    // SLIDER/TWO POINTERS
    //  int i =0;
    //  int j = i+1;
    //  if (nums.size()==0){
    //      return false;
    //  }
    //  while(i< nums.size()-1){
    //  if(nums.at(i)==nums.at(j)){
    //      return true;
    //  } else if (nums.at(i)!= nums.at(j)){
    //      if(j == nums.size()-1){
    //          i++;
    //          j= i+1;
    //          continue;
    //      }

    // }
    // j++;
    // }
    return false;
}

int main()
{
    vector<int> vec = {1, 2, 3, 4};
    cout << boolalpha;
    cout << isDup(vec);

    return 0;
}