#include <iostream>
#include <stack>
#include <string>
using namespace std;

void displayStack(stack<char> st)
{
    while (!st.empty())
    {
        // cout << st.top() << endl;
        st.pop();
    }
}

string simplifyPath(string path)
{
    stack<char> st;
    stack<char> output;
    string op = "/";
    if (path.size() == 1)
    {
        return op;
    }
    for (int i = 0; i < path.size(); i++)
    {
        st.push(path[i]);
        cout << st.top() << endl;
    }
    while (!st.empty())
    {
        char current = st.top();
        st.pop();
        bool flag = false;
        string cr = "";
        while (current != '/' && !st.empty())
        {
            if (!flag)
            {
                output.push(current);
                cr += current;
                current = st.top();
                st.pop();
            }
            if (current == '/')
            {
                output.push(current);
            }
        }
        if (cr == ".")
        {
            output.pop();
        }
        if (cr == "..")
        {
            flag = true;
            continue;
        }
        flag = false;
        cr = "";
    }
    char check = output.top();
    while (check == '/' || check =='.')
    {
        output.pop();
        check = output.top();
    }
    while (!output.empty())
    {
        op += output.top();
        output.pop();
    }
    return op;
}

int main()
{
    string str = "/.../a/../b/c/../d/./";
    cout << simplifyPath(str) << endl;

    return 0;
}