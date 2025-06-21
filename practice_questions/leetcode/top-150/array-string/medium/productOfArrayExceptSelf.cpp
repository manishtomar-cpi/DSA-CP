#include <iostream>
using namespace std;
#include <vector>
void display(vector<int> &vec)
{
    cout << "[ ";
    for (auto i : vec)
    {
        cout << i << " ";
    }
    cout << "]" << endl;
}
vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> res;
    if (nums.size() == 0)
    {
        return res;
    }
    vector<int> prefix(nums.size());
    vector<int> postfix(nums.size());
    prefix[0] = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }
    display(prefix);

    postfix[nums.size() - 1] = 1;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        postfix[i] = nums[i + 1] * postfix[i + 1];
    }
    display(postfix);

    for(int i =0;i<nums.size();i++){
        res.push_back(postfix[i]*prefix[i]);
    }
    display(res);

    return res;
}

int main()
{
    vector<int> vec = {1, 2, 3, 4};

    productExceptSelf(vec);

    return 0;
}