#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 3;
    
    cout << "10 / 3 = " << (a / b) << endl;  // 10 / 3 = 3 (quotient only, no decimal)
    cout << "10 % 3 = " << (a % b) << endl;  // 10 % 3 = 1 (remainder of division)
    
    double x = 10.0, y = 3.0;
    cout << "10.0 / 3.0 = " << (x / y) << endl;  // 10.0 / 3.0 = 3.3333 (normal division)
    
    return 0;
}
/*
  -------------------------------------------
  1. % (Modulus Operator) – Gives the Remainder
  -------------------------------------------
  - % returns the remainder after integer division.
  
  Example:
    int a = 7;
    int b = 3;

    a % b = 1   → because 7 ÷ 3 = 2 remainder 1

  -------------------------------------------
  2. / (Division Operator) – Gives the Quotient
  -------------------------------------------
  - / returns the integer quotient (whole number part of division).
  
  Example:
    int a = 7;
    int b = 3;

    a / b = 2   → because 7 ÷ 3 = 2

  -------------------------------------------
  🍭 Real-Life Analogy:
  -------------------------------------------
  You have 25 candies and want to pack them into boxes of 10:
    25 / 10 = 2  → 2 full boxes
    25 % 10 = 5  → 5 candies left over

  -------------------------------------------
  🔁 Using % and / to Extract Digits:
  -------------------------------------------
  int n = 1234;

  while (n > 0) {
      int digit = n % 10;  // Get the last digit
      n = n / 10;          // Remove the last digit
  }

  Output order: 4 → 3 → 2 → 1

  -------------------------------------------
  ✅ Summary Table:
  -------------------------------------------
  | Operator | Meaning             | Example   | Result |
  |----------|----------------------|-----------|--------|
  |   /      | Integer Division     | 17 / 5    |   3    |
  |   %      | Remainder (Modulus)  | 17 % 5    |   2    |

  -------------------------------------------
  🧠 Used in Happy Number Problems:
  -------------------------------------------
  To get the sum of the squares of each digit:
  
  int n = 19;
  int sum = 0;

  while (n > 0) {
      int digit = n % 10;       // Get last digit
      sum += digit * digit;     // Square and add
      n = n / 10;               // Remove last digit
  }

  For n = 19: 9² = 81, 1² = 1 → sum = 82
*/

