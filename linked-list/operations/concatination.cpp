#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    void createLL(int arr[], int size, Node *&head)
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

    Node *concat(Node *firstHead, Node *secondHead)
    {
        Node *temp = firstHead;
        while (temp->next != nullptr) // means [upto last node]
        {
            temp = temp->next;
        }
        temp->next = secondHead;
        return firstHead;
    }
};

int main()
{
    int arr[] = {1, 2, 3};
    int arr2[] = {6, 7, 8};
    Node *firstHead = nullptr;
    Node *secondHead = nullptr;
    Node n1;
    n1.createLL(arr, 3, firstHead);
    n1.createLL(arr2, 3, secondHead);
    n1.display(firstHead);
    n1.display(secondHead);
    Node *concat = nullptr;
    concat = n1.concat(firstHead, secondHead);
    n1.display(concat);

    return 0;
}