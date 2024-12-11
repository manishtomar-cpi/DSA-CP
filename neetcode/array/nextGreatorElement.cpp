#include <vector>
#include <iostream>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    // vector<int> res;
    // bool isFound = false;
    // int pointer = -1;
    // for (int i = 0; i < nums1.size(); i++)
    // {
    //     isFound = false;
    //     pointer=-1;
    //     for (int j = 0; j < nums2.size(); j++)
    //     {
    //         if (nums2[j] == nums1.at(i))
    //         {
    //             pointer = j;
    //             break;
    //         }
    //     }
    //     for (int k = pointer; k < nums2.size(); k++)
    //     {
    //         if (nums2.at(k) > nums1.at(i))
    //         {
    //             res.push_back(nums2.at(k));
    //             isFound = true;
    //             break;
    //         }
    //     }
    //     if (!isFound)
    //     {
    //         res.push_back(-1);
    //     }
    // }
    // return res;

    //! OPT
    vector<int> res;
    int pos = -1;
    int i = 0;
    int j = 0;
    bool isFound = false;

    while (i < nums1.size())
    {
        if (pos == -1)
        {
            if (nums2[j] == nums1[i])
            {
                pos = j;
                continue;
            }
            if (nums2[j] <= nums1[i])
            {
                j++;
                continue;
            }
        }
        if (pos != -1)
        {
            j = pos;
            if (j < nums2.size() - 1)
            {
                cout << nums2[j] << "nums2"<<j << endl;
                cout << nums1[i] <<" nums1" << i << endl;
                if (nums2[j] > nums1[i])
                {
                    res.push_back(nums2[j]);
                    j = 0;
                    pos = -1;
                    isFound=true;
                    i++;
                    continue;
                }
                if(nums2[j] <= nums1[i]){
                    j++;
                    continue;
                }
            }
            if(j == nums2.size()-1){
               res.push_back(-1);
               isFound=false;
               j=0;
            }
        }
        i++;
    }
}

int main()
{
    vector<int> vec1 = {4, 1, 2};
    vector<int> vec2 = {1, 3, 4, 2};

    nextGreaterElement(vec1, vec2);

    return 0;
}