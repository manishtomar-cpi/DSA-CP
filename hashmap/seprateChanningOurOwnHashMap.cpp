#include <iostream>
#include <string>
using namespace std;

// making map node class first
class MapNode
{
public:
    string key;
    int val;
    MapNode *next;

    MapNode(string key, int val) : key(key), val(val), next(nullptr) {};
};

// now making mymap classs for hashmap
class Mymap
{
private:
    int bucketSize;       // size of the bucket array
    MapNode **bucketAray; // making bucket array 'MapNode *' is the type of that array and one more pointer is for the dynamic array

    // converting key by hashing
    int hashFunction(string key)
    {
        // int hasValue = 0; // for counting the value of the key
        // for (int i = 0; i < key.size(); i++)
        // {
        //     hasValue += key[i];
        // }
        // return hasValue % bucketSize; // now taking mode for storing the value in the bucket table //? why mode because the mod always in the range of bucket array
        long long hashValue = 0;
        int p = 31, mod = 1e9 + 9; // Large prime number for a better range
        for (char ch : key)
        {
            hashValue = (hashValue * p + ch) % mod;
        }
        return hashValue % bucketSize;
    }
    /*
    Why Use Polynomial Hashing?

    previous approach:
    int hasValue = 0;
    for (int i = 0; i < key.size(); i++) {
        hasValue += key[i];
    }
    return hasValue % bucketSize;

    This sums up ASCII values of characters.

    Problem: abc, bca, and cab will give the same sum and map to the same bucket → More Collisions! ❌
    
    New Hashing Formula
    
    The polynomial rolling hash avoids this issue:
    hashValue=(hashValue×p+ch)modbucketSize
    We multiply the previous hash by p = 31 before adding the next character.
    This ensures order matters, so "abc" and "bca" get different hash values.
    Taking % mod ensures values stay within bounds.
    
    3. Example Calculation
    Let’s hash "abc" with bucketSize = 10:
    p = 31, mod = 10
    Character	ASCII	Calculation (mod 10)
    'a' (97)	97	(0 * 31 + 97) % 10 = 7
    'b' (98)	98	(7 * 31 + 98) % 10 = (217 + 98) % 10 = 5
    'c' (99)	99	(5 * 31 + 99) % 10 = (155 + 99) % 10 = 4
   
    Final Hash of "abc" = 4 
    
    4. Advantages of This Hashing Method
    ✔ Reduces Collisions: Similar words like "abc" and "bca" won’t get the same hash.
    ✔ Uses Prime Multiplication: Improves uniform distribution.
    ✔ Works Well for Strings: Many modern hash functions use polynomial rolling for text.

    5. Alternative Prime Values
    p = 31 is good for lowercase English letters (a-z).
    If your keys contain uppercase (A-Z) and digits (0-9), you can use:
    p = 53 (recommended for mixed case).
    p = 101 (for larger character sets).

    */

public:
    Mymap(int size) : bucketSize(size)
    {
        // making array in the constructor
        bucketAray = new MapNode *[bucketSize]; // again 'MapNode *' is the data type
        // because all the pointers in the bucket array contains garbage so make them
        for (int i = 0; i < bucketSize; i++)
        {
            bucketAray[i] = nullptr;
        }
    }

    void insert(string key, int val)
    {
        // taking hash value of the key
        int indexToInsert = hashFunction(key);
        MapNode *head = bucketAray[indexToInsert]; // making head
        // first checking existing value
        while (head)
        { // loop to check if exist is not exist we will add as the head otherwise will add next node after end
            if (head->key == key)
            {
                head->val = val;
                cout << key << " value updated to: " << val << " !" << endl;
                return;
            }
            head = head->next;
        }
        // insert the new node at the begining of the LL
        MapNode *temp = new MapNode(key, val);
        temp->next = bucketAray[indexToInsert]; // adding temp->next existing head
        bucketAray[indexToInsert] = temp;       // now updating the head
        cout << "inserted " << key << " -> " << val << " inserted in the hashmap!" << endl;
    }

    int search(string key)
    {
        int indexToSearch = hashFunction(key); // first hashed the index to search
        MapNode *head = bucketAray[indexToSearch];
        while (head)
        {
            if (head->key == key)
            {
                return head->val;
            }
            head = head->next;
        }
        return -1;
    }

    void deleteKey(string key)
    {
        int indexToDelete = hashFunction(key);
        MapNode *head = bucketAray[indexToDelete];
        MapNode *prev = nullptr;
        // if the key is at head

        // traversing the hashed index
        while (head)
        {
            if (head->key == key)
            {
                if (prev)
                { // if not head
                    prev->next = head->next;
                }
                else
                {
                    bucketAray[indexToDelete] = head->next; // making the head pointing to the next
                }
                delete head;
                cout << key << " deleted!" << endl;
                return;
            }
            // updating the prev and head on each iteration
            prev = head;
            head = head->next;
        }
    }

    void display()
    {
        for (int i = 0; i < bucketSize; i++)
        {
            MapNode *temp = bucketAray[i];
            while (temp)
            {
                cout << temp->key << " - > " << temp->val << endl;
                temp = temp->next;
            }
        }
    }

    ~Mymap()
    {
        for (int i = 0; i < bucketSize; i++)
        {
            MapNode *head = bucketAray[i];
            // first del all the lists
            while (head)
            {
                MapNode *temp = head;
                head = head->next;
                delete temp;
            }
        }
        // then array
        delete[] bucketAray;
    }
};

int main()
{
    Mymap m1(20);
    m1.insert("man", 16);
    m1.insert("vir", 10);
    m1.insert("nam", 11);
    m1.insert("riv", 89);
    m1.insert("aja", 12);
    m1.insert("abc", 16);
    m1.insert("man", 17);
    m1.display();
    cout << m1.search("man") << endl;
    m1.deleteKey("abc");
    m1.display();

    return 0;
}
