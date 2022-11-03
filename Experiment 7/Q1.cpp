#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
	int data;
	struct node *right;
	node(int val)
	{
		data = val;
		right = NULL;
	}
} Node;
void insertBeforeKey(Node *first, int key, int size, Node *n)
{
	Node *prev = first;
	for (int i = 0; i < size - 1; i++)
	{
		prev = prev->right;
	}
	while (first->data != key)
	{
		prev = first;
		first = first->right;
	}
	prev->right = n;
	n->right = first;
}
void insertAfterKey(Node *first, int key, int size, Node *n)
{
	Node *next = first->right;
	while (first->data != key)
	{
		next = next->right;
		first = first->right;
	}
	first->right = n;
	n->right = next;
}
void traverse(Node *first, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << first->data << " ";
		first = first->right;
	}
	cout << endl;
}
void removeNode(Node *first, int key, int size)
{
	Node *prev = first;
	for (int i = 0; i < size - 1; i++)
	{
		prev = prev->right;
	}
	Node *next = first->right;
	while (first->data != key)
	{
		prev = prev->right;
		next = next->right;
		first = first->right;
	}
	prev->right = next;
	free(first);
}
void sortList(Node *first, int size)
{
	vector<int> vec;
	for (int i = 0; i < size; i++)
	{
		vec.push_back(first->data);
		first = first->right;
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++)
	{
		first->data = vec[i];
		first = first->right;
	}
}
void deleteList(Node *first) { free(first); }
int main()
{
	Node *first = new Node(3);
	Node *second = new Node(5);
	Node *third = new Node(8);
	Node *fourth = new Node(1);
	Node *n = new Node(100);
	Node *m = new Node(200);
	int size = 4;
	first->right = second;
	second->right = third;
	third->right = fourth;
	fourth->right = first;
	cout << "Circular linked list is: ";
	traverse(first, size);
	insertBeforeKey(first, 8, size, n);
	size++;
	cout << "Before inserting the key circular linked list is: ";
	traverse(first, size);
	insertAfterKey(first, 8, size, m);
	size++;
	cout << "After inserting the key circular linked list is: ";
	traverse(first, size);
	removeNode(first, 8, size);
	size--;
	cout << "After removing the node circular linked list is: ";
	traverse(first, size);
	sortList(first, size);
	cout << "Sorted circular linked list is: ";
	traverse(first, size);
	return 0;
}
