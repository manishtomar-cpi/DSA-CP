#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
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

    //! BF
    // unordered_map<int, int> hash;
    // vector<int> vec1;
    // vector<int> vec2;
    // vector<vector<int>> res;
    // int count = 0;

    // // removing duplicates from nums1
    // for (int i = 0; i < nums1.size(); i++)
    // {
    //     if (hash[nums1[i]] == 0)
    //     {
    //         vec1.push_back(nums1.at(i));
    //         hash[nums1[i]]++;
    //     }
    // }

    // // make the hash empty because use same hash from nums2
    // for (auto &pair : hash)
    // {
    //     pair.second = 0;
    // }

    // // removing duplicates from nums2.
    // for (int i = 0; i < nums2.size(); i++)
    // {
    //     if (hash[nums2[i]] == 0)
    //     {
    //         vec2.push_back(nums2.at(i));
    //         hash[nums2[i]]++;
    //     }
    // }
    // display(vec1);
    // display(vec2);
    // nums1.clear();
    // nums2.clear();

    // // finding diff in vec1 from vec2
    // for (int i = 0; i < vec1.size(); i++)
    // {
    //     for (int j = 0; j < vec2.size(); j++)
    //     {
    //         if (vec1.at(i) == vec2.at(j))
    //         {
    //             count++;
    //             break;
    //         }
    //     }
    //     if (count == 0)
    //     {
    //         nums1.push_back(vec1.at(i));
    //     }
    //     else
    //     {
    //         count = 0;
    //     }
    // }

    // // finding diff of vec2 from vec1

    // for (int i = 0; i < vec2.size(); i++)
    // {
    //     for (int j = 0; j < vec1.size(); j++)
    //     {
    //         if (vec2.at(i) == vec1.at(j))
    //         {
    //             count++;
    //             break;
    //         }
    //     }
    //     if (count == 0)
    //     {
    //         nums2.push_back(vec2.at(i));
    //     }
    //     else
    //     {
    //         count = 0;
    //     }
    // }
    // display(nums1);
    // display(nums2);

    //! optimized
    // int i =0;
    // int j =0;

    // while(i < vec1.size()){
    //     if(vec1.size() > 0 || vec2.size()>0){
    //         if(vec1[i]==vec2[j]){
    //             vec1.erase(vec1.begin()+i);
    //             vec2.erase(vec2.begin()+j);
    //             j=0;
    //             continue;
    //         }
    //         if(vec1[i]!=vec2[j]){
    //             if(j == vec2.size()-1){
    //                 j=0;
    //                 i++;
    //                 continue;
    //             }
    //         }
    //     }
    //     if(vec1.size()==0 || vec2.size()==0){
    //         res.push_back(vec1);
    //         res.push_back(vec2);
    //         break;
    //     }
    //     j++;

    // }
    // display(vec1);
    // display(vec2);
    // return res;

    //! O(N)
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());
    nums1.clear();
    nums2.clear();
    vector<vector<int>> res;
    // finding the value in first vector which is not present in second vector
    for (int num : set1)
    {
        if (set2.find(num) == set2.end())
        {
            nums1.push_back(num);
        }
    }
    for (int num : set2)
    {
        if (set1.find(num) == set1.end())
        {
            nums2.push_back(num);
        }
    }
    res.push_back(nums1);
    res.push_back(nums2);
    return res;
}

int main()
{
    vector<int> nums1 = {-3, 6, -5, 4, 5, 5};
    vector<int> nums2 = {6, 6, -3, -3, 3, 5};

    func(nums1, nums2);

    return 0;
}