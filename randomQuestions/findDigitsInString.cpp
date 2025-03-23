#include <iostream>
#include <string>
using namespace std;

int stringToInt(string str)
{
    string res = "";
    if (str.size() == 0)
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < str.size(); i++)
        {
            int check = str[i] - 'a';
            if (check < 0 || check > 25)
            {
                res += str[i];
            }
        }
    }
    // cout << res << endl;
    // return 0;

    //?Method1: typecasting
    // int ans = stoi(res);
    // return ans;

    // Method2: without using inbuilt function
    int num = 0;
    for (int i = 0; i < res.size(); i++)
    {
        int current = (res[i] - '0') % 10; // convert current car to number(int)
        num = (num *= 10) + current;
    }
    return num;
}

int main()
{
    string str = "ab12nb65kl";

    cout << stringToInt(str) << endl;

    return 0;
}