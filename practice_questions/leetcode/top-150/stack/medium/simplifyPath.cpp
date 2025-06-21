#include <string>
#include <iostream>
#include <stack>
using namespace std;
/*
Simplify Unix File Path – Manual Parsing Approach

Goal:
Given a Unix-style absolute file path, return its simplified canonical form by removing:
- Single dots (.) representing the current directory
- Double dots (..) representing the parent directory
- Extra slashes (//, ///)

Approach (Manual Parsing without stringstream):
1. Traverse the string character by character.
2. Build each path segment (folder/file name) manually into a temporary string `str`.
3. When a slash `'/'` is encountered:
   - If `str` is ".." → pop from the stack (go to parent directory)
   - If `str` is valid (not ".", "..", empty) → push it onto the stack (go into that directory)
   - Reset `str` to prepare for the next segment

4. After the loop, handle the last token (if the path didn’t end with a slash):
   - Repeat the same rules to either push or skip

5. Build the final path by combining all entries in the stack with a single `/` separator.

Example:
Input: "/home//foo/../bar/"
Stack: ["home", "bar"]
Output: "/home/bar"

Notes:
- This approach manually parses the path without using extra STL functions like stringstream.
- Handles edge cases like:
  - Trailing slash ("/home/")
  - Root path only ("/../" → "/")
  - Dots and empty segments ("/a/./b/..")

?Time Complexity: O(n)
?Space Complexity: O(n)
Where n is the length of the input path
*/

string simplifyPath(string path)
{
    string str = ""; // for storing one dir name
    stack<string> s1;
    for (int i = 0; i < path.size(); i++)
    {
        // when get dir name's char
        if (path[i] != '/')
        {
            str += path[i];
        }
        // if encounter next '/' means one dir name complete
        else if (path[i] == '/')
        {
            cout << "str: " << str << endl;
            if (str == "..")
            { // then we will go one directory back that's why pop
                if (!s1.empty())
                {
                    s1.pop();
                }
            } // apply all filter and if dir name pass all then push into stack
            if (str != "." && str != "" && str != "..")
            {
                s1.push(str);
            }
            str = "";
        }
    }
    // cout << str << " str after loop" << endl;
    // cout << str.size() << endl;

    // at the end last dir name should left if it is .. the  pop the last entered directory name
    if (str == "..")
    {
        if (!s1.empty())
        {
            s1.pop();
        }
        str = "";
    }
    // if it genuine dir name then store it in stack
    if (str != "/" && str != "." && str != "" && str != " ")
    {
        s1.push(str);
    }
    str = "";
    cout << s1.size() << " stack size" << endl;
    if (s1.empty())
    { //? edge case :- if stack empty means we are in root dir
        return "/";
    }
    while (!s1.empty())
    {
        cout << s1.top() << endl;
        str = "/" + s1.top() + str; // making the path example in stack [foo,home] -> /foo then /home/foo
        s1.pop();
    }
    return str;
}
int main()
{
    string str = "/..";
    cout << simplifyPath(str) << endl;

    return 0;
}