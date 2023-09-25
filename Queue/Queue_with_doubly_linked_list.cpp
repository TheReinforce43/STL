#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class Queue
{
private:
    Node *front, *rear;
    int sz;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
        sz = 0;
    }
    void push(int value)
    {
        sz++;
        Node *newNode = new Node(value);
        if (front == NULL)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    void pop()
    {
        if (front == NULL)
            return;
        Node *deleteNode = front;
        front = front->next;
        if (front == NULL)
        {
            rear == NULL;
            delete deleteNode;
            return;
        }
        front->prev = NULL;

        sz--;
    }
    int front_value()
    {
        if (front == NULL)
            return -1;
        return front->data;
    }

    bool empty()
    {
        return (front==NULL) ? true : false;
    }
};

int main()
{

    Queue q;
    int value;

    while (cin >> value && value != -1)
    {
        q.push(value);
    }
    while (!q.empty())
    {
        cout << q.front_value() << " ";
        q.pop();
    }

    return 0;
}