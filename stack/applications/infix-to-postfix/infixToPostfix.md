# Infix to Postfix Conversion using Stack in C++

## Introduction
The conversion of an infix expression to a postfix expression is a fundamental concept in computer science, particularly in the domain of compilers and expression evaluation. Infix expressions are the standard arithmetic expressions that we write, such as `A + B`, where operators are placed between operands. However, infix expressions are not easy for machines to evaluate due to the need for operator precedence and associativity rules.

Postfix expressions, also known as Reverse Polish Notation (RPN), place operators after their operands, making them easier for computers to evaluate as they eliminate the need for parentheses and precedence rules. For example, the postfix form of `A + B * C` is `A B C * +`.

## Algorithm for Conversion
To convert an infix expression to a postfix expression, the following steps are used:

### 1. Define Precedence
Each operator has a precedence level, which determines the order in which operations are performed. For example:
- `*` and `/` have higher precedence than `+` and `-`.
- Parentheses `(` and `)` are used to override precedence.

### 2. Use a Stack
A stack is used to temporarily hold operators and parentheses during the conversion process.

### 3. Traverse the Infix Expression
For each character in the infix expression:
1. **Operand**: Append it directly to the postfix expression.
2. **Left Parenthesis (`(`)**: Push it onto the stack.
3. **Right Parenthesis (`)`)**: Pop operators from the stack and append them to the postfix expression until a left parenthesis is encountered. Discard the left parenthesis.
4. **Operator**: Pop operators from the stack with higher or equal precedence and append them to the postfix expression. Then push the current operator onto the stack.

### 4. Pop Remaining Operators
After traversing the infix expression, pop all remaining operators from the stack and append them to the postfix expression.

## Example
### Input
Infix expression: `A + B * (C - D)`

### Output
Postfix expression: `A B C D - * +`

## Implementation in C++
Below is the complete implementation of the infix to postfix conversion in C++ using a stack:

```cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to check if the character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (char c : infix) {
        // If the character is an operand, add it to the output
        if (isalnum(c)) {
            postfix += c;
        }
        // If the character is '(', push it to the stack
        else if (c == '(') {
            s.push(c);
        }
        // If the character is ')', pop and output from the stack until '(' is found
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(')
                s.pop();
        }
        // If the character is an operator
        else if (isOperator(c)) {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // Pop all remaining operators from the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
```

## Explanation of Code
1. **Precedence Function**: Determines the precedence level of operators (`+`, `-`, `*`, `/`).
2. **isOperator Function**: Checks if a character is an operator.
3. **infixToPostfix Function**:
   - Loops through each character in the infix string.
   - Adds operands directly to the postfix string.
   - Uses a stack to handle operators and parentheses.
   - Ensures operators are added to the postfix string in the correct order based on precedence.
4. **Main Function**:
   - Accepts an infix expression as input from the user.
   - Converts it to postfix using the `infixToPostfix` function.
   - Displays the resulting postfix expression.

## Example Execution
### Input
```
Enter an infix expression: A+B*(C-D)
```

### Output
```
Postfix expression: ABCD-*+
```

## Time Complexity
The time complexity of this algorithm is **O(n)**, where `n` is the length of the infix expression. Each character is processed once during the traversal.

## Space Complexity
The space complexity is **O(n)** due to the stack used to store operators and parentheses.

## Advantages of Postfix Expressions
1. Eliminate the need for parentheses.
2. Simplify the evaluation process.
3. Can be evaluated using a stack-based algorithm.

By using this approach and the provided code, you can effectively convert any valid infix expression into its postfix equivalent.
