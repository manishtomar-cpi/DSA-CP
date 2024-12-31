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

    Node *merge(Node *firstHead, Node *secondHead)
    {
        Node *third = nullptr;
        Node *last = nullptr;

        if (firstHead->data < secondHead->data)
        {
            third = firstHead;
            last = firstHead;
            firstHead = firstHead->next;
        }
        else if (firstHead->data > secondHead->data)
        {
            third = secondHead;
            last = secondHead;
            secondHead = secondHead->next;
        }
        while (firstHead != nullptr && secondHead != nullptr)
        {
            if (firstHead->data < secondHead->data)
            {
                last->next = firstHead;
                last = firstHead;
                firstHead = firstHead->next;
            }
            else
            {
                last->next = secondHead;
                last = secondHead;
                secondHead = secondHead->next;
            }
        }
        while (firstHead != nullptr)
        {
            last->next = firstHead;
            last = firstHead;
            firstHead = firstHead->next;
        }
        while (secondHead != nullptr)
        {
            last->next = secondHead;
            last = secondHead;
            secondHead = secondHead->next;
        }
        return third;
    }
};

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int arr2[] = {2, 4, 6, 8, 10};
    Node *firstHead = nullptr;
    Node *secondHead = nullptr;
    Node n1;
    n1.createLL(arr, 6, firstHead);
    n1.createLL(arr2, 5, secondHead);
    n1.display(firstHead);
    n1.display(secondHead);
    Node *merged = nullptr;
    merged = n1.merge(firstHead, secondHead);
    n1.display(merged);
    return 0;
}