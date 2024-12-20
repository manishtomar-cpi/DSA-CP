#include <iostream>
#include <string>
using namespace std;

int stoi(string str, int size)
{
    if (size == 0)
    {
        return 0;
    }
    int smallAnswer = stoi(str, size - 1);
    int lastDigit = str[size - 1] - '0';       // means if we have 5 then 5-0in (ASCII) is 5
    int answer = smallAnswer * 10 + lastDigit; // means ladt digit ko int ki equal leke aaye in above step then 10 ki guna krke acctual digit bna li
    return answer;
}

int stoiFor(string str)
{
    cout << sizeof(str) << " before" << endl;

    int ans = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int digit = str[i] - '0'; //convert into digit
        ans = ans * 10 + digit; //add in to answer 
    }
    cout << sizeof(ans) << " after" << endl;

    return ans;
}

int main()
{
    string str = "549867";
    int size = str.size();

    // cout << stoi(str, size) << endl;
    cout << stoiFor(str);
    return 0;
}
