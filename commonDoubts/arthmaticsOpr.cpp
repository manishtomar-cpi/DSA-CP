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
