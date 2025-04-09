#include <iostream>
#include <string>
#include<unordered_map>
#include<vector>
using namespace std;

/*
    Two strings are isomorphic if characters in 's' can be replaced to get 't',
    with the rules:
    - Each character in 's' must map to one character in 't'
    - No two characters from 's' can map to the same character in 't'
    - The order of characters must be preserved

    Approach:
    - Use two hash maps:
        1. s_to_t: stores mapping from characters in 's' to 't'
        2. t_to_s: stores reverse mapping from 't' to 's'
    - While iterating, check if the mapping is consistent in both directions
    - If a mismatch is found, return false
    - If the entire loop completes without conflict, return true

    !Time Complexity: O(n)
    !Space Complexity: O(k), where k is number of unique characters (usually ≤ 128)
*/

bool isIsomorphic(string s, string t)
{
    unordered_map <int,int> s_to_t;
    unordered_map <int,int> t_to_s;

    for (int i = 0; i < s.size(); i++)
    {
     
        if (s_to_t[t[i]] == 0 && t_to_s[s[i]] == 0)
        {
            s_to_t[s[i]] = t[i];
            t_to_s[t[i]] = s[i];
        }
        else
        {
            if (s_to_t[s[i]] != t[i] || t_to_s[t[i]] != s[i])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    string s = "aa";
    string t = "bb";
    cout << boolalpha;
    cout << isIsomorphic(s, t) << endl;

    return 0;
}