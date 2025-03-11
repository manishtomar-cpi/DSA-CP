#include <iostream>
#include <vector>
#include <string>
using namespace std;
int LCS_Helper(string first, int firstMatchingIndex, string second, int secondMatchingIndex)
{

    // the base case //? when we reach at the end of any string
    if (firstMatchingIndex == first.length() || secondMatchingIndex == second.length())
    {
        return 0;
    }
    // if both index match
    if (first[firstMatchingIndex] == second[secondMatchingIndex])
    {
        return 1 + (LCS_Helper(first, firstMatchingIndex + 1, second, secondMatchingIndex + 1)); //? if match both then add one becauee the lenght shoyuld increae and check for rest strings that's why added 1 in indexes
    }
    
    // not match the current indexes
    //? then we move forward from another string and match with the existing one of first and then take maximum from both
    return max(LCS_Helper(first, firstMatchingIndex + 1, second, secondMatchingIndex), LCS_Helper(first, firstMatchingIndex, second, secondMatchingIndex + 1));
}

int LCS(string first, string second)
{
    return LCS_Helper(first, 0, second, 0); //?why zero->because starting from first char
}

int main()
{
    cout << LCS("abcde", "ace") << endl;

    return 0;
}
