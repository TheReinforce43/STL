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

void Traverse(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    Traverse(root->left);
    Traverse(root->right);
}

int main()
{
    Node *root = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);
    Node *e = new Node(60);
    Node *f = new Node(70);
    Node *g = new Node(80);
    Node *h = new Node(90);
    Node *i = new Node(100);
    Node *j = new Node(110);
    Node *k = new Node(120);

    root->left = a;
    root->right = b;
    a->left = c;
    b->right = d;
    c->left = e;
    c->right = f;
    d->left = g;
    d->right = h;
    e->left = i;
    e->right = j;
    f->left = k;

    Traverse(root);

    return 0;
}