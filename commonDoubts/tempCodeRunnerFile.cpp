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