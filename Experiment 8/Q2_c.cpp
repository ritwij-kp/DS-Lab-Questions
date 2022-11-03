#include <iostream>
#include <queue>
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
Node *Insert(Node *root, int value)
{
	if (root == NULL)
	{
		return new Node(value);
	}
	if (value > root->data)
	{
		root->right = Insert(root->right, value);
	}
	else if (value < root->data)
	{
		root->left = Insert(root->left, value);
	}
	return root;
}
int Height(Node *node)
{
	if (node == NULL)
		return 0;
	else
	{
		int left_height = Height(node->left);
		int right_height = Height(node->right);
		return max(left_height, right_height) + 1;
	}
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
int levels(Node *root)
{
	int count = 0;
	if (root == NULL)
	{
		return count;
	}
	queue<Node *> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty())
	{
		Node *front = q.front();
		q.pop();
		if (front == NULL)
		{
			count++;
			if (!q.empty())
			{
				q.push(NULL);
			}
		}
		else
		{
			if (front->left != NULL)
			{
				q.push(front->left);
			}
			if (front->right != NULL)
			{
				q.push(front->right);
			}
		}
	}
	return count;
}
int cnt = 0;
int Total_Nodes(Node *root)
{
	if (root == NULL)
		return 0;
	cnt++;
	int lN = Total_Nodes(root->left);
	int rN = Total_Nodes(root->right);
	return 1 + lN + rN;
}
int getLeafCount(Node *root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	else
		return getLeafCount(root->left) + getLeafCount(root->right);
}
int main()
{
	int data;
	Node *root = NULL;
	root = Insert(root, 50);
	Insert(root, 30);
	Insert(root, 20);
	Insert(root, 40);
	Insert(root, 70);
	Insert(root, 60);
	Insert(root, 80);
	cout << "InOrder Traversal is :" << endl;
	inorder(root);
	cout << endl;
	cout << "Height of the BST is: " << Height(root) << endl;
	cout << "Number of levels in BST is: " << levels(root) << endl;
	cout << "Number of leaf Nodes in the BST is: " << getLeafCount(root) << endl;
	cout << "Total Number of nodes in BST is: " << Total_Nodes(root)
		 << endl;
	cout << "Number of Internal nodes in BST is: " << Total_Nodes(root) - getLeafCount(root) << endl;
	return 0;
}
