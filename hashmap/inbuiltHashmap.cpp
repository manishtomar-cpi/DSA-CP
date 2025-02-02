#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

void hashmap()
{
    unordered_map<string, int> myMap;

    //?---> insert
    //* method 1: un_map taking input like this by default
    pair<string, int> p{"abc", 1};
    myMap.insert(p);

    // *method2:
    myMap["def"] = 2; // easy simplest

    //? --->find or access
    cout << myMap["abc"] << endl;    // 1
    cout << myMap.at("abc") << endl; // 1

    //! cout << myMap.at("xyx") << endl; // throw exceptional error -> terminate called after throwing an instance of 'std::out_of_range'
    cout << myMap["xyx"] << endl; // 0 this method check xyx if not present add xyx in map and insert the key to 0, and return 0;

    //?---> size
    cout << "size: " << myMap.size() << endl; // 3

    // ?--->check presence of key
    // cout << myMap.count("xyx") << endl; // 1 ->because we just inserted above
    if (myMap.count("xyx") > 0)
    {
        cout << "xyx present!" << endl;
    }
    else
    {
        cout << "xyx not present!" << endl;
    }

    // ?--->update any key
    myMap["abc"] = 10;

    //?--->erase aby key
    myMap.erase("xyx");
    cout << "size: " << myMap.size() << endl; // 2

    // difference b/w unordered and ordered map is only of the time complexity in ordered map all operations take O(N), but in unordered O(1) because ordered works on Balanced BST and unordered works on hash table
}

// traversing in map
void traverse()
{
    unordered_map<string, int> myMap;
    myMap["manish"] = 6;
    myMap["virta"] = 5;
    myMap["archit"] = 4;
    myMap["shivam"] = 3;
    myMap["sagar"] = 2;
    // unordered_map<string, int>::iterator it = myMap.begin();
    auto it = myMap.begin();
    while (it != myMap.end())
    {
        cout << "key: " << it->first << " value: " << it->second << endl;
        it++;
    }
    //?in unordered map the values store in unordered manner but if we use ordered map the element will store in the sorted manner behalf of keys //!not on behalf on values
}
int main()
{
    // hashmap();
    traverse();
    return 0;
}