#include <iostream>
#include <vector>
using namespace std;

int func(vector<int> &nums)
{
    // int sign = 1;

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     if (nums.at(i) == 0)
    //     {
    //         return 0;
    //     }
    //     if (nums.at(i) < 1)
    //     {
    //         sign *= -1; // because *-1 in positive 1 means negative -1, on next negative it will became +1;
    //     }
    // }

    // return sign;

//METHOD 2
    int negativeCount = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums.at(i) == 0)
        {
            return 0;
        }
        if (nums.at(i) < 0)
        {
            negativeCount++;
        }
    }
    // if (negativeCount % 2 != 0)
    // {
    //     return -1;
    // }
    // return 1;
     return negativeCount % 2 == 0 ? 1 : -1;
}

int main()
{
    vector<int> vec = {-1, -2, -3, 3, 2, 1};
    cout << func(vec) << endl;
    return 0;
}