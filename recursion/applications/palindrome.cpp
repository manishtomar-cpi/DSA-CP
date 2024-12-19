#include <iostream>
#include <vector>
using namespace std;

bool palindrome(vector<int> &vec, int firstIndex, int lastIndex)
{
    // Base case: if indices have crossed, it's a palindrome
    if (firstIndex >= lastIndex)
    {
        return true;
    }

    // Check if the current elements are not equal
    if (vec[firstIndex] != vec[lastIndex])
    {
        return false;
    }

    // Recursive case: check the inner elements
    return palindrome(vec, firstIndex + 1, lastIndex - 1);
}

int main()
{
    vector<int> vec = {1, 2, 1, 1};

    cout << boolalpha;
    cout << palindrome(vec, 0, vec.size() - 1);

    return 0;
}