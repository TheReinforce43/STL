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
        int L, R;
        Node *left_node, *right_node;
        cin >> L >> R;
        if (L == -1)
            left_node = NULL;
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

    Node *root;
    Insertion(root);
    // Print_level_order(root);

    int key;
    cin >> key;

    if (bst_search(root, key))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;
}