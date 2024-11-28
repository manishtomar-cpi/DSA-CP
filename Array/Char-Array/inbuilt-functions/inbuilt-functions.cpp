#include <iostream>
#include <cstring>

using namespace std;

void myStrLen(char arr[])
{
    cout << "==========LEN============" << endl;

    cout << "$$$$INBUILT$$$$$$$$$$$" << endl;
    cout << "length of the string is " << strlen(arr) << endl; // length of the passed string
}

void myStrCmp(char str1[], char str2[])
{
    cout << "===========CMP===========" << endl;

    // cout << "$$$$INBUILT$$$$$$$$$$$" << endl;
    // if (strcmp(str1 , str2) == 0)
    // {
    //     cout << "equal" << endl;
    // }
    // else
    // {
    //     cout << "not equal" << endl;
    // }
    cout << "$$$$WRITTEn$$$$$$$$$$$" << endl;

    if (strlen(str1) != strlen(str2))
    {
        cout << "not equal" << endl;
    }
    for (int i = 0; i < strlen(str1); i++)
    {
        if (str1[i] != str2[i])
        {
            cout << "not equal" << endl;
            break;
            return;
        }
    }
    cout << "equal" << endl;
}

void myStrCpy(char str1[], char str2[])
{
    cout << "===========CPY===========" << endl;

    cout << "$$$$INBUILT$$$$$$$$$$$" << endl;
    cout << "before " << endl;
    cout << "str1:" << " " << str1 << endl; // man
    cout << "str2:" << " " << str2 << endl; // mas
    strcpy(str1, str2);                     // str1 became str2, size does not matter here
    cout << "after " << endl;
    cout << "str1:" << " " << str1 << endl; // mas
    cout << "str2:" << " " << str2 << endl; // mas
}

void myStrnCpy(char str1[], char str2[])
{
     cout << "===========NCPY===========" << endl;

    cout << "$$$$INBUILT$$$$$$$$$$$" << endl;
    cout << "before " << endl;
    cout << "str1:" << " " << str1 << endl; // man
    cout << "str2:" << " " << str2 << endl; // mas
    strncpy(str1, str2, 1);                     // str1 became str2 till 3, size does not matter here
    cout << "after " << endl;
    cout << "str1:" << " " << str1 << endl; // mas
    cout << "str2:" << " " << str2 << endl; // mas   
}

void myStrCat()
{
}

int main()
{
    char arr[100] = "man";
    char str1[100] = "man";
    char str2[100] = "ma";
    // myStrCat();
    // myStrLen(arr);

    // myStrCmp(str1, str2);
    // myStrCpy(str1, str2);
    myStrnCpy(str1, str2);
}