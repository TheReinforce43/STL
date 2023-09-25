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

vector<int> print_level_order(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        cout << "Tree is Empty\n";
        return ans;
    }
    queue<pair<Node *, int>> que;
    que.push({root, 1});
    // ans.push_back(root->data);
    bool frq[3010] = {false};

    while (!que.empty())
    {
        // first work
        pair<Node *, int> parent = que.front();
        que.pop();
        // second work
        Node *node = parent.first;
        int level = parent.second;
        if (frq[level] == false)
        {
            ans.push_back(parent.first->data);
            frq[level] = true;
        }
        // third work
        if (parent.first->left)
        {
            que.push({parent.first->left, parent.second + 1});
        }
        if (parent.first->right)
        {
            que.push({parent.first->right, parent.second + 1});
        }
    }

    return ans;
}

int main()
{

    Node *root = NULL;
    Insertion(root);
    vector<int> ans = print_level_order(root);
    for (auto u : ans)
        cout << u << " ";

    return 0;
}