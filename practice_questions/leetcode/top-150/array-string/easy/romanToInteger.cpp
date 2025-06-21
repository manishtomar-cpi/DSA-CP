#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> hash =
        {{'I', 1},
         {'V', 5},
         {'X', 10},
         {'L', 50},
         {'C', 100},
         {'D', 500},
         {'M', 1000}};

    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'I' && i < s.size() - 1)
        {
            if (s[i + 1] == 'V')
            {
                sum += 4;
                i++;
            }
            else if (s[i + 1] == 'X')
            {
                sum += 9;
                i++;
            }
            else
            {
                sum += hash[s[i]];
            }
        }
        else if (s[i] == 'X' && i < s.size() - 1)
        {
            if (s[i + 1] == 'L')
            {
                sum += 40;
                i++;
            }
            else if (s[i + 1] == 'C')
            {
                sum += 90;
                i++;
            }
            else
            {
                sum += hash[s[i]];
            }
        }
        else if (s[i] == 'C' && i < s.size() - 1)
        {
            if (s[i + 1] == 'D')
            {
                sum += 400;
                i++;
            }
            else if (s[i + 1] == 'M')
            {
                sum += 900;
                i++;
            }
            else
            {
                sum += hash[s[i]];
            }
        }
        else
        {
            sum += hash[s[i]];
        }
    }
    return sum;
}
int main()
{
    string str = "MCMXCIV";
    cout << romanToInt(str) << endl;

    return 0;
}