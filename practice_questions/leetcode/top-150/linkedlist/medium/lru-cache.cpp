
#include <iostream>
#include <unordered_map>
using namespace std;
class Node
{
public:
    int key;
    int val;
    Node *next;
    Node *prev;

    Node(int key_val, int value)
    {
        key = key_val;
        val = value;
        next = nullptr;
        prev = nullptr;
    }
    Node()
    {
        val = INT_MAX;
        key = INT_MAX;
        next = nullptr;
        prev = nullptr;
    }
};
class LRUCache
{
public:
    int size;
    int capacity;
    unordered_map<int, Node *> hash;

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        size = 0;
    }
    Node *dummy = new Node();
    Node *last = dummy;

    int get(int key)
    {
        if (hash.find(key) == hash.end())
        {
            return -1;
        }
        if (hash[key] == dummy->next)
        {
            return dummy->next->val;
        }
        Node *current = hash[key];

        if (current->prev)
        {
            current->prev->next = current->next;
        }
        if (current->next)
        {
            current->next->prev = current->prev;
        }

        // if we want the last one so last is also update this time
        if (last == current)
        {
            last = current->prev;
        }
        Node *dummy_next = dummy->next;
        dummy->next = current;

        current->prev = dummy;
        current->next = dummy_next;
        if (dummy_next) // update the next node's previous pointer if it exists.
            dummy_next->prev = current;

        return current->val;
    }

    void put(int key, int value)
    {
        cout << "::::::::" << key << endl;

        // first case if the key is not present
        if (hash.find(key) == hash.end())
        {
            Node *temp = new Node(key, value);

            // first case size is less then capacity
            if (size < capacity)
            {
                // in this first check if we inserting the first node
                if (!dummy->next)
                {
                    dummy->next = temp; // make connection of dummy next to new node
                    temp->prev = dummy; // update the prev of new node with dummy
                    last = dummy->next; // now last is also at new node
                    last->prev = dummy; // and last prev is pointing to dummy
                }
                // if already more then or equal to 1 node is present
                else
                {
                    Node *dummy_next = dummy->next;
                    dummy->next = temp;
                    temp->prev = dummy;
                    temp->next = dummy_next;
                    dummy_next->prev = temp;

                    // check last if it is still pointing to first means we are adding second node now last should be at second node
                    if (last->prev == dummy)
                    {
                        last->prev = temp;
                    }
                }
                size++;
                hash[key] = temp;
                cout << last->val << " -> last" << endl;
                cout << "first node is " << dummy->next->val << endl;
                cout << "prev of last is " << last->prev->val << endl;
            }
            // if cache is full
            else
            {

                //?REMOVE LAST
                Node *current = last;
                Node *last_prev = last->prev; // previous of last
                last_prev->next = nullptr;    // because it is the last nod eof ll
                last = last_prev;
                last->prev = last_prev->prev;

                //?MAKE CONNECTION ON HEAD
                // new node should on head now ->first chekc if have some nodes
                if (dummy->next)
                {
                    Node *dummy_next = dummy->next;
                    dummy->next = temp;
                    temp->prev = dummy;
                    temp->next = dummy_next;
                    dummy_next->prev = temp;
                }

                //! means capacity is 1 if capacity is 1 we every time remove first node ans we dont have dummy->next
                else
                {
                    dummy->next = temp; // make connection of dummy next to new node
                    temp->prev = dummy; // update the prev of new node with dummy
                    last = dummy->next; // now last is also at new node
                    last->prev = dummy; // and last prev is pointing to dummy
                }
                cout << last->val << " -> last" << endl;
                hash.erase(current->key);
                hash[key] = temp;

                cout << current->val << " erased from map" << endl;
                cout << "first node is " << dummy->next->val << endl;
                cout << "prev of last is " << last->prev->val << endl;
            }
        }
        else
        {
            cout << "+++++++++++alreay there!+++++++++++++++++" << endl;
            Node *current = hash[key];

            // now check it the current (which need to update) is already on head
            if (dummy->next == current)
            {
                current->val = value; // so, we will not remove last and and chnage head because it is already on head just update its value
            }
            else
            {
                // update its value and shift it on front
                current->val = value;
                Node *dummy_next = dummy->next;
                dummy->next = current;
                // means the node is the last node which we need to update , so we need to chnage the last as well this time
                if (last == current)
                {
                    last = current->prev;
                }
                current->prev->next = current->next;
                if (current->next)
                    current->next->prev = current->prev;
                current->prev = dummy;
                current->next = dummy_next;
                dummy_next->prev = current;
            }
        }
    }

    void print()
    {
        Node *temp = dummy->next;
        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LRUCache lRUCache(3); // Initialize LRUCache with capacity 3

    lRUCache.put(1, 1);
    lRUCache.put(2, 2);
    lRUCache.put(3, 3);
    lRUCache.put(4, 4);

    cout << lRUCache.get(4) << endl; // Expected 4
    cout << lRUCache.get(3) << endl; // Expected 3
    cout << lRUCache.get(2) << endl; // Expected 2
    cout << lRUCache.get(1) << endl; // Expected -1 (evicted)

    lRUCache.put(5, 5);

    cout << lRUCache.get(1) << endl; // Expected -1 (still not found)
    cout << lRUCache.get(2) << endl; // Expected -1 (evicted)
    cout << lRUCache.get(3) << endl; // Expected 3
    cout << lRUCache.get(4) << endl; // Expected 4
    cout << lRUCache.get(5) << endl; // Expected 5

    return 0;
}
