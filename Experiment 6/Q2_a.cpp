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

Node *helper(Node *head, Node *tail, Node *fH)
{
	if (tail->next == NULL)
	{
		return tail;
	}

	fH=helper(head,(tail->next),fH);
	(tail->next)->next=tail;
	return fH;
}
Node *reverseLinkedListRec(Node *head)
{
    
    if (head==NULL || head->next==NULL){
        return head;
    }
	Node* fH;
	fH=helper(head,head,head);
    
	head ->next=NULL;
    
	return fH;
}

Node *reverseLinkedList(Node *head) {
	if (head==NULL)
	{
		return head;
	}
	
    Node* prev=NULL;
	Node* curr=head;
	Node* next=head->next;
	while (curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;
}