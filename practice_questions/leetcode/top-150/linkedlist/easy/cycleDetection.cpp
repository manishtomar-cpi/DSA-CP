#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {};
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

    void makeCycle(int pos)
    {
        ListNode *temp = head;
        ListNode *cycleNode;

        int i = 0;
        while (temp->next)
        {
            if (i == pos)
            {
                cycleNode = temp;
            }
            temp = temp->next;
            i++;
        }
        temp->next = cycleNode;
        cout << "cycleCreated " << temp->val << " --> " << cycleNode->val << endl;
    }
    //? Floyd's Cycle Detection Algorithm
    /*
    Floyd's Cycle Detection Algorithm (Slow & Fast Pointer)

    Steps:
    1. Slow moves 1 step, Fast moves 2 steps.
    2. If cycle exists → They will meet.
    3. If fast or fast->next is nullptr → No cycle. Means we reached at the end of linkedlist

    ?Time: O(n)
    ?Space: O(1)
    */

    bool hasCycle()
    {
        if (head == nullptr)
        {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    LinkedList l1;
    cout << boolalpha;
    l1.insert(3);
    // l1.insert(-2);
    // l1.insert(0);
    // l1.insert(4);
    l1.print();
    // l1.makeCycle(0);
    cout << l1.hasCycle() << endl;

    return 0;
}