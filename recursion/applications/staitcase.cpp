#include<iostream>
using namespace std;

int countWays(int n){
    if(n==0||n==1){
        return 1; //base case means zero to zero its 0 from  0 to to its also one way

    }
    if(n==2){
        return 2; //means for reaching 2 we have two ways one from 1 to 2 one from o to 2
    }

    return  countWays(n-1)+countWays(n-2)+countWays(n-3); //means we have n-1. n-2 , n-3 ways to reach because we only take 1,2,3 steps 
}

int main (){
    int n =5;

    cout << countWays(n) << endl;

    return 0;
}