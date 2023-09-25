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

Node *Insertion(int arr[], int l, int r)
{
    if(l>r) return NULL;
    int mid = (l + r) / 2;

    Node *root = new Node(arr[mid]);
    Node *left_node = Insertion(arr, l, mid - 1);
    Node *right_node = Insertion(arr, mid + 1, r);
    root->left = left_node;
    root->right = right_node;

    return root;
}

void Print_level_order(Node *root)
{
    if (root == NULL)
    {
        cout << "BST is Empty\n";
        return;
    }
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node *fro = Q.front();
        Q.pop();
        cout << fro->data << " ";
        if (fro->left)
            Q.push(fro->left);
        if (fro->right)
            Q.push(fro->right);
    }
}

int main()
{

    int N;
    cin >> N;
    int arr[N + 5];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr+N);


    Node *root=Insertion(arr, 0, N - 1);
    Print_level_order(root);

    return 0;
}