#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isAnagram(string s, string t)
{
    //edge case 
    if (s.size() < t.size() || s.size() > t.size())
    {
        return false;
    }
    //MAP
    vector<int> hash(26, 0);
    //fill the map according to both string all the index at the end should balanced to 0 if they are anagram
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a']++;
        hash[t[i] - 'a']--;
    }
    //check hash after filling
    for (int count : hash)
    {
        if (count != 0)
            return false;
    }
    return true;
}

/*
  Method: Frequency Count using Array

  Idea:
  - Use a fixed-size array (size 26 for lowercase letters) to count characters.
  - Increment count for each character in 's'
  - Decrement count for each character in 't'
  - At the end, all counts should be zero.

  Steps:
  1. Create an array of size 26 initialized to 0
  2. Loop through 's' and increment count for each letter
  3. Loop through 't' and decrement count for each letter
  4. If any count ≠ 0 → not an anagram

  Time Complexity: O(n)
  Space Complexity: O(1) (constant 26-sized array)

  Pros:
  - Fast and memory efficient
  - Best for lowercase letters

  Cons:
  - Limited to lowercase letters unless modified for other char sets

  Example:
  s = "aabb", t = "baba" → count matches → yes it is
*/


/*
Method : Sorting
  Idea:
  - Sort both strings and compare them.
  - If they match exactly, they are anagrams.
  Steps:
  1. Sort string 's'
  2. Sort string 't'
  3. Compare both sorted strings character by character

  !Time Complexity: O(n log n)
  Space Complexity: O(1) if sorting in place

  Pros:
  - Simple and easy to understand
  - No extra data structures needed

  Cons:
  - Slower due to sorting
  - Not ideal for very long strings

  Example:
  s = "listen", t = "silent" → after sort → "eilnst" == "eilnst" → yes it is

  sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != t[i]) {
            return false;
        }
    }
    return true;
*/

/*
Method: Hash Map (Generic Character Count)

  Idea:
  - Use unordered_map<char, int> to store frequencies
  - Works for all characters (including uppercase, digits, Unicode, etc.)

  Steps:
  1. Loop through 's' and increment char counts in map
  2. Loop through 't' and decrement counts
  3. If a character not found or count < 0 → not an anagram
  4. Finally, all values in map should be 0

  !Time Complexity: O(n)
  Space Complexity: O(k), where k = number of unique characters

  Pros:
  - Works for all character sets
  - Easy to extend for case-insensitive or Unicode

  Cons:
  !- Slightly more overhead than fixed-size array

  Example:
  s = "Debit Card", t = "Bad Credit" → normalize and compare counts -> yes

vector<int> hash(26, 0);
 for (int i = 0; i < s.size(); i++) {
     int index = s[i] - 'a';
     hash[index]++;
 }
 for (int i = 0; i < t.size(); i++) {
     int index = t[i] - 'a';
     if (hash[index] == 0) { // if word not present in s but present
     in t
         return false;
     }
     hash[index]--;
 }
 for (int i = 0; i < s.size(); i++) {
     int index = s[i] - 'a';
     if (hash[index] > 0)
         return false;
 }
*/
