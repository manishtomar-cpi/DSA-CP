#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle)
{
    for (int i = 0; i < haystack.size(); i++)
    {
        bool flag = false; // use to detect the starting char of the neelde
        if (haystack[i] == needle[0] &&
            i <= (haystack.size() - needle.size()))
        {                // found the first char but the index in haystack should be in range of the needle that's why  //! i <= (haystack.size() - needle.size())
            flag = true; // turn flag true
            for (int j = 0; j < needle.size(); j++)
            {
                if (haystack[i + j] != needle[j])
                { // if any step the the chars b/w them not matching
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
        { // only when the seocnd loop runs completly
            return i;
        }
    }
    return -1;
}

int main()
{
    string haystack = "sadbutsad";
    string needle = "sad";

    cout << strStr(haystack, needle) << endl;

    return 0;
}