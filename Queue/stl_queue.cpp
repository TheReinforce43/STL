#include<bits/stdc++.h>
using namespace std;


int main()
{
    
    queue<int> que;
    int value;
    while(cin>>value && value !=-1)
    {
        que.push(value);
    }
    while(!que.empty())
    {
        cout<<que.front()<<" ";
        que.pop();
    }
    return 0;

}