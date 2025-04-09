#include <iostream>
#include <unordered_map>
using namespace std;

bool isHappy(int n)
{
    unordered_map<int, int> hash;
    int currentNumber = n; // for holding the sum of squires
    while (true)
    {
        int newNumber = 0; // new number we will get after sum

        // traverse the current number till its became > 0 , when it will became 0 ? -> when it is in single digit and / by 10 is 0.
        while (currentNumber > 0)
        {
            int digit = currentNumber % 10; // give reminder -> 19 %10 =9
            newNumber += (digit * digit); //calculating new number 
            currentNumber /= 10; // give quotient means how many times we can completely divide this number by 10
        }

        //if lucky
        if (newNumber == 1)
        {
            return true;
        }

        //place the new number in hashmap
        hash[newNumber]++;

        //if repeat 
        if (hash[newNumber] > 1)
        {
            break;
        }
        //change current number to new number 
        currentNumber = newNumber;
    }
    return false;
}

/*
  Approach: Detecting a Happy Number using a Hash Map

  -------------------------------
  What is a Happy Number?
  -------------------------------
  A happy number is a number that eventually becomes 1
  when replaced by the sum of the squares of its digits.
  
  Example:
  19 → 1² + 9² = 1 + 81 = 82
  82 → 8² + 2² = 64 + 4 = 68
  68 → 6² + 8² = 36 + 64 = 100
  ?100 → 1² + 0² + 0² = 1 -> Happy Number

  -------------------------------
  Logic Behind This Code:
  -------------------------------
  1. Use a hash map (unordered_map<int, int>) to keep track of numbers we've seen before.
     - This helps us detect cycles (loops).
  2. For the given number `n`, repeat the process:
     a. Take each digit using % 10
     b. Square it and add to a new sum
     c. Remove the last digit using / 10
  3. If the new number becomes 1 → return true (it’s a happy number)
  4. If the number is repeated (seen again in map) → return false (cycle detected)
  5. Repeat the process using the new number as the current number

  -------------------------------
  Key Operators Used:
  -------------------------------
  - `% 10`: Gets the last digit of the number
  - `/ 10`: Removes the last digit from the number
  - `unordered_map`: Tracks how many times each "newNumber" has appeared

  -------------------------------
  !Time Complexity: O(log n)
  - Each time we reduce the number by dividing by 10 while extracting digits
  - We may process the same numbers again, but the cycle length is short

  Space Complexity: O(k)
  - Where k is the number of different numbers we generate before repeating or reaching 1

*/


int main()
{
    int number = 2;
    cout << boolalpha;
    cout << isHappy(number) << endl;

    return 0;
}