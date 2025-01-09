#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

string removeDuplicates(string s)
{
    stack<char> s1;
    string orignal = "";
    if (s.size() == 0)
    {
        return orignal;
    }
    else
    {
        s1.push(s[0]); //insert first element 
        int i = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (!s1.empty() && s[i] == s1.top())
            { // we take empty condition because at some case stack could became empty
                s1.pop();
            }
            else
            {   //if top not equal to the current element then push it into stack
                s1.push(s[i]);
            }
        }
    }
    while (!s1.empty())
    {   //now making orignal what is in the stack that os not duplicate
        orignal = s1.top() + orignal; //making top in front because the last is the first in the stack and we can't chnage the order 
        s1.pop();
    }
    return orignal;
}

int main()
{
    string str = "abbaca";
    cout << removeDuplicates(str) << endl;

    return 0;
}
