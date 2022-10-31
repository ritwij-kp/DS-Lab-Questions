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

class Stack
{
    Node *head;
    int size;
    Node *next;

public:
    Stack()
    {
        head=NULL;
        size=0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size==0;
    }

    void push(int element)
    {
        Node* newNode=new Node(element);
        newNode -> next=head;
        head=newNode;
        size++;
    }

    int pop()
    {
        if(size==0){
            return -1;
        }
        int ans;
        ans=head->data;
        Node *trash=head;
        head= head ->next;
        delete trash;
        size--;
        return ans;
    }

    int top()
    {
        if(size==0){
            return -1;
        }
        return head ->data;
    }
};