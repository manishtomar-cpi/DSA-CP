#include <iostream>
#include <string>
using namespace std;

int sizeOfLastword(string s)
{
    int count = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if ((s.at(i) == 32 && count == 0))
        {
            continue;
        }
        if (s.at(i) == 32 && count > 0)
        {
            return count;
        }
        if (s.at(i) != 32)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    string s = "hello world      b gh dd sss   tgyt ";
    cout << sizeOfLastword(s) << endl;

    return 0;
}