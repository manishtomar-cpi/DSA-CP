// #include <iostream>
// #include <vector>
// using namespace std;

// // Function 1: Add 10 to a number (pass-by-reference)
// void addTen(int &num) {  // `num` is a reference to the original variable
//     num += 10;
// }

// // Function 2: Double each element in a vector (pass-by-reference in a range-based loop)
// void doubleElements(vector<int> &vec) {
//     for (int &num : vec) {
//         num *= 2;  // Double each element
//     }
// }

// // Function 3: Print elements without modifying (using `const &` for read-only access)
// void printElements(const vector<int> &vec) {
//     for (const int &num : vec) {
//         cout << num << " ";
//     }
//     cout << endl;
// }

// // Function 4: Add 5 to each element using traditional `for` loop (index-based access with `&`)
// void addFiveToElements(vector<int> &vec) {
//     for (size_t i = 0; i < vec.size(); ++i) {
//         int &num = vec[i];
//         num += 5;
//     }
// }

// int main() {
//     // Example 1: Passing by Reference in Function
//     int x = 5;
//     cout << "Original value of x: " << x << endl;
//     addTen(x);  // Pass x by reference
//     cout << "Value of x after addTen function: " << x << endl;  // Output: 15

//     cout << "-----------------------" << endl;

//     // Example 2: Using `&` in Range-Based Loop to Modify Elements
//     vector<int> numbers1 = {1, 2, 3, 4, 5};
//     doubleElements(numbers1);
//     cout << "Modified numbers1 (each element doubled): ";
//     printElements(numbers1);  // Output: 2 4 6 8 10

//     cout << "-----------------------" << endl;

//     // Example 3: Using `const &` in Range-Based Loop for Read-Only Access
//     vector<int> numbers2 = {10, 20, 30, 40, 50};
//     cout << "Read-only access to numbers2 (no modifications): ";
//     printElements(numbers2);  // Output: 10 20 30 40 50

//     cout << "-----------------------" << endl;

//     // Example 4: Using `&` with Traditional `for` Loop for Index-Based Access
//     vector<int> numbers3 = {5, 10, 15, 20, 25};
//     addFiveToElements(numbers3);
//     cout << "Modified numbers3 (5 added to each element): ";
//     printElements(numbers3);  // Output: 10 15 20 25 30

//     return 0;
// }


#include<iostream>
#include<vector>
using namespace std;

void printElement(const vector<int>&vec){ //here wqe passed by reference with const , means we canbt chnage thye value and no copy will made of the orignal vector 
    cout << "{ ";
    for(auto i : vec){
        cout << i << " ";
    }
    cout << "}" << endl;
}

void func(int &a){
a+=10;
}

void doubleElements(vector<int> &vec) { // no copy make 
    // for (int num : vec) { // if we not take int &num means we are changing in the function
    for (int &num : vec) { //now chnage the acctual value

        num *= 2;  // Double each element
    }
}

int main (){
    int a =15;
    func(a);
    cout << a << endl; //25 chnage the orignal value because we send by reference 
    vector<int> vec = {1,2,3,4};

    doubleElements(vec);
    printElement(vec);
}