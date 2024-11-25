#include<iostream>
using namespace std;


int lengthOfString(char arr[]){
int i =0;

//loop until got 'null' in string
while (arr[i] != '\0'){
    i++;
}
cout <<"size of the string is : ";
return i;
}

int main(){
    char arr[100] = {'m', 'a', 'n', 'i'};
    cout << lengthOfString(arr);

    return 0;
    }