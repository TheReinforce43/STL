#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void Insertion(Node *&root)
{
    int value;
    cin >> value;
    if (value == -1)
    {
        root = NULL;
        // return;
    }
    else
        root = new Node(value);
    queue<Node *> que;
    if (root)
        que.push(root);

    while (!que.empty())
    {
        Node *fro = que.front();
        que.pop();
        Node *left_node, *right_node;
        int L, R;
        cin >> L >> R;
        if (L == -1)
        {
            left_node = NULL;
        }
        else
            left_node = new Node(L);
        if (R == -1)
            right_node = NULL;
        else
            right_node = new Node(R);

        fro->left = left_node;
        fro->right = right_node;

        if (fro->left)
            que.push(fro->left);
        if (fro->right)
            que.push(fro->right);
    }
}

void Print_level_order(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> que;
    que.push(root);

    while (!que.empty())
    {
        Node *fro = que.front();
        que.pop();
        cout << fro->data << " ";
        if (fro->left)
            que.push(fro->left);
        if (fro->right)
            que.push(fro->right);
    }

    cout << "\n";
}

int cnt_node(Node *root)
{
    if (root == NULL)
        return 0;
    int l = cnt_node(root->left);
    int r = cnt_node(root->right);

    return 1 + l + r;
}

int main()
{
    Node *Root = NULL;
    Insertion(Root);
    Print_level_order(Root);
    cout << cnt_node(Root);
    return 0;
}