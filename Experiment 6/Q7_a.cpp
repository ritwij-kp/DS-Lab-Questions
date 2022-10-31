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

void printAlternate(Node* head)
{
	Node* temp=head;
	while (temp!=NULL)
	{
		cout<<temp->data<<endl;
		if (temp->next==NULL)
		{
			break;
		}
		else
		{
			temp=temp->next->next;
		}
	}
}