#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#include <algorithm>
#include <unordered_map>
class Node
{
public:
	string data;
	Node *next;

    Node()
    {
        this->data=-1;
        this->next=NULL;
    }
	Node(string data)
	{
		this->data = data;
		this->next = NULL;
	}
};

void insert(string n, Node* head)
{
    if (head->next==NULL)
    {
        Node* newNode = new Node(n);
        head->next=newNode;
        return;
    }
    insert(n,head->next);
}

int findNode(Node *head, string n)
{
	int ans;
	if (head == NULL)
	{
		return -1;
	}
	if ((head->data) == n)
	{
		return 0;
	}
	ans = findNode(head->next, n);
	if (ans == -1)
	{
		return -1;
	}
	else
	{
		return ans + 1;
	}
}

Node *deleteNode(Node *head, int pos)
{
	int count = 0;
	Node *temp = head;
	if (pos == 0)
	{
		return head->next;
	}

	while (temp != NULL && count < (pos - 1))
	{
		temp = temp->next;
		count++;
	}

	if ((temp->next) != NULL)
	{
		Node *a = temp->next;
		temp->next = a->next;
		delete a;
	}
	return head;
}

void deleteLL(Node* head)
{
    if (head->next==NULL)
    {
        delete head;
        return;
    }
    deleteLL(head->next);
    delete head;
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

Node* copyLL(Node* head)
{
    Node* newHead=head;
    head=head->next;
    Node* temp=newHead;
    while (head!=NULL)
    {
        Node* newNode=head;
        temp->next=newNode;
        head=head->next;
        temp=temp->next;
    }
    temp->next=NULL;
    return newHead;
}