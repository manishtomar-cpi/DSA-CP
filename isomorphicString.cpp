#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool checkIsomorphic(string s, string t)
{
    unordered_map<int, int> firstHash;
    unordered_map<int, int> secondHash;
    vector<int> first;
    vector<int> second;
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        firstHash[s[i]]++;
    }
    for (int i = 0; i < t.size(); i++)
    {
        secondHash[t[i]]++;
    }

    for (auto &i : firstHash)
    {
        first.push_back(i.second);
    }
    for (auto &i : secondHash)
    {
        second.push_back(i.second);
    }

    for (int i = 0; i < first.size(); i++)
    {
        count = 0;
        for (int j = 0; j < second.size(); j++)
        {
            if(second.at(j)==first[i]){
                second[j]=-1;
                count++;
                break;
            }
        }
        if(count ==0 ){
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "egg";
    string t = "add";
    cout << boolalpha;
    cout << checkIsomorphic(s, t);
}