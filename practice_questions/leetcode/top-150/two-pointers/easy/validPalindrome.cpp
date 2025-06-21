#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s)
{
    string orignal = "";
    for (int i = 0; i < s.size(); i++)
    {
        // Filtered only alphanumeric characters
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9'))
        {
            // Converted to lowercase before storing
            orignal += tolower(s[i]);
        }
    }
    int i = 0;
    int j = orignal.size() - 1;
    // Two-pointer palindrome check
    while (i < j)
    {
        if (orignal[i] != orignal[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main()
{
    string str = "A man, a plan, a canal: Panama";
    cout << boolalpha;
    cout << isPalindrome(str) << endl;

    return 0;
}