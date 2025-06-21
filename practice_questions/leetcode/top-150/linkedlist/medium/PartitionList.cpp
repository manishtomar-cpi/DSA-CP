#include <iostream>
#include <unordered_map>
using namespace std;

#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {};
    ListNode() : val(0), next(nullptr) {};
};

class LinkedList
{
private:
    ListNode *head;

public:
    LinkedList() : head(nullptr) {};

    void insert(int val)
    {
        ListNode *temp = new ListNode(val);
        if (head == nullptr)
        {
            head = temp;
        }
        else
        {
            ListNode *temp1 = head;
            while (temp1->next)
            {
                temp1 = temp1->next;
            }
            temp1->next = temp;
        }
        cout << val << " inserted!" << endl;
    }
    void print()
    {
        if (head == nullptr)
        {
            cout << "empty!" << endl;
            return;
        }
        else
        {
            ListNode *temp = head;
            while (temp)
            {
                cout << temp->val << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    ListNode *getHead()
    {
        return head;
    }
    void printByHead(ListNode *head)
    {
        ListNode *temp = head;
        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    /*
    Goal → Rearrange Linked List such that:
        - All nodes with value < x come first
        - All nodes with value >= x come after
        - Original relative order should be maintained

    Step 1 → Edge Case Handling:
        - If head is NULL → return NULL
        - If only 1 node present → return head (no partition needed)

    Step 2 → Create 2 Dummy Nodes:
        - smallDummy → For storing nodes < x
        - largeDummy → For storing nodes >= x
        - Maintain smallTail and largeTail for both lists

    Step 3 → Traverse Original Linked List:
        - If (current->val < x)
            → Add node in smaller list (smallTail->next = current)
            → Move smallTail forward
        - Else
            → Add node in larger list (largeTail->next = current)
            → Move largeTail forward

    Step 4 → Final Connection:
        - smallTail->next = largeDummy->next (Merge both lists)
        - largeTail->next = NULL (Avoid cycle at end)

    Step 5 → Return Final Answer:
        - Return smallDummy->next (New head after partition)

    ?Time Complexity → O(N)
    ?Space Complexity → O(1)  (No extra space except dummy nodes)

    Why it Works?
    - Dummy Nodes Handle Edge Cases cleanly
    - No extra array/vector used
    - Relative Order Preserved
    - Handles cases where:
        - x is not present
        - All values < x
        - All values >= x
    */

    ListNode *partition(int x)
    {
        if (!head)
        {
            return nullptr;
        }
        ListNode *small = new ListNode();
        ListNode *small_last = small;
        ListNode *large = new ListNode();
        ListNode *large_last = large;
        ListNode *temp = head;
        while (temp)
        {
            if (temp->val < x)
            {
                small_last->next = temp;
                small_last = small_last->next;
            }
            else
            {
                large_last->next = temp;
                large_last = large_last->next;
            }
            temp = temp->next;
        }
        small_last->next = large->next;
        large_last->next = nullptr;
        return small->next;
    }
};

int main()
{
    LinkedList l1;
    l1.insert(1);
    l1.insert(4);
    l1.insert(3);
    l1.insert(2);
    l1.insert(5);
    l1.insert(2);

    ListNode *head = l1.partition(3);
    l1.printByHead(head);

    l1.print();
    return 0;
}