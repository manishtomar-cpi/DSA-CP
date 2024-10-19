#include<iostream>
using namespace std;

int main (){

    // char input [4];
    // cout << "what is your input: " << endl;
    // cin >> input;


    // cout << "name is: " << input << endl; //if we fill 'abcd' means fill the array it may or may not print garbage till find \0 if we fill 'ma n' it will only print ma

    //solution for space is getline

    char arr[100];
    cout << "enter anything with space: " << endl;
    cin.getline(arr,100);// take 99 input one reserve for \0 but resolve the space issue
    cout << arr << endl;

    //cin.getline take 3 parameter (array_name, length_want_to_store, delimeter) delimeter means where you want to terminate the input  
    char char_arr[10];

    cout << "enter char: " << endl;
    cin.getline(char_arr, 10, 'o'); //means terminate at 'o'

    cout << char_arr << endl; //if we write hello world it will print hell


}



// This code provides a demonstration of handling input, particularly how to deal with spaces and custom delimiters in user input using `cin.getline()`. Here’s a breakdown of the important concepts and how the code works:

//  Key Concepts and Code Breakdown:

// 1. Character Array Input (`cin >> input`)
//    - Initially, the code commented out the basic `cin >> input` method, which reads input until it encounters whitespace. This approach does not handle spaces within input well, as it will only read the first word. 
//    - For example, if the user enters "ma n", only "ma" would be stored, and the rest is ignored.

// 2. Using `cin.getline()` for Input with Spaces
//    - The problem of reading input with spaces can be resolved by using the `cin.getline()` function.
//    - Syntax:
//      cin.getline(array_name, max_length);
//    - This function reads a line of text, including spaces, and stores it in the array. It stops reading when the line is terminated by a newline (`\n`) or when the maximum length specified (99 in this case) is reached.
//    - In the code:
//      char arr[100];
//      cout << "enter anything with space: " << endl;
//      cin.getline(arr, 100);  // Reads up to 99 characters plus the null terminator '\0'
//    - Explanation:
//      - It allows you to enter a string that contains spaces, such as "hello world", and it will correctly store and print the entire input.
//      - The `cin.getline(arr, 100)` function will reserve 99 characters for the input, leaving one space for the null terminator (`'\0'`), which is automatically added at the end of the string.

// 3. Using `cin.getline()` with a Delimiter
//    - `cin.getline()` also has an overloaded version that accepts a third parameter, a delimiter character. Input will be read until this delimiter is encountered.
//   
//      cin.getline(array_name, max_length, delimiter);
//    - In the code:
//      
//      cin.getline(char_arr, 10, 'o');
//    - Explanation:
//      - This line will read input until the character `'o'` is encountered. For instance, if the user enters "hello world", it will only store "hell" (because it stops reading before the first occurrence of 'o').
//      - The delimiter `'o'` essentially acts as a custom termination character.

// 4. Example Output:
//    - If the user inputs "hello world" when prompted for the second input:
//      cin.getline(char_arr, 10, 'o');
//      The program will stop reading at 'o', so `char_arr` will contain "hell", and this will be printed to the console.

// Key Takeaways:

// Handling Spaces in Input:
//   - `cin >>` doesn’t handle spaces well, so use `cin.getline()` to read a full line of input with spaces. This is essential when working with multiple-word strings or inputs where spaces are needed.
  
// Custom Delimiters:
//   - You can use `cin.getline()` with a custom delimiter to stop reading input based on a specific character. This is useful in cases where you want to process partial input up to a certain point, such as stopping at a specific character (like `'o'` in the example).

// Input Length Control:
//   - The second parameter in `cin.getline()` ensures that the input does not exceed the array's capacity, preventing buffer overflow issues. Always leave space for the null terminator (`'\0'`), which is automatically added to the string.
