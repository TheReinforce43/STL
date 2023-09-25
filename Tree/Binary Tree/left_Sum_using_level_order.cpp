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
        return;
    }
    else
        root = new Node(value);
    queue<Node *> que;
    que.push(root);
    while (!que.empty())
    {
        Node *fro = que.front();
        que.pop();
        Node *left_node, *right_node;
        int l, r;
        cin >> l >> r;
        if (l == -1)
            left_node = NULL;
        else
            left_node = new Node(l);
        if (r == -1)
            right_node = NULL;
        else
            right_node = new Node(r);
        fro->left = left_node;
        fro->right = right_node;
        if (fro->left)
            que.push(fro->left);
        if (fro->right)
            que.push(fro->right);
    }
}

void print_level_order(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree is Empty\n";
        return;
    }
    queue<Node *> que;
    que.push(root);

    while (!que.empty())
    {
        Node *fro = que.front();
        que.pop();

        if (fro->left)
        {
            cout << fro->left->data << " ";
            que.push(fro->left);
        }
        if (fro->right)
            que.push(fro->right);
    }
}

int main()
{

    Node *root = NULL;
    Insertion(root);
    print_level_order(root);

    return 0;
}