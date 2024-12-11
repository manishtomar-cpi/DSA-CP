#include <iostream>
#include <string>
#include <vector>
using namespace std;

void stringBasic()
{
    string s = "hello";
    cout << s << endl;

    string *sp = new string;

    *sp = "hello world";
    cout << sp << endl;  // address where sp is stored
    cout << *sp << endl; // de-reference the string
}

void takingInputAsSpace()
{
    string str;
    getline(cin, str); // means we can take input as space as well; -> hello world
    cout << str << endl;
}

void operations()
{
    string s1 = "hello";
    string s2 = "world";

    string s3 = s1 + s2; // concat
    cout << s3 << endl;  // hello world

    s3 = s3 + " we are here" + " mze aare hai";
    cout << s3 << endl; // hello world we are here mze aare hai
    //*we can use push_back also in string 
    //! SUBSTR
    string s4 = "hell0";
    cout << s4.substr(2);    // it will give the s4 -> starting from index 2 ->  llo
    cout << s4.substr(2, 2); // means start from index 2 and give me 2 chars //ll

    //! FIND
    string s5 = "defgtfabcgrfabc";
    s5.find("abc"); // return the int from where a is start means first find 'abc' then return the index of a -> 6

    //! convert int to str
    int a = 123;
    string s6 = to_string(a);
    cout << s6 << endl; //123 as string 

    //!string to int 
    int a = stoi(s6); //123 as int 
}

int main()
{
    stringBasic();
    // takingInputAsSpace();
    operations();
    return 0;
}