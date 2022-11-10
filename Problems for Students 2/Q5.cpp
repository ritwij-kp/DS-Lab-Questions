#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
Node*buildTree(string str)
{
    if (str.length() == 0 ||str[0] == 'N')
        return NULL;
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);
    Node *root = new Node(stoi(ip[0]));
    queue<Node *> queue;
    queue.push(root);
    int i = 1;
    while (!queue.empty() &&i < ip.size())
    {
        Node *currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if (currVal != "N")
        {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];
        if (currVal != "N")
        {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}
class Solution
{
public:
    Node
        *
        findLca(Node*root,int first, int second)
    {
        if (!root)
            return NULL;
        if (root->data == first || root->data == second)
        {
            return root;
        }
        Node *l = findLca(root->left, first, second);
        Node *r = findLca(root->right, first, second);
        if (l && r)
        {
            return root;
        }
        if (l)
        {
            return l;
        }
        else if (r)
        {
            return r;
        }
        else
        {
            return NULL;
        }
    }
    Node *calcTurnsL(Node *lca, char dirn1, int &countTurns, int first, int second)
    {
        if (!lca)
            return NULL;
        if (lca->data == first || lca->data == second)
            return lca;
        Node *l = calcTurnsR(lca->left, 'L', countTurns, first, second);
        Node *r = calcTurnsR(lca->right, 'R', countTurns, first, second);
        if (l)
        {
            if (dirn1 == 'R')
                countTurns++;
            return l;
        }
        else if (r)
        {
            if (dirn1 == 'L')
                countTurns++;
            return r;
        }
        else
            return NULL;
    }
    Node *calcTurnsR(Node *lca, char dirn2, int &countTurns, int first, int second)
    {
        if (!lca)
            return NULL;
        if (lca->data == first || lca->data == second)
            return lca;
        Node *l = calcTurnsR(lca->left, 'L', countTurns, first, second);
        Node *r = calcTurnsR(lca->right, 'R', countTurns, first, second);
        if (l)
        {
            if (dirn2 == 'R')
                countTurns++;
            return l;
        }
        else if (r)
        {
            if (dirn2 == 'L')
                countTurns++;
            return r;
        }
        else
            return NULL;
    }
    int NumberOFTurns(Node *root, int first, int second)
    {
        Node *lca = findLca(root, first, second);
        char dirn1 = 'L';
        char dirn2 = 'R';
        int countTurns = 0;
        calcTurnsL(lca->left, dirn1, countTurns, first, second);
        calcTurnsR(lca->right, dirn2, countTurns, first, second);
        if (lca->data == first || lca->data == second)
        {
            if (countTurns == 0)
            {
                return -1;
            }
            else
                return countTurns;
        }
        else
            return countTurns + 1;
    }
};
int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        int turn, first, second;
        cin >> first >> second;
        Solution ob;
        if ((turn = ob.NumberOFTurns(root, first, second)))
            cout << turn << endl;
        else
            cout << "-1\n";
        cin.ignore();
    }
    return 0;
}
