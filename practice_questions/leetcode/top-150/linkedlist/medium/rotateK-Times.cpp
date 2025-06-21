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
    Approach: Rotate a Linked List to the Right by K Places
   
    Intuition:
    When rotating a linked list right by `k` steps, we're essentially moving the last `k` nodes to the front.
    Instead of doing actual rotations `k` times (which is inefficient), we can calculate where the new head
    should be, break the list there, and reconnect accordingly.

    Step-by-Step:

    1. Handle Edge Cases:
       - If head is nullptr or k == 0 → no rotation needed → return head.
       - If there's only one node → return head.

    2. Calculate Size of the List:
       - Traverse the entire list once using `temp` to count total number of nodes.

    3. Optimize K:
       - If `k >= size`, then `k = k % size` because rotating `size` times brings it back to original position.
       - If after mod, `k == 0`, just return head (no change).

    4. Traverse to the Breakpoint:
       - Move a pointer `temp` to the `(size - k)`th node (this will become the new tail).
       - The node after this will be the **new head**.

    5. Break and Reconnect:
       - Store `temp->next` in `rotated`, which is the new head.
       - Set `temp->next = nullptr` to break the list.
       - Traverse from `rotated` to the end (`temp2`), and connect `temp2->next = head`.

    6. Return New Head:
       - The `rotated` pointer now points to the rotated head of the new list.

    ?Time Complexity: O(N)
        - One pass to calculate size.
        - Another to traverse to (size - k) node.
        - Another to reach end of rotated segment → Total O(N)

    ?Space Complexity: O(1)
        - No extra space used, only pointers.

    Example:
        Input:  head = [1, 2, 3, 4, 5],  k = 2
        Output: [4, 5, 1, 2, 3]
        Explanation:
            - Size = 5, k = 2 → rotate by last 2 elements.
            - Break at 5 - 2 = 3rd node (value = 3)
            - New head = 4, reconnect 5 to 1
*/

    ListNode *rotation(int k)
    {
        // Edge case → if linked list is empty
        if (head == nullptr)
        {
            return nullptr;
        }

        // Edge case → if only one node OR rotation is 0 → return as it is
        if (!head->next || k == 0)
        {
            return head;
        }

        int size = 0;
        ListNode *temp = head;
        ListNode *rotated = nullptr;

        // Calculate the size of linked list
        while (temp)
        {
            size++;
            temp = temp->next;
        }
        // Optimize k because rotating size times gives same list
        // Example: size = 5 and k = 15 → 15 rotations = 15 % 5 = 0
        if (k >= size)
        {
            if (k % size == 0)
            {
                return head; // No rotation needed
            }

            // Keep k in range of size
            while (k > size)
            {
                k -= size;
            }
        }

        temp = head;

        // Move temp to the (size - k)th node
        // Because after rotation, last k nodes will come to front accoridng to rotation
        for (int i = 1; i < (size - k); i++)
        {
            temp = temp->next;
        }

        // Now temp is at the node just before rotated part
        // rotated → will be new head after rotation
        rotated = temp->next;

        // Break the list from here because this node should be last node after rotation
        temp->next = nullptr;

        // Move temp2 to the end of rotated part
        ListNode *temp2 = rotated;
        while (temp2->next)
        {
            temp2 = temp2->next;
        }
        // Connect last node of rotated part to old head to make whole ll after rotation
        temp2->next = head;
        return rotated;
    }
};

int main()
{
    LinkedList l1;
    l1.insert(0);
    l1.insert(1);
    // l1.insert(2);
    // l1.insert(4);
    // l1.insert(5);

    l1.print();
    ListNode *head = l1.rotation(0);
    l1.printByHead(head);
    return 0;
}