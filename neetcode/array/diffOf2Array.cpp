#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void display(vector<int> &vec)
{
    cout << "[ ";
    for (auto &i : vec)
    {
        cout << i << " ";
    }
    cout << "]" << endl;
}

vector<vector<int>> func(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> hash;
    vector<int> vec1;
    vector<int> vec2;
    vector<vector<int>> res;
    int count =0;

    for (int i = 0; i < nums1.size(); i++)
    {
        if (hash[nums1[i]] == 0)
        {
            vec1.push_back(nums1.at(i));
            hash[nums1[i]]++;
        }
    }
   for (auto& pair : hash) { //make the hash empty
        pair.second = 0; 
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        if (hash[nums2[i]] == 0)
        {
            vec2.push_back(nums2.at(i));
            hash[nums2[i]]++;
        }
    }
    display(vec1);
    display(vec2);
    nums1.clear();
    nums2.clear();

    for (int i = 0; i < vec1.size(); i++)
    {
        for (int j = 0; j < vec2.size(); j++)
        {
            if (vec1.at(i) == vec2.at(j))
            {
                count++;
                break;
                
            }
        }
        if(count ==0){
            nums1.push_back(vec1.at(i));
        }else{
            count =0;
        }
    }

    for (int i = 0; i < vec2.size(); i++)
    {
        for (int j = 0; j < vec1.size(); j++)
        {
            if (vec2.at(i) == vec1.at(j))
            {
                count++;
                break;
                
            }
        }
        if(count ==0){
            nums2.push_back(vec2.at(i));
        }else{
            count =0;
        }
    }
    display(nums1);
    display(nums2);
}

int main()
{
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2,4,6};

    func(nums1, nums2);

    return 0;
}