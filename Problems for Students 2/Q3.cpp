#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
    Node *prev;

	Node(int data)
	{
		this->data = data;
		this->next = NULL;
        this->prev=NULL;
	}
};
Node *takeInput()
{
	int data;
	cin >> data;
	Node *head = NULL;
	Node *tail = NULL;
	while (data != (-1))
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{

			tail->next = newNode;
            newNode->prev=tail;
			tail = newNode;
		}
		cin >> data;
	}

    head->prev=NULL;
	return head;
}
void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}
int main()
{
    Node* head=takeInput();
    int x;
    cin>>x;
    int i=0;
    Node* temp=head;
    while (temp!=NULL)
    {
        if (temp->prev!=NULL && temp->prev->data<x && temp->data<x)
        {
            temp=temp->next;
        }
        else if (temp->prev!=NULL && temp->data<x && temp->prev->data>=x)
        {
            Node* newTemp=temp;
            while (newTemp->prev!=NULL && newTemp->prev->data>=x)
            {
                Node* forward=newTemp->next;
                Node* backward=newTemp->prev->prev;
                if (backward==NULL)
                {
                    head->next=forward;
                    forward->prev=head;
                    newTemp->next=head;
                    head->prev=newTemp;
                    newTemp->prev=NULL;
                    head=newTemp;
                    break;
                }
                
                newTemp->next=newTemp->prev;
                newTemp->next->next=forward;
                newTemp->next->prev=newTemp;
                newTemp->prev=backward;
                backward->next=newTemp;
                forward->prev=newTemp->next;

            }
            if (newTemp->prev!=NULL)
            {
                temp=newTemp->prev;
            }
            else
            {
                temp=newTemp;
            }

        }
        else
        {
            temp=temp->next;
        }
    }
    print(head);
}
