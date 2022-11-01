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

	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}

	Node()
	{
		this->data=-1;
		this->next=NULL;
	}
};
Node* mergeEvenElements(Node* head1,Node* head2)
{
	Node* temp1=head1->next;
	Node* temp2=head2->next;
	Node* finalHead;
	Node* finalTemp=finalHead;
	while (temp1!=NULL || temp2!=NULL)
	{
		
		
		if (temp1!=NULL)
		{
			finalTemp->next=temp1;
			temp1=temp1->next;
		}
		if (temp2!=NULL)
		{
			finalTemp->next=temp2;
			temp2=temp2->next;
		}
		finalTemp=finalTemp->next;
	}
	finalTemp->next=NULL;
	finalHead=finalHead->next;
	return finalHead;
}
