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
};
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
            if(head1==NULL){
            return head2;
        }
        if(head2==NULL){
            return head1;
        }
    Node *fH= ((head1->data)<=(head2->data))?head1:head2;
	Node *fT=fH;
    if (fH==head1)
	{
		head1=head1->next;
	}
	else
	{
		head2=head2->next;
	}
	while (head1!=NULL && head2!=NULL)
	{

		if ((head1->data)<=(head2->data))
		{
			fT->next=head1;
			fT=head1;
			head1=head1->next;
		}
		else
		{
			fT->next=head2;
			fT=head2;
			head2=head2->next;
		}
        
	}
	if (head1==NULL)
	{
		fT->next=head2;
        fT=head2;
	}
	else
	{
		fT->next=head1;
        fT=head1;
	}
	return fH;
}
