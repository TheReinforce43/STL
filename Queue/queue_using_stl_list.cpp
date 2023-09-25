#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
private:
    list<int> que;

public:
    void push(int value)
    {

        que.push_back(value);
    }
    void pop()
    {
        if (que.empty())
            return;
        que.pop_front();
    }
    int top()
    {
        return que.front();
    }

    int size()
    {
        return que.size();
    }

    bool empty()
    {
        return que.size() == 0 ? true : false;
    }
};

int main()
{

    MyQueue que;
    int value;
    while (cin >> value && value != -1)
    {
        que.push(value);
    }
    while (!que.empty())
    {
        cout << que.top() << " ";
        que.pop();
    }

    return 0;
}