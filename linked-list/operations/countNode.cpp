#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    void createLL(int arr[], int size, Node *&head, Node *&end)
    {
        head = new Node;
        head->data = arr[0];
        head->next = nullptr;

        Node *last = head;
        for (int i = 1; i < size; i++)
        {
            Node *temp = new Node;
            temp->data = arr[i];
            temp->next = nullptr;
            last->next = temp;
            last = temp;
        }
        end = last;
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

    int countNode(Node *p)
    {
        int count = 0;

        while (p != nullptr)
        {
            count++;
            p = p->next;
        }

        return count;
    }

    void addNode(Node *&p, int data)
    {
        Node *temp = new Node;
        temp->data = data;
        temp->next = nullptr;
        p->next = temp;
        p = temp;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    Node *head = nullptr;
    Node *end = nullptr;
    Node n1;
    n1.createLL(arr, 5, head, end);
    n1.display(head);
    cout << n1.countNode(head) << endl;
    n1.addNode(end, 6);
    n1.display(head);
    cout << n1.countNode(head) << endl;
    return 0;
}