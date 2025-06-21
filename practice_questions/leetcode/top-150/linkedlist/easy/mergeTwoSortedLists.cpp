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
    void printList(ListNode *head)
    {
        while (head)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    /*
    Logic:
    - We are given two sorted linked lists list1 and list2.
    - The goal is to merge them into a single sorted linked list.

    Steps:
    1. Edge Case Handling:
       - If either list1 or list2 is empty, return the other list directly.
       - If both are empty, return nullptr.

    2. Create a new linked list:
       - Initialize `sorted` pointer to store the head of the new merged list.
       - Use `last` pointer to track the last node of the new list.

    3. Traverse both lists:
       - Compare current nodes of list1 and list2.
       - Whichever has the smaller value, create a new node with that value.
       - Append this new node at the end of the `sorted` list using `last->next`.
       - Move the corresponding list pointer forward.

    4. Append remaining nodes:
       - If any nodes are left in either list1 or list2, create new nodes for them and attach at the end of the merged list.

    5. Return `sorted` head pointer.

    ?Time Complexity: O(n + m)
        - Where n = size of list1, m = size of list2
        - Because we traverse both lists completely.

    ?Space Complexity: O(n + m)
        - Because we are creating new nodes for every element from both lists.
        Note:
        - This approach is correct and works for all test cases.
        - But it's not space optimal because the question asks us to merge by reusing existing nodes (without creating new nodes).
    */

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // edge case
        if (list1 && !list2)
        {
            return list1;
        }
        if (list2 && !list1)
        {
            return list2;
        }
        if (!list1 && !list2)
        {
            return nullptr;
        }
        ListNode *sorted = nullptr;
        ListNode *last = nullptr;
        while (list1 && list2) // first travers any one list whole
        {
            if (list1->val <= list2->val)
            {
                ListNode *temp = new ListNode(list1->val);
                if (sorted == nullptr)
                {
                    sorted = temp;
                    last = sorted;
                }
                else
                {
                    last->next = temp;
                    last = last->next;
                }
                list1 = list1->next;
            }
            else
            {
                ListNode *temp = new ListNode(list2->val);
                if (sorted == nullptr)
                {
                    sorted = temp;
                    last = sorted;
                }
                else
                {
                    last->next = temp;
                    last = last->next;
                }
                list2 = list2->next;
            }
        }
        if (list1)
        {
            while (list1)
            {
                ListNode *temp = new ListNode(list1->val);

                last->next = temp;
                last = last->next;
                list1 = list1->next;
            }
        }
        if (list2)
        {
            while (list2)
            {
                ListNode *temp = new ListNode(list2->val);

                last->next = temp;
                last = last->next;
                list2 = list2->next;
            }
        }
        return sorted;
    }

    ListNode *mergeTwoLists_optimal(ListNode *list1, ListNode *list2)
    {
        // edge cases
        if (list1 && !list2)
        {
            return list1;
        }
        if (list2 && !list1)
        {
            return list2;
        }
        if (!list1 && !list2)
        {
            return nullptr;
        }
        ListNode *sorted = new ListNode;
        ListNode *last = sorted;
        while (list1 && list2)
        {
            //if list1's current value is sorter 
            if (list1->val <= list2->val)
            {
                //add list1 next 
                last->next = list1;
                last = last->next;
                list1 = list1->next;
            }
            else
            {
                //add list 2 next
                last->next = list2;
                last = last->next;
                list2 = list2->next;
            }
        }
        //if any of the elements left 
        if (list1)
        {
            last->next = list1;
        }
        if (list2)
        {
            last->next = list2;
        }
        return sorted->next; //? why next, because in sorted it's 0 in head because we created new ListNode and constructor push 0 in head
    }
    /*
Approach: Merge Two Sorted Linked Lists (Optimal In-place Approach)
--------------------------------------------------------------------

Idea:
- We are given two sorted linked lists list1 and list2.
- The goal is to merge them into a single sorted linked list.
- We will not create new nodes; instead, we will reuse the existing nodes
  by changing their next pointers.

Steps:
1. Handle Edge Cases:
   - If list1 is empty → return list2.
   - If list2 is empty → return list1.
   - If both are empty → return nullptr.

2. Create a dummy node (sorted):
   - This helps avoid handling edge cases separately when adding the first node.
   - Pointer `last` will always point to the last node of the merged list.

3. Traverse both lists:
   - Compare current nodes of list1 and list2.
   - Whichever node has the smaller value, attach it to `last->next`.
   - Move `last` forward and also move the corresponding list pointer forward.

4. Attach remaining nodes:
   - After one list ends, directly attach the remaining nodes of the other list to `last->next`.

5. Return merged list:
   - Return `sorted->next` (because `sorted` was a dummy node).

--------------------------------------------------------------------

Example:
Input:
list1 = [1, 2, 4]
list2 = [1, 3, 4]

Dry Run:
- Start with dummy node → sorted
- Compare 1 and 1 → Attach list1's 1
- Compare 2 and 1 → Attach list2's 1
- Compare 2 and 3 → Attach list1's 2
- Compare 4 and 3 → Attach list2's 3
- Compare 4 and 4 → Attach list1's 4
- Attach remaining list2's 4

Final Merged List:
[1, 1, 2, 3, 4, 4]

--------------------------------------------------------------------

Time Complexity: O(n + m)
    - Traverse both lists completely.
    - Where n = size of list1, m = size of list2.

Space Complexity: O(1)
    - No extra space used apart from dummy node.
    - Nodes are reused — optimal solution.

*/
};

int main()
{
    LinkedList l1;
    cout << boolalpha;
    l1.insert(-9);
    l1.insert(3);
    // l1.insert(3);

    LinkedList l2;
    l2.insert(5);
    l2.insert(7);
    // l2.insert(9);

    l1.print();
    l2.print();

    ListNode *mergedHead = l1.mergeTwoLists_optimal(l1.getHead(), l2.getHead());
    l1.printList(mergedHead);
    return 0;
}