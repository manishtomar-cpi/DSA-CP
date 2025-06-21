#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s)
{ //?TIME:(N), SPACE:(1)
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        // push all the open bracket
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }

        // if it is closing bracket
        else
        { // if no open bracket means closing bracket before any closing that should not be valid
            if (st.size() == 0)
                return false;
            char current = st.top(); // the current added open should be the next closed
            st.pop();
            if ((s[i] == ')' && current != '(') ||
                (s[i] == ']' && current != '[') ||
                (s[i] == '}' && current != '{'))
            {
                return false;
            }
        }
    }
}

int main()
{
    string s = "{}";
    cout << isValid(s) << endl;

    return 0;
}