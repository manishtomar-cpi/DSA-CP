#include <iostream>
#include <string>
using namespace std;

void print_subs(string input, string output)
{
    if (input.size() == 0)
    {
        cout << output << endl;
        return;
    }
     //every char have 2 choices include or exclude
    print_subs(input.substr(1), output); //exclude here //!substr (1) means 'bc'
    print_subs(input.substr(1), output + input[0]); //include here
}
     
int main (){
    string str = "abc";
    string op ="";

    print_subs(str,op);

    return 0;
}