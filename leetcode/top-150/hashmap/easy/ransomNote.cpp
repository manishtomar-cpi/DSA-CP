#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
bool canConstruct(string ransomNote, string magazine)
{
    unordered_map<int, int> hash;
    for (int i = 0; i < magazine.size(); i++)
    {
        // fill the map according to occurance
        hash[magazine[i]]++;
    }
    for (int i = 0; i < ransomNote.size(); i++)
    {
        // if not there
        if (hash[ransomNote[i]] < 1)
        {
            return false;
        }
        // if there-> decrease the occurance by once
        hash[ransomNote[i]]--;
    }
    return true;
}

int main()
{
    string ransomNote = "aa";
    string magazine = "aab";

    cout << canConstruct(ransomNote, magazine) << endl;

    return 0;
}