#include <iostream>
#include <vector>
#include <string>
using namespace std;
//!not correct solution
bool isSubsequence(string s, string t)
{
    vector<int> checker;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < t.size(); j++)
        {
            if (s.at(i) == t.at(j))
            {
                checker.push_back(j);
            }
        }
    }

    for (int i = 0; i < checker.size() - 1; i++)
    {
        if (checker[i] > checker[i + 1])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string s = "axc";
    string t = "ahbgdc";
    cout << boolalpha;
    cout << isSubsequence(s, t);

    return 0;
}