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
	int data;
	Node *next;

    Node()
    {
        this->data=-1;
        this->next=NULL;
    }
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

void swapPairs(Node* head)
{
	Node* temp=head;
	Node* prev=head->next;
	while (temp!=NULL && temp->next!=NULL)
	{
		if (temp==head)
		{
			Node* forward=temp->next->next;
			head=temp->next;
			head->next=temp;
			temp->next=forward;
			prev=temp;
			temp=temp->next;
			continue;
		}
		Node* forward=temp->next->next;
		prev->next=temp->next;
		temp->next->next=temp;
		temp->next=forward;
		prev=temp;
		temp=temp->next;
	}
}