#include <iostream>
#include <string>
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
    Character -> ASCII Value
        '0'	48
        '1'	49
        '2'	50
        '3'	51
        '4'	52
        '5'	53
        '6'	54
        '7'	55
        '8'	56
        '9'	57
Approach:

 Problem Statement:
 - Given two non-empty linked lists l1 and l2 representing two non-negative integers.
 - The digits are stored in reverse order.
 - Each node contains a single digit.
 - Add the two numbers and return the sum as a linked list.

 Key Points:
 - No leading zeros in numbers except for the number 0 itself.
 - Directly add the numbers digit by digit.
 - Handle carry (reminder) properly.
 - No extra storage like strings or integers required.
 - Build the final answer linked list while traversing l1 and l2.

 Steps of the Algorithm:
 1. Initialize:
    - curr_sum to store sum of current digits.
    - reminder (carry) to store carry after every addition.
    - final_list (dummy node) for ease of attaching nodes.
    - last pointer to always point to the last node of the final list.

 2. Traverse both l1 and l2:
    - Add corresponding digits.
    - If reminder is true, add 1 to sum.
    - If sum >= 10, subtract 10 and set reminder = true.
    - Create new node with sum and attach to final_list.

 3. Process Remaining Nodes:
    - If l1 or l2 is still left, repeat the same process.

 4. Final Step:
    - If reminder is still true after loop ends, add a new node with value 1.

 Return:
 - final_list->next (since head is a dummy node with value 0)


 Dry Run Example:
 l1 = [2, 4, 3]  → Represents 342
 l2 = [5, 6, 4]  → Represents 465

 Addition:
 342 + 465 = 807

 Output Linked List: [7, 0, 8]


? Time Complexity: O(max(n, m))
 - Where n is size of l1 and m is size of l2.

? Space Complexity: O(max(n, m))
 - Space required for storing the result linked list.

 */

    ListNode *additon(ListNode *l1, ListNode *l2)
    {
        int curr_sum = 0;      // we will store the current sum -> one by one
        bool reminder = false; // tell the reminder

        ListNode *final_list = new ListNode(); // new node
        ListNode *last = final_list;           // to toggle last in constant time
        // first process any one complete list
        while (l1 && l2)
        {
            curr_sum = l1->val + l2->val; // calculate current sum
            // if reminder add 1 in current sum
            if (reminder)
            {
                curr_sum += 1;
                reminder = false;
            }
            // check reminder
            if (curr_sum >= 10)
            {
                curr_sum -= 10;
                reminder = true;
            }
            // make a node of the result we get and add into final list
            ListNode *temp = new ListNode(curr_sum);
            last->next = temp;
            last = last->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        // if any one of the list left follow the same process
        while (l1)
        {
            if (reminder)
            {
                curr_sum = l1->val + 1;
                reminder = false;
            }
            else
            {
                curr_sum = l1->val;
            }
            if (curr_sum >= 10)
            {
                curr_sum -= 10;
                reminder = true;
            }
            ListNode *temp = new ListNode(curr_sum);
            last->next = temp;
            last = last->next;

            l1 = l1->next;
        }
        while (l2)
        {
            if (reminder)
            {
                curr_sum = l2->val + 1;
                reminder = false;
            }
            else
            {
                curr_sum = l2->val;
            }
            if (curr_sum >= 10)
            {
                curr_sum -= 10;
                reminder = true;
            }
            ListNode *temp = new ListNode(curr_sum);
            last->next = temp;
            last = last->next;

            l2 = l2->next;
        }
        // at end if remindr left add 1 at the end
        if (reminder)
        {
            ListNode *temp = new ListNode(1);
            last->next = temp;
            last = last->next;
        }
        return final_list->next; // why because on head its '0'
    }
};

int main()
{
    LinkedList l1;
    l1.insert(9);
    l1.insert(9);
    l1.insert(9);
    l1.insert(9);
    l1.insert(9);
    l1.insert(9);
    l1.insert(9);

    LinkedList l2;
    l2.insert(9);
    l2.insert(9);
    l2.insert(9);
    l2.insert(9);

    l1.print();
    l2.print();

    ListNode *added = l1.additon(l1.getHead(), l2.getHead());

    l1.printList(added);
    return 0;
}