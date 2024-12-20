# Generating Subsequences of a String Using Recursion

## Problem Statement

Given a string, generate all possible subsequences (or subsets) of that string. A subsequence is defined as a sequence derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

### Example

For the string `"abc"`, the subsequences are:
```
"", "a", "b", "c", "ab", "ac", "bc", "abc"
```

## Approach

The problem can be solved using recursion. At every step, we decide whether to include or exclude the current character from the subsequence.

### Steps in the Algorithm

1. Base Case: 
   - If the input string becomes empty, print the current output string and return.

2. Recursive Case:
   - Exclude the first character of the input string and make a recursive call.
   - Include the first character of the input string in the output and make another recursive call.

### Code Implementation

```cpp
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
     // Every character has 2 choices: include or exclude
    print_subs(input.substr(1), output); // Exclude here
    print_subs(input.substr(1), output + input[0]); // Include here
}

int main (){
    string str = "abc";
    string op ="";

    print_subs(str,op);

    return 0;
}
```

## Detailed Explanation of Recursion Tree with Steps

Here is a detailed explanation of the recursion process for the input string `"abc"`:

### Step 1: Process the First Character `a`

- Input: `"abc"`, Output: `""`
  - Option 1 (Exclude `a`): Call `print_subs("bc", "")`
  - Option 2 (Include `a`): Call `print_subs("bc", "a")`

Tree after Step 1:
```
          ""
         /   \
      ""     "a"
```

### Step 2: Process the Second Character `b`

#### For Exclude `a` (Input: `"bc"`, Output: `""`):
  - Option 1 (Exclude `b`): Call `print_subs("c", "")`
  - Option 2 (Include `b`): Call `print_subs("c", "b")`

#### For Include `a` (Input: `"bc"`, Output: `"a"`):
  - Option 1 (Exclude `b`): Call `print_subs("c", "a")`
  - Option 2 (Include `b`): Call `print_subs("c", "ab")`

Tree after Step 2:
```
          ""
         /   \
      ""     "a"
     /  \    /   \
   ""   "b" "a"  "ab"
```

### Step 3: Process the Third Character `c`

#### For Exclude `b` (Input: `"c"`, Output: `""`):
  - Option 1 (Exclude `c`): Call `print_subs("", "")`
  - Option 2 (Include `c`): Call `print_subs("", "c")`

#### For Include `b` (Input: `"c"`, Output: `"b"`):
  - Option 1 (Exclude `c`): Call `print_subs("", "b")`
  - Option 2 (Include `c`): Call `print_subs("", "bc")`

#### For Exclude `b` with Include `a` (Input: `"c"`, Output: `"a"`):
  - Option 1 (Exclude `c`): Call `print_subs("", "a")`
  - Option 2 (Include `c`): Call `print_subs("", "ac")`

#### For Include `b` with Include `a` (Input: `"c"`, Output: `"ab"`):
  - Option 1 (Exclude `c`): Call `print_subs("", "ab")`
  - Option 2 (Include `c`): Call `print_subs("", "abc")`

Tree after Step 3:
```
                ""
         /               \
      ""                  "a"
     /  \              /       \
   ""   "b"         "a"        "ab"
  / \   /  \       /   \      /    \
"" "c" "b" "bc"  "a"  "ac"  "ab"  "abc"
```

### Step 4: Base Cases

At this point, the input string becomes empty for all paths. The output is printed:
- `""`, `"c"`, `"b"`, `"bc"`, `"a"`, `"ac"`, `"ab"`, `"abc"`

### Complete Recursion Tree

Here is the complete recursion tree for `"abc"`:
```
                ""
         /               \
      ""                  "a"
     /  \              /       \
   ""   "b"         "a"        "ab"
  / \   /  \       /   \      /    \
"" "c" "b" "bc"  "a"  "ac"  "ab"  "abc"
```

## Simplified Steps for Understanding

### Step 1: Start with Full String
- Input: `"abc"`, Output: `""`

### Step 2: Branch for Each Character
- Exclude/Include `a`
  - Exclude/Include `b`
    - Exclude/Include `c`

### Step 3: Print Outputs at Base Case
- When the input string is empty, print the output string.

### Step 4: Backtrack to Explore All Paths
- Return to previous states and explore the unexplored branches.

### Step-by-Step Output
1. Start: `"abc"` -> Options: Exclude/Include `a`
2. For `"bc"`: Explore Exclude/Include `b`
3. For `"c"`: Explore Exclude/Include `c`
4. Base Case: Print all possible subsequences:
   - `""`, `"c"`, `"b"`, `"bc"`, `"a"`, `"ac"`, `"ab"`, `"abc"`

## Complexity Analysis

### Time Complexity:
- At every step, we make two recursive calls.
- For a string of length `n`, the total number of recursive calls is \(2^n\).
- Hence, the time complexity is \(O(2^n)\).

### Space Complexity:
- The space complexity is \(O(n)\) due to the maximum depth of the recursion tree.

## Output for Input "abc"

The output of the code is:
```
""
"c"
"b"
"bc"
"a"
"ac"
"ab"
"abc"
```
