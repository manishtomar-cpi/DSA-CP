#include <iostream>
#include <string>
using namespace std;

void printString(string str)
{
    static int i = 0;
    if (str.size() == 0)
    {
        return;
    }
    if (i == str.size())
    {
        return;
    }
    else
    {
        cout << str[i] << " ";
        i++;
        return printString(str);
    }
}

void reversePrint(char str[])
{
    if (str[0] == '\0')
    {
        return;
    }
    reversePrint(str + 1);
    cout << str[0] << " ";
}

int main()
{
    string str = "manish";
    // printString(str);

    char str1[] = "manush";
    reversePrint(str1);
    return 0;
}