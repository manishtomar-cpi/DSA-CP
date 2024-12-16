#include<iostream>
using namespace std;

void print(int n){
    if(n>=1){
        cout << n << " "; //dec order
        print(n-1);
        // cout << n << " "; // ass order 
    }
    // return 0;
}

int main (){
    print(4);

    return 0;
}