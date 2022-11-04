#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int n)
    {
        this->data = n;
        this->next = NULL;
        this->prev = NULL;
    }
};

int getMin(Node *head)
{
    return head->data;
}
int getMax(Node *head)
{
    return head->prev->data;
}
void deleteMin(Node **head)
{
    int headData = (*head)->data;
    Node *trash = (*head);
    Node *tail = (*head)->prev;
    *head = (*head)->next;
    (*head)->prev = tail;
    tail->next = (*head);
    delete trash;
    cout << headData << " deleted" << endl;
}
void deleteMax(Node **head)
{
    int tailData = (*head)->prev->data;
    Node *trash = (*head)->prev;
    Node *tail = (*head)->prev->prev;
    (*head)->prev = tail;
    tail->next = (*head);
    delete trash;
    cout << tailData << " deleted" << endl;
}
void display(Node *head)
{
    Node *temp = head;
    while (temp->next != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}
int main()
{
    int n;
    cout << "Enter head data:" << endl;
    cin >> n;
    Node *head = new Node(n);
    Node *tail = head;
    int data = 0;
    while (true)
    {
        cout << "Enter element:" << endl;
        cin >> data;
        if (data == -1)
        {
            break;
        }

        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        tail->next = head;
        head->prev = tail;
    }
    cout << getMin(head) << endl
         << getMax(head) << endl;
    display(head);
    deleteMin(&head);
    deleteMax(&head);
    display(head);
}