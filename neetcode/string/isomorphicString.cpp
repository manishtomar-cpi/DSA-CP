#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void displayHash(unordered_map<int, int> hash)
{
    for (auto &i : hash)
    {
        cout << i.first;
        cout << " " << i.second;
    }
    cout << endl;
}

bool checkIsomorphic(string s, string t)
{
    // unordered_map<int, int> hash;
    // for(int i=0; i< s.size();i++){
    //     if(hash[s[i]]==0){
    //         for(auto &j : hash){
    //         if(j.second==t[i]){
    //             return false;
    //         }
    //         }
    //         hash[s[i]]=t[i];
    //     }
    //     if(hash[s[i]]!=0){
    //         if(hash[s[i]]!=t[i]){
    //             return false;
    //         }
    //     }
    // }
    // return true;

    //! O(N)

    unordered_map<int, int> mapST, mapTS;

    for (int i = 0; i < s.size(); i++)
    {
        if (mapST[s[i]] == 0 && mapTS[t[i]] == 0)
        {
            mapST[s[i]] = t[i];
            mapTS[t[i]] = s[i];
        }
        else
        {
            if (mapST[s[i]] != t[i] || mapTS[t[i]] != s[i])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    string s = "paper";
    string t = "title";
    cout << boolalpha;
    cout << checkIsomorphic(s, t);
}