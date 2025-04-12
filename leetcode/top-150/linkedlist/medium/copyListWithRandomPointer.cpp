#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;
    Node(int val) : val(val), next(nullptr), random(nullptr) {};
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    // Insert at end
    void insert(int val)
    {
        Node *newNode = new Node(val);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Print the List
    void print()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << "Node Value: " << temp->val << " ";

            if (temp->next)
                cout << "| Next: " << temp->next->val << " ";
            else
                cout << "| Next: NULL ";

            if (temp->random)
                cout << "| Random: " << temp->random->val << endl;
            else
                cout << "| Random: NULL" << endl;

            temp = temp->next;
        }
    }

    // Getter to access head (for copy function)
    Node *getHead()
    {
        return head;
    }

    void printHash(unordered_map<int, int> hash)
    {
        for (auto it : hash)
        {
            cout << it.first << " " << it.second << endl;
        }
    }
    /*
Approach Explanation:

Step 1: Traverse the original linked list and create a hash map
        where key = current node index, value = index of node where random pointer is pointing.
        - If random pointer is NULL, store -1.
        - Else traverse from head and find the index of the node where random pointer is pointing.

Step 2: Create a completely new linked list by copying only the values
        from the original list (ignoring random for now).
        - Connect the new nodes using next pointer only.

Step 3: Set the random pointers in the newly created list using the hash map.
        - If hash value is -1, set random = NULL.
        - Else move to the corresponding index node in copied list and set random pointer.

Important Point:
- This approach uses index-based mapping to avoid using old node addresses in the new list.
- No pointer of the copied list is connected to any old node.
- Hash map is only used to store index information temporarily to set correct random pointers.

Time Complexity:
- O(n^2) because for finding random node index, nested traversal is used.

Space Complexity:
- O(n) extra space for hash map.

Conclusion:
- Correct deep copy is created.
- Fulfills the condition of no old node address being used in the new list.
- Clean and simple approach.
*/

    Node *copyRandomList(Node *head)
    {
        unordered_map<int, int> hash; // in the map key is the index of current node (1 based) and value is in which index random is pointing
        Node *temp = head;
        int i = 1;
        int j = 1;
        // First fill the map accordingly
        while (temp)
        {
            // if random pointing on null
            if (temp->random == nullptr)
            {
                hash[i] = -1;
            }
            else
            {
                // store the address of the random where random is pointing
                Node *address = temp->random;
                Node *temp1 = head;
                // now find that address in LL
                while (temp1)
                {
                    if (temp1 == address)
                    {
                        hash[i] = j;
                        j = 0;
                        break;
                    }
                    temp1 = temp1->next;
                    j++;
                }
            }
            i++;
            j = 1;
            temp = temp->next;
        }
        printHash(hash);
        Node *copied = nullptr;
        Node *copied_last = nullptr;
        Node *for_traverse = head;
        // Now make all new linked list , ignore random at this step
        while (for_traverse)
        {
            Node *temp = new Node(for_traverse->val);
            if (copied_last == nullptr)
            {
                copied = temp;
                copied_last = copied;
            }
            else
            {
                copied_last->next = temp;
                copied_last = copied_last->next;
            }
            for_traverse = for_traverse->next;
        }
        // Now connect random of each node
        for_traverse = copied;
        i = 1;
        j = 1;
        while (for_traverse)
        {
            // if current node random is pointing to null
            if (hash[i] == -1)
            {
                for_traverse->random = nullptr;
            }
            else
            {
                // now to to that index according to map
                Node *temp = copied;
                j = 1;
                while (j < hash[i])
                {
                    temp = temp->next;
                    j++;
                }
                for_traverse->random = temp; // after found connect random
            }
            for_traverse = for_traverse->next;
            i++;
        }
        return copied;
    }
    void printList(Node *head)
    {
        Node *temp = head;
        cout << "Printing Linked List:" << endl;
        while (temp != nullptr)
        {
            cout << "Node Value: " << temp->val << " ";

            if (temp->next)
                cout << "| Next: " << temp->next->val << " ";
            else
                cout << "| Next: NULL ";

            if (temp->random)
                cout << "| Random: " << temp->random->val << endl;
            else
                cout << "| Random: NULL" << endl;

            temp = temp->next;
        }
    }
};
int main()
{
    LinkedList ll;

    ll.insert(7);
    ll.insert(13);
    ll.insert(11);
    ll.insert(10);
    ll.insert(1);

    Node *head = ll.getHead();

    // setting random manually for testing
    head->random = nullptr;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next; // 11 → 1
    head->next->next->next->random = head->next->next;       // 10 → 11
    head->next->next->next->next->random = head;             // 1 → 7

    ll.print();
    Node *copied = ll.copyRandomList(head);

    ll.printList(copied);
    return 0;
}
