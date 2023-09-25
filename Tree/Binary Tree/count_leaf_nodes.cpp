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

        int L, R;
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

void print_level_order(Node *root)
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

int count_leaf(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    int l = count_leaf(root->left);
    int r = count_leaf(root->right);
    return l + r;
}

int max_height(Node *root)
{
    if (root == NULL)
        return 0;

    int l = max_height(root->left);
    int r = max_height(root->right);
    return max(l, r) + 1;
}

int main()
{

    Node *root = NULL;

    Insertion(root);
    print_level_order(root);
    // cout << count_leaf(root);
    cout << max_height(root);

    return 0;
}