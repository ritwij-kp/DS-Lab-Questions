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

int length(Node *head)
{
	if (head->next == NULL)
	{
		return 1;
	}
	return length(head->next) + 1;
}

int findIntersection(Node *firstHead, Node *secondHead)
{
    int l1=length(firstHead);
	int l2=length(secondHead);
	if (l1>l2)
	{
		for (int i = 0; i < (l1-l2); i++)
		{
			firstHead=firstHead->next;
		}
	}
	else if (l1<l2)
	{
		for (int i = 0; i < (l2-l1); i++)
		{
			secondHead=secondHead->next;
		}
	}
	while (firstHead!=secondHead || firstHead->next!=secondHead->next)
	{
		firstHead=firstHead->next;
		secondHead=secondHead->next;
	}
	return firstHead->data;
}