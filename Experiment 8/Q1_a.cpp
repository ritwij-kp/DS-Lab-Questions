#include <iostream>
using namespace std;
class Node
{

public:
	int data;
	Node *left;
	Node *right;
	Node(int d)
	{
		this->data = d;
		this->left = NULL;
		this->right = NULL;
	}
};
Node *build_tree(Node *root)
{
	int data;
	cout << "Enter the data" << endl;
	cin >> data;
	root = new Node(data);
	if (data == -1)
	{
		return NULL;
	}
	cout << "Enter the data for inserting in left of " << data << endl;
	root->left = build_tree(root->left);
	cout << "Enter the data for inserting in right of " << data << endl;
	root->right = build_tree(root->right);
	return root;
}
void inorder(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
void postorder(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}
void preorder(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
int main()
{
	int data;
	Node *root = NULL;
	root = build_tree(root);
	cout << "Level Order Traversal is :" << endl;
	inorder(root);
	cout << endl;
	cout << "PreOrder Traversal is :" << endl;
	preorder(root);
	cout << endl;
	cout << "PostOrder Traversal is :" << endl;
	postorder(root);
	return 0;
}
