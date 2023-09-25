#include <bits/stdc++.h>
using namespace std;

int main()
{

    priority_queue<int> pq;
    while (true)
    {
        int com;
        cin >> com;
        if (com == 0)
        {
            int x;
            cin >> x;
            pq.push(x);
        }
        else if (com == 1)
        {

            cout << pq.top() << " ";
        }
        else if (com == 2)
        {
            pq.pop();
        }
        else
            break;
    }
    return 0;
}