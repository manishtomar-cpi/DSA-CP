#include <iostream>
#include <string>
using namespace std;

/*
---------------------------------------------------------
REVERSE WORDS IN A STRING
---------------------------------------------------------

GOAL:
Given a string 's' with spaces and words, return a new string where:
- Words are in reverse order
- Only one space separates each word
- No leading or trailing spaces

---------------------------------------------------------
ALGORITHM OVERVIEW ( Custom Logic):

1.  Find the first non-space character:
   - Skip leading spaces and get the valid start index

2. Traverse the string backward from the end till valid start index:
   - Add characters to the result string `res`
   - Only add valid characters
   - Skip trailing spaces and extra spaces between words

   3. After building the reverse string:
   - Each word is backward, but word order is correct
   - So we now reverse each word individually to correct it

4. Reversal of each word:
   - Use two pointers (`marker`, `till`)
   - Whenever a space or end is found, reverse the current word
   - Ensure the last word is also reversed using: `i == res.size() - 1`

---------------------------------------------------------
WHY IT WORKS:
- i build the result in reverse while removing unwanted spaces
- Then fix each reversed word using one pass

!TIME COMPLEXITY: O(n)
- Each character is processed at most twice (once in building, once in reversing)

!SPACE COMPLEXITY: O(n)
- Output string `res` holds the final result

---------------------------------------------------------
*/

string reverseWords(string s)
{
    bool flag = false;
    string res = "";
    int startIndex = -1;

    // first found the valid start index
    for (int i = 0; i < s.size(); i++)
    {
        startIndex = i;
        if (s[i] != ' ')
        {
            break;
        }
    }

    // now traverse the string from back and add valid chars in res
    for (int i = s.size() - 1; i >= startIndex; i--)
    {
        // when encounter ' ' means the next word
        if (s[i] != ' ')
        {
            flag = true;
        }
        if (flag)
        {
            if (s[i] == ' ')
            { // the ending of current word
                flag = false;
            }

            res += s[i];
        }
    }
    // now swapping
    int marker = 0;
    int till = 0;
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i] == ' ' || i == res.size() - 1)
        { // why i == res.size()-1 because at the end we dont have ' ' so we also need to swap that word
            i < res.size() - 1 ? till = i - 1 : till = i;
            while (marker < till)
            {
                swap(res[marker++], res[till--]);
            }
            marker = i + 1;
        }
    }
    return res;
}

int main()
{
    string str = "  hello world  ";

    cout << reverseWords(str) << endl;

    return 0;
}