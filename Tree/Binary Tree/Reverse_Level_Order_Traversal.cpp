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

vector<int> Reverse_level_order(Node *root)
{
    stack<int> stk;
    vector<int> ans;
    if(root==NULL) return ans;
    queue<Node *> que;
    que.push(root);
    
    while(!que.empty())
    {
        Node *fro=que.front();
        que.pop();
        stk.push(fro->data);
        cout<<fro->data<<" ";

        if(fro->left)
        {
            que.push(fro->left);
        }
        if(fro->right)
        {
            que.push(fro->right);
        }
    }

    while(!stk.empty())
    {
        ans.push_back(stk.top());
        stk.pop();
    }

    return ans;
}

int main()
{

    Node *root = NULL;
    Insertion(root);
    vector<int> ans = Reverse_level_order(root);
    cout<<"\n";
    for (auto u : ans)
        cout << u << " ";

    return 0;
}