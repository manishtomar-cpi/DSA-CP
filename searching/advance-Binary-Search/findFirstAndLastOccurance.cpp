#include <iostream>
#include <vector>
using namespace std;

void binarySearch(vector<int> &nums, int target)
{
    int start = 0;
    int end = nums.size() - 1;
    int mid = (start + end) / 2;
    int first = -1;
    int last = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[mid] == target)
        {
            first = mid;
            end=mid-1;
            mid = (start + end) / 2;
        }
        if (nums[mid] < target)
        {
            start = mid + 1;
            mid = (start + end) / 2;
        } 
        if (nums[mid] > target)
        {
            end = mid - 1;
            mid =(start + end) / 2;
        }
    }

    start = 0;
    end = nums.size() - 1;
    mid = (start + end) / 2;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[mid] == target)
        {
            last = mid;
            start=mid+1;
            mid = (start + end) / 2;
        }
        if (nums[mid] < target)
        {
            start = mid + 1;
            mid = (start + end) / 2;
        } 
        if (nums[mid] > target)
        {
            end = mid - 1;
            mid =(start + end) / 2;
        }
    }


    cout << "first: " <<  first << endl;
    cout << "last: " <<  last << endl;
}
int findOcc(vector<int> &vec, int num)
{
    bool flag = false;
    int first = -1;
    int last = -1;

    for (int i = 0; i < vec.size(); i++)
    {
        if (flag)
        {
            if (vec[i] == num)
            {
                last++;
                continue;
            }
            if (vec[i] != num)
            {
                break;
            }
        }
        if (vec[i] == num)
        {
            first = i;
            last = first;
            flag = true;
        }
    }
    cout << "first occ: " << first << endl;
    cout << "last occ: " << last << endl;
}

int main()
{
    vector<int> vec = {5,7,7,8,8,10};
    // findOcc(vec, 5);
    binarySearch(vec,7);

    return 0;
}