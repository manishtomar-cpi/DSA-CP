#include <iostream>
#include <string>
using namespace std;

void replace(char ar[])
{
    if (ar[0] == '\0')
    {
        return;
    }
    if (ar[0] == 'a')
    {
        ar[0] = 'x';
    }
    return replace(ar + 1);
}

int main()
{
    char ar[] = "a";

    replace(ar);

    cout << ar << endl;

    return 0;
}