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

class Queue {
	Node* head;
	Node* tail;
	int size;
   public:
    Queue() {
		head=NULL;
		tail=NULL;
		size=0;
	}

	int getSize() {
		return size;
	}

    bool isEmpty() {
		return size==0;
	}

    void enqueue(int data) {
		Node* newNode= new Node(data);
		if (head==NULL)
		{
			head=newNode;
			tail=newNode;
		}
		else
		{
			tail->next=newNode;
			tail=newNode;
		}
        size++;
	}

    int dequeue() {
		if (head==NULL)
		{
			return -1;
		}
		int ans=head->data;
		Node* oldHead=head;
        head=head->next;
		delete oldHead;
        size--;
		return ans;
    }

    int front() {
		if (head==NULL)
		{
			return -1;
		}
		
        return head->data;
    }
};