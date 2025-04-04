#include <string>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <set>
using namespace std;

int lengthOfLongestSubstring(string s)
{ //! TIME: O(n²) -> tring slicing and rebuilding using + and substr or loops is costly — it takes extra time, making approach O(n²) in the worst case.
    if (s.size() == 0)
    {
        return 0;
    }
    unordered_map<int, int> hash;
    string str = "";
    int len = 0;
    int j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (hash[s[i]] != 0)
        {
            int currentLen = str.size();
            bool flag = false;
            string sliced = "";
            if (currentLen > len)
            {
                len = str.size();
            }
            for (int j = 0; j < str.size(); j++)
            {
                if (!flag)
                {
                    hash[str[j]]--;
                    if (str[j] == s[i])
                    {
                        flag = true;
                        continue;
                    }
                }
                if (flag)
                {
                    sliced += str[j];
                }
            }
            str = sliced;
        }
        str += s[i];
        hash[s[i]]++;
    }
    return len < str.size() ? str.size() : len;
}

/*
    Sliding Window Approach (O(n) Time Complexity):

    Strategy:
    - Use two pointers: 'left' and 'right' to define the current window of unique characters.
    - Use an unordered_set 'seen' to track the characters currently in the window.
    - Expand the window by moving 'right', and shrink it by moving 'left' if a duplicate is found.

    Steps:
    1. Initialize left = 0, right = 0, maxLen = 0
    2. While 'right' hasn't reached the end of the string:
       a. If s[right] is not in the 'seen' set:
          - Add it to the set
          - Update maxLen if the current window is larger
          - Move 'right' one step forward
       b. If s[right] is already in the set (duplicate):
          - Remove s[left] from the set (shrink the window from the left)
          - Move 'left' one step forward
    3. Return the maximum length found

    !Time Complexity: O(n)
    !Space Complexity: O(k), where k is the number of unique characters (at most 128 for ASCII)
    */
int lengthOfLongestSubstring_sliding(string s)
{
    int left = 0;
    int right = 0;
    int maxLen = 0;
    set<char> hash;

    //traverse the string till last 
    while (right < s.size())
    {
        //if not found add that
        if (hash.find(s[right]) == hash.end())
        {
            hash.insert(s[right++]);
            maxLen = max(maxLen, right - left + 1);
        }
        //if found erase (shrink the window) till we get all unique, logic is same as slicing but here we are processign the pointer left and right 
        else
        {
            hash.erase(s[left++]);
        }
    }
    return maxLen;
}
int main()
{
    string str = "tmmzuxt";
    cout << lengthOfLongestSubstring(str) << endl;

    return 0;
}