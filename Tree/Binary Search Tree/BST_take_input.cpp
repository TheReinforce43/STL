#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void Insertion(Node *&root, int key)
{
    if (root == NULL)
    {
        root = new Node(key);
        return;
    }
    else if (root->data > key)
    {
        if (root->left == NULL)
        {
            root->left = new Node(key);
        }
        else
            Insertion(root->left, key);
    }
    else if (root->data < key)
    {
        if (root->right == NULL)
        {
            root->right = new Node(key);
        }
        else
            Insertion(root->right, key);
    }
    else
    {
        cout << "Duplicate value Not inserted in BST\n";
        // return root;
        return;
    }
}

void Print_level_order(Node *root)
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
        /* code */
        Node *fro = que.front();
        que.pop();
        cout << fro->data << " ";
        if (fro->left)
            que.push(fro->left);
        if (fro->right)
            que.push(fro->right);
    }
}

bool bst_search(Node *root, int key)
{
    if (root == NULL)
        return false;
    else if (root->data == key)
        return true;
    else if (root->data > key)
        return bst_search(root->left, key);
    else
        return bst_search(root->right, key);
}

int main()
{

    Node *root=NULL;
    int value;
    while (cin >> value && value != -1)
    {
        /* code */
        Insertion(root, value);
    }

    Print_level_order(root);

    return 0;
}