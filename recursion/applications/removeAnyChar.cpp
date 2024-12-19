#include <iostream>
using namespace std;

void removeA(char ar[])
{
    if (ar[0] == '\0')
    { // base
        return;
    }
    if (ar[0] != 'a')
    {                    // if current not equal to a
        removeA(ar + 1); // recursive call from next index
    }
    else
    { // if current is a
        for (int i = 0; ar[i] != '\0'; i++)
        {
            ar[i] = ar[i + 1]; // shift all chars to the left side to remove a
        }
        removeA(ar); // again recursive call not +1 because  now we have new shifted array their might be chance the array contain 'aa' means we have new a on 0
    }
}

void removeConsecutive(char ar[])
{
    if(ar[0]=='\0'){
        return;
    }
    if(ar[0]!=ar[1]){
        removeConsecutive(ar+1);
    }
    else{
        for(int i =0; ar[i]!='\0';i++){
            ar[i]= ar[i+1];
        }
        removeConsecutive(ar);
    }
}
int main()
{
    // char ar[] = "aaaaaaaak";
    // removeA(ar);
    // cout << ar << endl;
    char ar[] = "abcdefdd";
    removeConsecutive(ar);
    cout << ar << endl;
    return 0;
}