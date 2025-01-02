#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    void create(Node *&head, int a[], int size)
    {
        head = new Node;
        head->data = a[0];
        head->next = nullptr;

        Node *last = head;

        for (int i = 1; i < size; i++)
        {
            Node *temp = new Node;
            temp->data = a[i];
            temp->next = nullptr;
            last->next = temp;
            last = temp;
        }
    }

    void display(Node *head)
    {
        cout << "[ ";
        while (head != nullptr)
        {
            cout << head->data << " ";
            head = head->next;
        }
        cout << "]" << endl;
    }

    bool isLoop(Node *head)
    {
        Node *first = head;
        Node *second = head;
        while (second != nullptr && second->next != nullptr) // we give that condition because where their is no loop and ll have odd number of element then second->next->next will go to the segmentation fault
        {
            second = second->next->next;            // this is moving faster
            first = first->next;                    // this is moving slower
            if (first == second) // when their is circular track and one car is moving fast then second then it should meet the slower one
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    int a[] = {1, 4, 3, 7, 5, 9, 10};
    int size = 7;
    Node *head = nullptr;
    Node n1;
    n1.create(head, a, size);
    n1.display(head);
    cout << boolalpha;
    cout << n1.isLoop(head) << endl;

    return 0;
}