#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    void create(Node *&head, int arr[], int size)
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

    int sumOfLL(Node *head){
        int sum = 0;
        while (head !=nullptr){
         sum+=head ->data;
         head = head->next;            
        }

        return sum;
    }
};

int main (){
    int arr [] = {1,2,3};
    Node *head = nullptr;

    Node n1;
    n1.create(head,arr,3);
    n1.display(head);

    cout << n1.sumOfLL(head) << endl;

    return 0;
}