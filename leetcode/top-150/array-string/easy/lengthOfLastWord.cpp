#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s)
{ //! TIME : O(N), SPACE: O(1)
    bool flag = false;
    int count = 0;
    int i = s.size() - 1; // because we will loop from end

    while (i >= 0)
    {
        // when we meet the last char of the last word
        if (s[i] != ' ')
        {
            flag = true;
        }

        // if we traversed the last word
        if (flag && s[i] == ' ')
        {
            return count;
        }

        // when we traversing the last word
        if (flag)
        {
            count++;
        }
        i--;
    }
    return count;
}

int main()
{
    string str = "    my  name is     manish    tomarr   ";
    cout << lengthOfLastWord(str) << endl;

    return 0;
}