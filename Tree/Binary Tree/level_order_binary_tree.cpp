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

void Level_order(Node *root)
{
    queue<Node *> que;
    que.push(root);

    while (!que.empty())
    {
        Node *fro = que.front();
        que.pop();
        cout << fro->data << " ";

        if (fro->right)
            que.push(fro->right);

        if (fro->left)
            que.push(fro->left);
    }
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

    Level_order(root);
    // Traverse(root);

    return 0;
}