#include <bits/stdc++.h>
using namespace std;

int main()
{

    priority_queue<int, vector<int>, greater<int>> min_heap;

    while (true)
    {
        int com;
        cin >> com;
        if (com == 0)
        {
            int x;
            cin >> x;
            min_heap.push(x);
        }
        else if (com == 1)
        {
            cout << min_heap.top() << " ";
        }
        else if (com == 2)
            min_heap.pop();
        else
            break;
    }

    return 0;
}