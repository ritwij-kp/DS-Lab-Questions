#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
void traverse(node *root, vector<int> &vec)
{
    if (root)
    {
        traverse(root->left, vec);
        vec.push_back(root->data);
        traverse(root->right, vec);
    }
}
int main()
{
    node *p = new node(20);
    node *p1 = new node(15);
    node *p2 = new node(23);
    node *p3 = new node(10);
    node *p4 = new node(18);
    node *p5 = new node(30);
    node *p6 = new node(16);
    node *p7 = new node(19);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;
    p4->left = p6;
    p4->right = p7;
    vector<int> vec;
    traverse(p, vec);
    int k = 3;
    cout << vec[vec.size() - k];
    return 0;
}