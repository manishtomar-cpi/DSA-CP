#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
  Problem:
  --------
  we're given:
  - A string called 'pattern' like "abba"
  - A string called 's' like "dog cat cat dog"

  we need to check if the string 's' follows the same pattern.

  That means:
  - Each letter in the pattern should map to one unique word in 's'
  - And each word in 's' should map to only one unique letter in the pattern
  - No letter or word should be reused in a different mapping

  What the code does:
  -------------------
  1. Add a space to the end of 's' to make it easier to grab the last word.
  2. Make two hash maps:
     - 'hash' to store which word is mapped to each letter in the pattern
     - 'hash2' to store which letter is mapped to each word (for checking both sides)
  3. Go through each character of 's' and build a word until we hit a space.
     Once we have a complete word:
     - Get the current letter in the pattern using the 'covered' index.
     - If this letter and word haven’t been used before:
         → Store the mapping in both hash maps.
     - If they have been used before:
         → Check if the stored mapping is still the same.
         → If it’s different, return false (pattern doesn't match).
  4. At the end, check if the number of words equals the number of pattern letters.
     → If not, return false.

  Key Variables:
  --------------
  - 'currentWord': builds each word from 's'
  - 'covered': keeps track of which letter in the pattern we're using
  - 'hash': pattern letter → word
  - 'hash2': word → pattern letter
  - 'totalWords': counts how many words we found in 's'

  !Time: O(n), where n is the length of string 's'
  !Space: O(k), where k is the number of unique letters and words
*/
bool wordPattern(string pattern, string s)
{
    s += ' ';           // forprocessing last word
    int totalWords = 0; // for edge cases
    int covered = 0;    // how much chars covered from pattern
    string currentWord = "";
    unordered_map<int, string> hash;  // in which we will store the pattern -> s
    unordered_map<string, int> hash2; // for s -> pattern
    for (int i = 0; i < s.size(); i++)
    {
        // processing new word
        if (s[i] != ' ')
        {
            currentWord += s[i];
        }
        else
        {
            // if the new word we have
            if (hash[pattern[covered]] == "" && hash2[currentWord] == 0)
            {
                hash[pattern[covered]] = currentWord;
                hash2[currentWord] = pattern[covered];
            }
            // any of them is exist
            else
            {
                //!We use 'covered' to align each word with its pattern letter; if mapping is correct, the same letter at this index must map to the same word as before.
                if (hash2[currentWord] != pattern[covered] || hash[pattern[covered]] != currentWord)

                {
                    return false;
                }
            }
            currentWord = "";
            covered++;
            totalWords++;
        }
    }
    return totalWords == pattern.size() ? true : false;
}

int main()
{
    string pattern = "abba";
    string s = "dog cat cat fish";

    cout << wordPattern(pattern, s) << endl;

    return 0;
}