#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printPrifix(string s)
{
    // BF
    //  for (int i = 0; i < s.size(); i++)
    //  {
    //      for (int j = 0; j <=i; j++)
    //      {
    //          cout << s.at(j);
    //      }
    //      cout << endl;
    //  }

    // TWO POINTER
    //  int i =0;
    //  int j =0;

    // while(i<s.size()){
    //     if (j<=i){
    //         cout << s.at(j);
    //     }
    //     if(j==i){
    //         i++;
    //         j=0;
    //         cout << endl;
    //         continue;
    //     }
    //     j++;
    // }

    // SINGLE FOR LOOP
    string str = "";
    for (int i = 0; i < s.size(); i++)
    {
        str += s.at(i);
        cout << str << endl;
    }
}

int main()
{
    string s = "abcdefg";

    printPrifix(s);
    return 0;
}