#include <stack>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isOperator(string c)
{ // tell if the current string is operator or not
    if (c == "/" || c == "+" || c == "-" || c == "*")
    {
        return true;
    }
    return false;
}
int operation(int first, int second, string oper)
{ // if it will operator the  we will do calculation
    int orignal = INT_MIN;
    if (oper == "/")
    {
        orignal = second / first; //! if '/' means second will devide by first in 4/2 -> postfix is 42/ in stack they will store -> [4,2] then first is 2 seocnd is 4 thats why second/first
        return orignal;
    }
    if (oper == "+")
    {
        orignal = first + second;
        return orignal;
    }
    if (oper == "-")
    {
        orignal = second - first; //! same as divide
        return orignal;
    }
    if (oper == "*")
    {
        orignal = first * second;
        return orignal;
    }
}
/*
  Approach:
  - Use a stack to simulate evaluation of a postfix expression.
  - Loop through each token in the input:
      - If the token is a number, push it onto the stack.
      - If the token is an operator (+, -, *, /):
          - Pop the top two elements from the stack.
          - Apply the operator using a helper `operation()` function.
          - Push the result back onto the stack.
  - After processing all tokens, the stack contains one element — the final result.

  Functions:
  - `isOperator()` checks if the current token is an arithmetic operator.
  - `operation(a, b, op)` performs the required operation (b op a).
     Note: second is popped before first → apply as: second <op> first

  !Time Complexity:
  - O(n), where n is the number of tokens

  !Space Complexity:
  - O(n), for the stack used during evaluation

  Example:
    Input: ["2", "1", "+", "3", "*"]
    Step-by-step:
      1. Push 2
      2. Push 1
      3. '+' → Pop 1, 2 → 2+1 = 3 → Push 3
      4. Push 3
      5. '*' → Pop 3, 3 → 3*3 = 9 → Push 9
      → Result: 9
*/
int evalRPN(vector<string> &tokens)
{
    if (tokens.size() == 1)
    { // edge case
        return stoi(tokens[0]);
    }
    int orignal = INT_MAX;
    stack<string> st;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (!isOperator(tokens[i]))
        { // push all the digits
            st.push(tokens[i]);
        }
        else
        {

            int first = stoi(st.top()); //! stoi take O(k) time where k is number of digits in the number ~ O(1)
            st.pop();
            int second = stoi(st.top());
            st.pop();
            int calculation = operation(first, second, tokens[i]);
            st.push(to_string(calculation)); //! same as stoi
        }
    }
    return stoi(st.top());
}

int main()
{
    vector<string> str = {"2", "1", "+", "3", "*"};
    cout << evalRPN(str) << endl;

    return 0;
}