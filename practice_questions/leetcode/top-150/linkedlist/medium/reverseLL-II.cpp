#include <iostream>
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
    /*
    MY APPROACH:

    → I am not reversing the whole segment like standard approach.
    → I am simply swapping left node and right node one by one.

    STEPS I FOLLOWED:
    1. Take 2 pointers:
       - current_left → to reach left position
       - current_right → to reach right position

    2. Also keep prev_left and prev_right for connecting links.

    3. Special Case:
       - If left is 1 → means head is involved so I handled head swapping carefully.
       - If left and right are side by side (adjacent) → I handled that by checking prev_right == current_left.

    4. After swapping:
       - Increase left++
       - Decrease right--
       - Reset all pointers again to head (because in singly linked list I can't go back).

    5. Continue till left >= right.

    !TIME COMPLEXITY → O(N²)
    → Because I am traversing again and again from head for left and right.

    SPACE COMPLEXITY → O(1)
    → No extra space used, everything is done by pointers.

    CONNECTION EXPLANATION IN CODE:
    ----------------------------------

    CASE 1 → When left is 1
    Means I am swapping the head node with the right node.
    Example:
    Input List: [1 → 2 → 3 → 4 → 5]
    left = 1, right = 4
    Nodes to swap: 1 (head) and 4

    Steps:
    1. temp1 = head->next  → 2
    2. temp2 = head        → 1
    3. temp3 = current_right->next → 5

    Now make head = current_right → head = 4

    Now connections:
    - If left and right are not side by side:
    head->next = temp1  → 4→2
    prev_right->next = temp2 → node before 4 (which was 3) will point to 1
    temp2->next = temp3 → 1→5

    Final after swap:
    [4 → 2 → 3 → 1 → 5]


    CASE 2 → If left and right are adjacent
    Condition: prev_right == current_left
    Example:
    List: [1 → 2 → 3 → 4 → 5]
    left = 2, right = 3
    Swapping 2 and 3

    Why special care?
    Because if you directly connect without care → it may create a cycle (node pointing to itself).

    Connections:
    current_right->next = current_left → 3→2
    prev_right->next = temp3 (next of right node) → 2→4

    Final after swap:
    [1 → 3 → 2 → 4 → 5]

    CASE 3 → Normal Case
    left and right are not adjacent & left != head
    Example:
    List: [1 → 2 → 3 → 4 → 5 → 6]
    left = 2, right = 5
    Swapping 2 and 5

    Steps:
    prev_left->next = current_right  → 1→5
    prev_right->next = current_left  → 4→2
    current_right->next = temp_left  → 5→3
    current_left->next = temp_right  → 2→6

    Final after swap:
    [1 → 5 → 3 → 4 → 2 → 6]

*/

    ListNode *reverseBetween(int left, int right)
    {
        int i = 1;
        int j = 1;
        ListNode *current_left = head;  // current left first pointing on head because we start from head we will go the left mark
        ListNode *prev_left = nullptr;  // move behind head for connection
        ListNode *current_right = head; // same current is start from head
        ListNode *prev_right = nullptr; // this move behind the right one
        while (left < right)
        { // when they are not crossed or equal

            // move i towards left
            while (i < left)
            {
                prev_left = current_left;
                current_left = current_left->next;
                i++;
            }

            // move roght towards right
            while (j < right)
            {
                prev_right = current_right;
                current_right = current_right->next;
                j++;
            }
            //! edge case - If left is 1 → means head is involved
            if (prev_left == nullptr)
            {
                // for connection
                ListNode *temp1 = head->next;
                ListNode *temp2 = head;
                ListNode *temp3 = current_right->next;
                head = current_right;

                //! edge case 2 -If left and right are side by side (adjacent) → handled that by checking prev_right == current_left. why this because prev_right and current left pointing on same node it will create the cycle on same node
                if (prev_right == current_left)
                {
                    current_right->next = current_left;
                    prev_right->next = temp3;
                }
                else
                {
                    head->next = temp1;
                    prev_right->next = temp2;
                    temp2->next = temp3;
                }
            }
            else
            {
                ListNode *temp_left = current_left->next;
                ListNode *temp_right = current_right->next;
                prev_left->next = current_right;
                //! edge case 2 -If left and right are side by side (adjacent) → handled that by checking prev_right == current_left.
                if (prev_right == current_left)
                {
                    current_right->next = current_left;
                    prev_right->next = temp_right;
                }
                else
                {
                    prev_right->next = current_left;
                    current_right->next = temp_left;
                    current_left->next = temp_right;
                }
            }
            left++;
            right--;
            j = 1;
            i = 1;
            prev_right = nullptr;
            current_right = head;
            prev_left = nullptr;
            current_left = head;
        }
        return head;
    }
};

int main()
{
    LinkedList l1;
    l1.insert(1);
    l1.insert(2);
    // l1.insert(3);
    // l1.insert(4);
    // l1.insert(5);

    l1.print();
    l1.reverseBetween(1, 2);
    l1.print();
    return 0;
}