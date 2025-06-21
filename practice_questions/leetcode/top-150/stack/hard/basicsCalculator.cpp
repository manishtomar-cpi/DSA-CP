#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

//for to_postfix
bool isOperand_char(char c)
{
    if (c >= '0' && c <= '9')
    {
        return true;
    }
    return false;
}

//for to_postfix
bool isOperator_char(char c)
{
    if (c == '/' || c == '*' || c == '+' || c == '-')
    {
        return true;
    }
    return false;
}

//for calculate
bool isOperand(string c)
{
    if (c >= "0" && c <= "9")
    {
        return true;
    }
    return false;
}

//for calculate
bool isOperator(string c)
{
    if (c == "/" || c == "*" || c == "+" || c == "-")
    {
        return true;
    }
    return false;
}

//tell preference - and + are same  and * and / are same but higher then + and -
int pre(char c)
{
    if (c == '-' || c == '+')
    {
        return 1;
    }
    if (c == '/' || c == '*')
    {
        return 2;
    }
}

void display(vector<string> &vec)
{
    cout << "[ " <<endl;
    for (auto i : vec)
    {
        cout << i << endl;
    }
    cout << "]" << endl;
}

//converting to postfix first
vector<string> toPostfix(string s)
{
    string converted = ""; //used for storing the current traversing string
    stack<char> s1; //for pri when add which operator 
    vector<string> vec;//format the strong to genuine values like if we have "1234+65" in vector will store [1234,+,65]
    for (int i = 0; i < s.size(); i++)
    {
        if (isOperand_char(s[i]))
        {
            //when we get only numeric
            converted += s[i];
        }
        if (isOperator_char(s[i]))
        {
            //when encounter operation
            vec.push_back(converted); //push the number we got
            converted = "";//make converted empty for next value
            if (s1.empty())
            {
                //push operator in stack first
                s1.push(s[i]);
            }
            else
            {
                //check pre 
                if (pre(s1.top()) >= pre(s[i]))
                {
                    //if greater or equal then
                    converted += s1.top(); //add the lesser one first
                    vec.push_back(converted);//push the operator in the vector
                    converted = "";
                    s1.pop();//pop because we added that
                    s1.push(s[i]);//push the new one
                }
                else
                {
                    s1.push(s[i]);
                }
            }
        }
    }
    vec.push_back(converted); //if we have 25+26*27 -> 27 left because no operator after 27 thats why add that as well
    while (!s1.empty()) //if some operators are in the stack remaining
    {
        converted = "";
        converted += s1.top();
        vec.push_back(converted);
        s1.pop();
    }
    display(vec);
    cout << "size: " << vec.size() << endl;
    return vec;
}

int operation(int first, int second, string c)
{
    if (c == "+")
    {
        return first + second;
    }
    if (c == "*")
    {
        return first * second;
    }
    if (c == "-")
    {
        return second - first;
    }
    if (c == "/")
    {
        return second / first;
    }
    return -1;
}

int calculate(string s)
{
    vector<string> converted = toPostfix(s);
    stack<int> s1;
    if (converted.size() == 1)
    {//edge
        return stoi(converted[0]);
    }
    for (int i = 0; i < converted.size(); i++)
    {
        //push the digits in stack
        if (isOperand(converted[i]))
        {
            s1.push(stoi(converted[i]));
        }
        //when found operators
        if (isOperator(converted[i]))
        {
            int first = s1.top();
            s1.pop();
            int second = s1.top();
            s1.pop();
            //calculate answer accordingly
            int answer = operation(first, second, converted[i]);
            s1.push(answer);
        }
    }
    return s1.top();
}

/*
Expression Evaluator using Infix to Postfix Conversion

Goal:
Evaluate a valid math expression string like "3 + 5 * 2 - 8" and return the correct result.

Simple Steps of the Approach:

1. Convert the infix expression (normal math) to postfix (Reverse Polish Notation):
   - Traverse the string one character at a time.
   - Store full numbers (e.g., "123") and ignore spaces.
   - Use a stack to handle operator precedence (* and / before + and -).
   - Output a vector of tokens in postfix order (e.g., ["3", "5", "2", "*", "+", "8", "-"]).

2. Evaluate the postfix expression:
   - Use a stack to process the postfix tokens.
   - Push numbers into the stack.
   - When you find an operator, pop the top two numbers, apply the operator, and push the result back.
   - Final result is the only value left in the stack.

?Works Perfectly For:
- Multi-digit positive numbers
- Expressions with +, -, *, /
- Handles operator precedence correctly (e.g., * and / happen before + and -)

!Limitation:
- Unary minus (e.g., "-2" or "1 - (-3)") is not supported — current logic treats '-' only as a binary operator.

Time Complexity: O(n)
Space Complexity: O(n)
*/


int main()
{
    string str = "(1+(4+5+2)-3)+(6+8)";
    cout << calculate(str) << endl;

    return 0;
}