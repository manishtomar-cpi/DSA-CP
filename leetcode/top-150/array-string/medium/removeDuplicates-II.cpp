#include <iostream>
#include <vector>
using namespace std;


/*
It starts by checking if the array size is less than 3, in which case no duplicates need to be removed. It then uses two pointers: 'i' to track the position to insert the next valid element, 
and 'j' to iterate through the array starting from index 2. Since the array is sorted, if the current element at 'j' is not equal to the element at 'i - 2', 
it means we have not yet stored two occurrences of this number, so we copy it to position 'i' and increment 'i'. This ensures that no element appears more than twice. Finally, the function returns 'i', 
which represents the new length of the array after in-place removal of extra duplicates.
*/


int removeDuplicates(vector<int> &nums)
{
    if (nums.size() < 3)
    {
        return nums.size();
    }
    int i = 2;//because we should remove the third one if same 
    for (int j = 2; j < nums.size(); j++)
    {
        if (nums[j] != nums[i - 2])
        { //check the seocnd last if that is same the middle one should also same because array is sorted in assending order.
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}

int main()
{
    vector<int> vec = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    cout << removeDuplicates(vec) << endl;

    return 0;
}
