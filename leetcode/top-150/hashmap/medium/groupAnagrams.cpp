#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

void display_2D(vector<vector<string>> &vec)
{

    for (int i = 0; i < vec.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << "]" << " ";
    }
    cout << endl;
}
void display(vector<string> &str)
{
    cout << "[ ";
    for (auto i : str)
    {
        cout << i << " , ";
    }
    cout << "]" << endl;
}
/*
- For each string:
      1. Sort the string → becomes the key
      2. Use a hash map where:
         - key = sorted string
         - value = list of all anagram strings
  - All anagrams will naturally fall under the same key

  - Finally, collect all the values from the hash map

  Pros:
  - Very clean and efficient
  - No nested loop
  - Only one hash map needed
  ?- Time Complexity: O(n·m·log m) where:
      → n = number of words
      → m = average length of word
  ?-  Space Complexity: O(n)
*/
vector<vector<string>> groupAnagrams_optimal(vector<string> &strs)
{
    unordered_map<string, vector<string>> hash;
    // created the hashmap of all the anagrams
    for (auto key : strs)
    {
        string word = key;            // orginal word
        sort(key.begin(), key.end()); // sorted because of next anagram we can check if it will be the next anagram
        hash[key].push_back(word);
    }
    /*
    Map look like:
    aet -> eat, tea, ate
    ant -> tan, nat
    abt -> bat
    */
    vector<vector<string>> res;
    // because in the hash all the anagrams in the values at each key
    for (auto anagram : hash)
    {
        res.push_back(anagram.second);
    }
    return res;
}

/*
- Sort the original input list to keep the output more ordered (optional)
  - For each word:
      1. Sort it to get its "anagram signature"
      2. Store the sorted version in a separate map
  - Then for each word:
      - If the sorted form hasn't been used before:
          → Compare with all remaining words' sorted forms
          → Group matching ones
      - Track which keys were used using a separate hash map

  Pros:
  ?- Conceptually straightforward
  ?- Good practice for working with multiple hash maps and nested loops

  Cons:
  !- Works fine but
  !- Time Complexity: O(n² * m) due to inner loop
  !- Redundant checks for matching even after precomputing keys
  !- Requires extra space for tracking sorted versions and visited keys

*/
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    if (strs.size() < 1)
    {
        return {};
    }
    vector<vector<string>> res;
    vector<string> same;
    unordered_map<string, int> hash;      // for checking the anagrams if already added
    unordered_map<string, string> sorted; // for reducing time of inner sort
    sort(strs.begin(), strs.end());

    // making the sorted hashmap
    for (int i = 0; i < strs.size(); i++)
    {
        string current = strs[i];
        sort(current.begin(), current.end());
        sorted[strs[i]] = current; // eat -> aet //? helps us when we want the sorted one
    }
    display(strs);

    for (int i = 0; i < strs.size(); i++)
    {
        string current = sorted[strs[i]]; // comes sorted hashmap in work , in constant time getting the sorted , insted of sort();
        // if current comes first time
        if (!hash.count(current))
        {
            same.push_back(strs[i]);
            // traverse whole vector to find the anagram of current
            for (int j = i + 1; j < strs.size(); j++)
            {
                string check = sorted[strs[j]]; //?again
                // sort(check.begin(), check.end());
                if (current == check)
                { // checking the sorted if sorted is same that means they are anagram
                    same.push_back(strs[j]);
                }
            }
            // push in final vector
            res.push_back(same);
            same.clear();
        }
        // now we have added anagrams of current word
        hash[current]++;
    }
    display_2D(res);
    return res;
}
int main()
{
    vector<string> str = {"eat", "tea", "tan", "ate", "nat", "bat"};
    groupAnagrams(str);

    return 0;
}