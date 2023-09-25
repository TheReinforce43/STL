#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Queue
{
private:
    Node *head, *tail;
    int len = 0;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
    }
    void push(int value)
    {
        len++;
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    void pop()
    {
        if (head == NULL)
            return;
        Node *deleteNode = head;
        head = head->next;
        delete deleteNode;
        if (head == NULL)
        {
            tail = NULL;
        }
        len--;
    }

    int front()
    {
        if (head == NULL)
            return -1;
        return head->data;
    }

    int queue_size()
    {
        return len;
    }

    bool empty_check()
    {
        return len == 0 ? true : false;
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

    while (!q.empty_check())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}