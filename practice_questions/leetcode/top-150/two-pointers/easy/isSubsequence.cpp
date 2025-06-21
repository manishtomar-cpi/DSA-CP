#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(string s, string t)
{ //! TIME:O(N), SPACE:O(1)
    if (s.size() == 0)
    { // if first stirng have zero size it should be the subsequence of seocnd one
        return true;
    }
    int j = 0;
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == s[j])
        {
            j++;               // move to next char as we found current
            if (j == s.size()) // we traverse whole string
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    string s = "abc";
    string t = "ahbgdc";

    cout << boolalpha;
    cout << isSubsequence(s, t) << endl;

    return 0;
}