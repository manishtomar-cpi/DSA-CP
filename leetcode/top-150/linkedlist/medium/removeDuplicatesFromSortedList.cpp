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

    ListNode *removeDuplicates()
    { //! TIME: O(N), SPACE : O(N)
        unordered_map<int, int> hash;
        ListNode *temp = head;

        // first fill the map accordingly
        while (temp)
        {
            hash[temp->val]++;
            temp = temp->next;
        }
        // for head removal
        ListNode *dummy = new ListNode();
        ListNode *last = dummy;
        temp = head;

        // now traverse ll
        while (temp)
        {
            // if the value comes only once -> update last
            if (hash[temp->val] == 1)
            {
                last->next = temp;
                last = last->next;
            }
            temp = temp->next;
        }
        // at last , last -> next should be null
        last->next = nullptr;
        return dummy->next;
    }

    /*
     Goal: Remove all duplicates from a **sorted** linked list.
     Only values that appear exactly once should remain.

     ?TIME: O(N) — one pass
     ?SPACE: O(1) — in-place

     Explanation:
     - Use 3 pointers:
         1. slow → current node we're evaluating
         2. fast → next node for comparison
         3. checker → previous node to help detect duplicates
     - Use a dummy node to build the new list safely (even when head gets removed).
     - Use 'last' pointer to track the tail of the new list.

     Step-by-step:
     1. Traverse the list using slow and fast.
     2. If slow->val != fast->val, it means:
         → slow is a unique node (only if not equal to checker).
         → add slow to result list.
     3. If slow->val == fast->val, skip it (do nothing).
     4. Update checker = slow each time to track previous node.
     5. After loop, we check for the last node (slow) separately because fast becomes null and last pair won’t be handled inside loop.
     6. Ensure the last->next = nullptr to avoid any trailing duplicates.

     Example:
     Input : 1 → 2 → 3 → 3 → 4 → 4 → 5
     Output: 1 → 2 → 5
 */

    ListNode *remove_duplicate_optimal()
    {
        if (!head)
            return nullptr; // empty list case
        if (!head->next)
            return head; // single node case

        ListNode *slow = head;            // current node
        ListNode *fast = head->next;      // next node to compare
        ListNode *checker = nullptr;      // helps detect duplicates
        ListNode *dummy = new ListNode(); // dummy node for safe start
        ListNode *last = dummy;           // tracks last added to result list

        while (fast)
        {
            if (slow->val != fast->val)
            {
                if (!checker)
                {
                    last->next = slow; // first node, safe to add
                    last = last->next;
                }
                else if (checker->val != slow->val)
                {
                    last->next = slow; // safe to add if not duplicate
                    last = last->next;
                }
            }
            checker = slow;    // update checker
            slow = fast;       // move slow
            fast = fast->next; // move fast
        }

        // After loop, check last node (slow) if it’s not a duplicate
        if (last->val != slow->val)
        {
            if (checker && checker->val == slow->val)
            {
                last->next = nullptr; // skip duplicate
            }
            else
            {
                last->next = slow; // add last node
                last = last->next;
                last->next = nullptr; // ensure end
            }
        }

        if (last->val == slow->val)
        {
            last->next = nullptr;
        }

        return dummy->next; // return result head
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
};

int main()
{
    LinkedList l1;
    l1.insert(1);
    l1.insert(1);
    // l1.insert(2);
    // l1.insert(3);
    // l1.insert(3);
    // l1.insert(4);
    // l1.insert(4);
    // l1.insert(5);

    l1.print();

    ListNode *head = l1.remove_duplicate_optimal();
    l1.printByHead(head);

    return 0;
}