#include <iostream>
using namespace std;

int length(char ar[])
{
    if (ar[0] == '\0')
    {
        return 0;
    }
    else
    {
        return length(ar + 1) + 1;
    }
}

int main()
{
    char ar[] = "man";

    cout << length(ar) << endl;

    return 0;
}