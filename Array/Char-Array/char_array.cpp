#include <iostream>
using namespace std;

int main()
{

    char name[100];
    cout << "enter your name : " << endl;
    cin >> name;

    // cout << "your name is : " << name << endl; // manish -> 'm' 'a' 'n' 'i' 's' 'h' '\0(null)'s

    // name[7] = 't';
    // cout << "your name is : " << name << endl; //manish -> because on name [6] its '\0'

    // name[6] = 'o';
    // cout << "your name is : " << name << endl; //manishotuç█v∟ôαvⁿ■a because terminate at '\0'

    cout << ">>>loop>>>>" << endl;
    for (auto i : name)
    {
        cout << i << " ";
    } // print everything in the array include name then garbage like m a n i s h    ? é ┌ v ê + ☻ ☺ ╝ ■ a  u ç █ v ∟ ô α v ⁿ ■ a  = | █ v    } ü ┌ v c ü ┌ v n ▲ ↕ @  α ↕ @      É → @  ╨ ■ a    a  ╠   a  p ß ┌ v Ω : á m ■         a  m é ┌
    cout << endl;
    return 0;
}

// 1. Character Array (`char name[100]`)
//    - The array `name` is declared with a size of 100 characters, meaning it can store a string of up to 99 characters plus the null terminator (`'\0'`) which indicates the end of a C-style string.
//    - In C++, character arrays can be used to store strings, but they don't have the built-in safeguards or features of `std::string` (e.g., automatic memory management).

// 2. User Input (`cin >> name`)
//    - The `cin` command reads a string from the user and stores it in the `name` array.
//    - `cin` stops reading when it encounters whitespace, so only one word will be read.

// 3. Output Initial Name
//    - The first `cout` prints the name the user entered.
//    - At this point, the array stores the entered name followed by the null terminator (`'\0'`), ensuring proper string handling.

// 4. Manipulating Characters Beyond the String's Length
//    - `name[7] = 't';`: This line attempts to assign the value `'t'` to the 8th position of the array (index 7). If the user's name is shorter than 7 characters, this may modify an unintended memory location or a null terminator, causing unpredictable behavior when the string is printed.
//      - For example, if the name is "manish", which ends at index 6 (`'\0'`), setting `name[7]` introduces undefined behavior because you’re modifying beyond the string’s natural boundary.
//    - The second `cout` prints this modified array, but depending on the original input, the result might be incorrect or cause undefined behavior.

// 5. Modifying the Null Terminator (`name[6] = 'o';`)
//    - `name[6] = 'o';`: This line replaces the null terminator (`'\0'`) with the character `'o'`.
//    - Since a C-string is terminated by `'\0'`, modifying this terminator disrupts the string, leading to potentially printing garbage values (characters beyond the original string).
//    - The final `cout` will now print garbage characters or memory contents past the intended string boundary because the string is no longer terminated correctly.

// Key Takeaways:

// - String Termination in C++: C-style strings (character arrays) rely on the null terminator (`'\0'`) to know where the string ends. If the terminator is overwritten, you may print random memory values (garbage) after the string.

// - Array Bounds: Be cautious when manipulating specific elements of the array beyond the actual length of the string entered by the user. Going past the bounds of the array or the string leads to undefined behavior.

// - Better String Handling: While character arrays work, it's generally better to use `std::string` in C++ for safer string manipulation, as it automatically manages the string's size and handles input/output more flexibly without risking memory issues.