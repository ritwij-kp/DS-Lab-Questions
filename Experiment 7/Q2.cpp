#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
	node(int val)
	{
		data = val;
		left = right = NULL;
	}
} Node;
void insertBeforeKey(Node *n, int givenKey, Node *first)
{
	Node *prev = NULL;
	while (first->data != givenKey)
	{
		prev = first;
		first = first->right;
	}
	prev->right = n;
	first->left = n;
	n->left = prev;
	n->right = first;
}
void traverse(Node *first)
{
	while (first)
	{
		cout << first->data << " ";
		first = first->right;
	}
	cout << endl;
}
void insertAfterKey(Node *n, int givenKey, Node *first)
{
	Node *next = first->right;
	while (first->data != givenKey)
	{
		next = next->right;
		first = first->right;
	}
	first->right = n;
	next->left = n;
	n->left = first;
	n->right = next;
}
void reverseTraverse(Node *first)
{
	if (first == NULL)
		return;
	reverseTraverse(first->right);
	cout << first->data << " ";
}
void removeKeyNode(Node *first, int key)
{
	Node *prev = NULL;
	Node *next = first->right;
	while (first->data != key)
	{
		prev = first;
		next = next->right;
		first = first->right;
	}
	prev->right = next;
	next->left = prev;
	free(first);
}
Node *accessNode(Node *first, int pos)
{
	if (pos == 1)
	{
		return first;
	}
	for (int i = 0; i < pos - 1; i++)
	{
		first = first->right;
	}
	return first;
}
void sortList(Node *first)
{
	vector<int> vec;
	Node *temp = first;
	while (first != NULL)
	{
		vec.push_back(first->data);
		first = first->right;
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++)
	{
		temp->data = vec[i];
		temp = temp->right;
	}
}
void deleteList(Node *first) { free(first); }
int main()
{
	Node *first = new Node(3);
	Node *second = new Node(5);
	Node *third = new Node(8);
	Node *fourth = new Node(1);
	first->right = second;
	second->left = first;
	second->right = third;
	third->left = second;
	third->right = fourth;
	fourth->left = third;
	Node *l = new Node(100);
	Node *r = new Node(200);
	cout << "doubly linked list is: ";
	traverse(first);
	insertBeforeKey(l, 8, first);
	cout << "Inserting Before key , doubly circular linked list is: ";
	traverse(first);
	insertAfterKey(r, 8, first);
	cout << "Inserting After key , doubly circular linked list is: ";
	traverse(first);
	cout << "Reverse traversal of doubly circular linked list is: ";
	reverseTraverse(first);
	cout << endl;
	removeKeyNode(first, 8);
	cout << "After removing the key , doubly circular linked list is: ";
	traverse(first);
	int pos = 3;
	cout << "node at position " << pos << " is " << accessNode(first, pos)->data;
	sortList(first);
	cout << endl;
	cout << "Sorted doubly circular linked list is: ";
	traverse(first);
	return 0;
}
