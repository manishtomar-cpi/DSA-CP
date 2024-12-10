### **1. `length()` / `size()`**
Returns the length of the string.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "hello";
    cout << s.length(); // Output: 5
}
```

---

### **2. `empty()`**
Checks if the string is empty.

```cpp
string s = "";
cout << s.empty(); // Output: 1 (true)
```

---

### **3. `clear()`**
Clears all characters from the string.

```cpp
string s = "hello";
s.clear();
cout << s; // Output: (empty string)
```

---

### **4. `push_back(char)`**
Adds a character to the end of the string.

```cpp
string s = "abc";
s.push_back('d');
cout << s; // Output: abcd
```

---

### **5. `pop_back()`**
Removes the last character from the string.

```cpp
string s = "hello";
s.pop_back();
cout << s; // Output: hell
```

---

### **6. `substr(pos, len)`**
Extracts a substring.

```cpp
string s = "abcdef";
cout << s.substr(2, 3); // Output: cde
```

---

### **7. `find(str)`**
Finds the first occurrence of a substring.

```cpp
string s = "hello world";
cout << s.find("world"); // Output: 6
```

---

### **8. `rfind(str)`**
Finds the last occurrence of a substring.

```cpp
string s = "hello hello";
cout << s.rfind("hello"); // Output: 6
```

---

### **9. `replace(pos, len, str)`**
Replaces part of the string.

```cpp
string s = "abcdef";
s.replace(2, 3, "XYZ");
cout << s; // Output: abXYZf
```

---

### **10. `insert(pos, str)`**
Inserts a substring at a position.

```cpp
string s = "hello";
s.insert(2, "XYZ");
cout << s; // Output: heXYZllo
```

---

### **11. `erase(pos, len)`**
Removes part of the string.

```cpp
string s = "abcdef";
s.erase(2, 3);
cout << s; // Output: abf
```

---

### **12. `append(str)`**
Appends a string to the end.

```cpp
string s = "abc";
s.append("def");
cout << s; // Output: abcdef
```

---

### **13. `compare(str)`**
Compares two strings.

```cpp
string s1 = "abc", s2 = "abd";
cout << s1.compare(s2); // Output: -1 (s1 < s2)
```

---

### **14. `to_string(num)`**
Converts a number to a string.

```cpp
int num = 123;
cout << to_string(num); // Output: 123
```

---

### **15. `stoi(str)`**
Converts a string to an integer.

```cpp
string s = "456";
cout << stoi(s); // Output: 456
```

---

### **16. `sort(begin, end)`** *(from `<algorithm>`)*  
Sorts the characters of the string.

```cpp
#include <algorithm>
string s = "dcba";
sort(s.begin(), s.end());
cout << s; // Output: abcd
```

---

### **17. `reverse(begin, end)`** *(from `<algorithm>`)*  
Reverses the string.

```cpp
#include <algorithm>
string s = "abcd";
reverse(s.begin(), s.end());
cout << s; // Output: dcba
```

---

### **18. `isdigit(ch)` & `isalpha(ch)`** *(from `<cctype>`)*  
Checks if a character is a digit or alphabet.

```cpp
#include <cctype>
cout << isdigit('5') << " " << isalpha('a'); // Output: 1 1
```

---

### **19. `find_first_of(chars)`**
Finds the first occurrence of any character in `chars`.

```cpp
string s = "hello";
cout << s.find_first_of("aeiou"); // Output: 1
```

---

### **20. `find_last_of(chars)`**
Finds the last occurrence of any character in `chars`.

```cpp
cout << s.find_last_of("aeiou"); // Output: 4
```

---

### **21. `resize(len)`**
Resizes the string.

```cpp
string s = "abcdef";
s.resize(3);
cout << s; // Output: abc
```

---

### **22. `swap(str)`**
Swaps two strings.

```cpp
string s1 = "abc", s2 = "xyz";
s1.swap(s2);
cout << s1; // Output: xyz
```

---

### **23. `toupper(ch)` & `tolower(ch)`** *(from `<cctype>`)*  
Converts a character to uppercase or lowercase.

```cpp
#include <cctype>
char upper = toupper('a'), lower = tolower('Z');
cout << upper << " " << lower; // Output: A z
```

---

### **24. `count(begin, end, ch)`** *(from `<algorithm>`)*  
Counts the occurrences of a character.

```cpp
#include <algorithm>
string s = "aaaabc";
cout << count(s.begin(), s.end(), 'a'); // Output: 4
```

---

### **25. `unique()`** *(from `<algorithm>`)*  
Removes consecutive duplicate characters.

```cpp
#include <algorithm>
string s = "aabbcc";
s.erase(unique(s.begin(), s.end()), s.end());
cout << s; // Output: abc
```

---

### **26. `getline()`**
Reads a full line of input.

```cpp
string s;
getline(cin, s); // Input: "hello world"
cout << s; // Output: hello world
```

---

These examples cover key string manipulation tasks often required in **competitive programming**, ensuring efficient solutions to common problems.