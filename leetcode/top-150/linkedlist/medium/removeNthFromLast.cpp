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
    ListNode *removed(int n)
    {
        // int size = 0;
        // ListNode *temp = head;
        // // go till last to calculate size
        // while (temp)
        // {
        //     size++;
        //     temp = temp->next;
        // }
        // // edge case when we need to remove head
        // if (size - n == 0)
        // {
        //     return head->next;
        // }

        // // two pointer for making connection
        // ListNode *prev = nullptr;
        // ListNode *current = head;

        // // traverse till the node need to remove
        // for (int i = 1; i <= (size - n); i++)
        // {
        //     prev = current;
        //     current = current->next;
        // }
        // // now prev is at one behind the node need to remove make prev =  curr->next;
        // prev->next = current->next;
        // delete current;

        // return head;

        /*
            One Pass Approach:

            1. Create a dummy node → handles head deletion safely.
            !2. Move the fast pointer n+1 steps ahead → this creates a gap of n between fast and slow.
            !   (Why? Because by moving fast n+1 steps ahead, we ensure that when fast reaches the end,
            !   the slow pointer will be exactly one node before the one we want to delete.)
            3. Move both slow & fast pointers together until fast reaches NULL.
            4. At this point, slow is just before the target node.
            5. Skip the target node using:
               slow->next = slow->next->next;
        */

        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = dummy;

        // moved fast to n+1 times to create gap on n between slow and fast
        for (int i = 0; i < n + 1; i++)
        {
            fast = fast->next;
        }

        // now move fast and slow one by one teill fast became null
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return dummy->next;
    }
};

int main()
{
    LinkedList l1;
    l1.insert(1);
    // l1.insert(2);
    // l1.insert(3);
    // l1.insert(4);
    // l1.insert(5);

    l1.print();
    l1.removed(1);
    l1.print();

    return 0;
}