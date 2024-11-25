#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void displayVectoeElement(vector<int> vec)
{
    cout << "[ ";
    for (int i : vec)
    {
        cout << i << " ";
    }
    cout << "]" << endl;
}

// by bruit force
vector<int> intersectionByBruitForce(vector<int> &nums1, vector<int> &nums2)
{
    set<int> set1(nums1.begin(), nums1.end());
    set<int> set2(nums2.begin(), nums2.end());
    vector<int> inter;

    for (int i : set1)
    {
        for (int j : set2)
        {
            if (i == j)
            {
                inter.push_back(i);
            }
        }
    }
    displayVectoeElement(inter);
    return inter;
}

vector<int> intersectionInON(vector<int> nums1, vector<int> nums2)
{
    vector<int> inter;
    set<int> set1(nums1.begin(), nums1.end());
    set<int> set2(nums2.begin(), nums2.end());

    nums1 = {set1.begin(), set1.end()};
    nums2 = {set2.begin(), set2.end()};

    int i = 0;
    int j = 0;
    if (nums1.size() <= nums2.size())
    {
        if (nums1.size() == 1)
        {
            for (int i = 0; i < nums2.size(); i++)
            {
                if (nums2.at(i) == nums1.at(0))
                {
                    inter.push_back(nums1.at(0));
                }
            }
            displayVectoeElement(inter);
            return inter;
        }
        while (i < nums1.size())
        {
            if (j == nums2.size())
            {

                i++;
                j = 0;
                continue;
            }
            if (nums2.at(j) == nums1.at(i))
            {
                inter.push_back(nums1.at(i));
                j = 0;
                i++;
            }
            else
            {
                j++;
                continue;
            }
        }
    }
    if (nums1.size() > nums2.size())
    {
        if (nums2.size() == 1)
        {
            for (int i = 0; i < nums1.size(); i++)
            {
                if (nums1.at(i) == nums2.at(0))
                {
                    inter.push_back(nums2.at(0));
                }
            }
            displayVectoeElement(inter);
            return inter;
        }
        while (i < nums1.size())
        {
            if (j == nums1.size() - 1)
            {
                i++;
                j = 0;
                continue;
            }
            if (nums1.at(j) == nums2.at(i))
            {
                inter.push_back(nums1.at(i));

                j = 0;
                i++;
            }
            else
            {
                j++;
                continue;
            }
        }
    }
    displayVectoeElement(inter);
    return inter;
}

vector<int> intrsectionBySort(vector<int> nums1, vector<int> nums2)
{
    vector<int> inter;
    set<int> set1(nums1.begin(), nums1.end());
    set<int> set2(nums2.begin(), nums2.end());

    nums1 = {set1.begin(), set1.end()};
    nums2 = {set2.begin(), set2.end()};
    int nums1Size = nums1.at(nums1.size() - 1);
    int nums2Size = nums2.at(nums2.size() - 1);

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    

    for (int i = 0; i < nums1Size; i++)
    {
        if (nums1.at(i) != i + 1)
        {
            nums1.insert(nums1.begin() + i, 0);
        }
    }

    cout << nums2.at(nums2.size() - 1) << endl;

    for (int i = 0; i < nums2Size; i++)
    {
        if (nums2.at(i)==0){
            continue;
        }
        if (nums2.at(i) != i + 1)
        {
            nums2.insert(nums2.begin() + i, 0); // now inserted at specific possition , below is removing the existing value with 0;
            // nums2.at(i)=0;
            // nums.at(i+1)
            // cout << nums2.size();
            // displayVectoeElement(nums2);
            // nums2Size++;
        }
    }

    if (nums1.at(nums1.size() - 1) <= nums2.at(nums2.size() - 1))
    {
        for (int i = 0; i < nums1.at(nums1.size() - 1); i++)
        {
            if ((nums1.at(i) && nums2.at(i)) == 0)
            {
                continue;
            }
            if (nums1.at(i) == nums2.at(i))
            {
                inter.push_back(nums1.at(i));
            }
        }
    }
    
    if (nums1.at(nums1.size() - 1) > nums2.at(nums2.size() - 1))
    {
        for (int i = 0; i < nums2.at(nums2.size() - 1); i++)
        {
            if (nums2.at(i) && nums1.at(i) == 0)
            {
                continue;
            }
            if (nums2.at(i) == nums1.at(i))
            {
                inter.push_back(nums2.at(i));
            }
        }
    }
displayVectoeElement(inter);
    return inter;
}

int main()
{
    vector<int> vec1 = {4,7,9,7,6,7};
    vector<int> vec2 = {5,0,0,6,1,6,2,2,4};
    // intersectionByBruitForce(vec1, vec2);

    // intersectionInON(vec1, vec2);
    intrsectionBySort(vec1, vec2);
}