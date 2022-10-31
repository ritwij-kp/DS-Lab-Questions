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

Node *midPoint(Node *head)
{
    Node* slow=head;
	Node* fast=head;
	while (fast->next!=NULL && (fast->next)->next!=NULL)
	{
		slow=slow->next;
		fast= (fast->next)->next;
	}
	return slow;
}

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

Node *mergeSort(Node *head)
{
    if (head==NULL)
    {
        return head;
    }
	if (head->next==NULL)
	{
		return head;
	}
	Node *tail=midPoint(head);
	Node *head2=tail->next;
	tail->next=NULL;
	return mergeTwoSortedLinkedLists(mergeSort(head),mergeSort(head2));
}