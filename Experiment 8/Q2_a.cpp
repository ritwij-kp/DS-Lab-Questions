#include <iostream>
using namespace std;
class BST
{
	int data;
	BST *left;
	BST *right;

public:
	BST()
	{
		data = 0;
		left = NULL;
		right = NULL;
	}
	BST(int value)
	{
		data = value;
		left = NULL;
		right = NULL;
	}
	BST *Insert(BST *root, int value)
	{
		if (root == NULL)
		{
			return new BST(value);
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
	void Inorder(BST *root)
	{
		if (root == NULL)
		{
			return;
		}
		Inorder(root->left);
		cout << root->data << " ";
		Inorder(root->right);
	}
	bool search(BST *root, int key)
	{
		if (root == NULL)
			return false;
		if (root->data == key)
			return true;

		if (root->data < key)
			return search(root->right, key);

		return search(root->left, key);
	}
	BST *minValueNode(BST *node)
	{
		BST *current = node;

		while (current && current->left != NULL)
			current = current->left;
		return current;
	}
	BST *deleteNode(BST *root, int key)
	{
		if (root == NULL)
			return root;

		if (key < root->data)
			root->left = deleteNode(root->left, key);

		else if (key > root->data)
			root->right = deleteNode(root->right, key);

		else
		{
			if (root->left == NULL and root->right == NULL)
				return NULL;

			else if (root->left == NULL)
			{
				BST *temp = root->right;
				free(root);
				return temp;
			}
			 else if (root->right == NULL)
			{
				BST *temp = root->left;
				free(root);
				return temp;
			}
			BST *temp = minValueNode(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
		return root;
	}
};
int main()
{
	BST b, *root = NULL;
	root = b.Insert(root, 50);
	b.Insert(root, 30);
	b.Insert(root, 20);
	b.Insert(root, 40);
	b.Insert(root, 70);
	b.Insert(root, 60);
	b.Insert(root, 80);
	cout << "Inorder travesal of the binary tree is: ";
	b.Inorder(root);
	cout << endl;
	int a;
	cout << "Enter the value to search in BST" << endl;
	cin >> a;
	bool ans = b.search(root, a);
	if (ans == false)
	{
		cout << "Key is not present" << endl;
	}
	else
	{
		cout << "Key is present" << endl;
	}
	int p;
	cout << "Enter the value you want to delete from the BST" << endl;
	cin >> p;
	root = b.deleteNode(root, p);
	cout << "Inorder traversal of the modified tree \n";
	b.Inorder(root);
	return 0;
}
