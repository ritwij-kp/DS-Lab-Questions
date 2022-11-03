#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void preOrder(struct node *root, list<int> &pre)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        pre.push_back(root->data);
        preOrder(root->left, pre);
        preOrder(root->right, pre);
    }
}
void postOrder(struct node *root, list<int> &post)
{
    if (root != NULL)
    {
        postOrder(root->left, post);
        postOrder(root->right, post);
        printf("%d ", root->data);
        post.push_back(root->data);
    }
}
void inOrder(struct node *root, list<int> &in)
{
    if (root != NULL)
    {
        inOrder(root->left, in);
        printf("%d ", root->data);
        in.push_back(root->data);
        inOrder(root->right, in);
    }
}
int main()
{
    struct node *p = createnode(15);
    struct node *p1 = createnode(10);
    struct node *p2 = createnode(20);
    struct node *p3 = createnode(9);
    struct node *p4 = createnode(11);
    struct node *p5 = createnode(23);
    struct node *temp1 = createnode(14);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;
    p4->right = temp1;
    list<int> pre;
    list<int> post;
    list<int> in;
    preOrder(p, pre);
    printf("\n");
    postOrder(p, post);
    printf("\n");
    inOrder(p, in);
    cout << endl;
    pre.reverse();
    post.reverse();
    in.reverse();
    for (auto it = pre.begin(); it != pre.end(); it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;
    for (auto it = post.begin(); it != post.end(); it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;
    for (auto it = in.begin(); it != in.end(); it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;
}