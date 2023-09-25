#include<bits/stdc++.h>
using namespace std;


int main()
{
    
    vector<int> v;
    int N;
    cin>>N;
    while(N--)
    {
        int value;
        cin>>value;
        v.push_back(value);
        int cur_indx=v.size()-1;
        while(cur_indx!=0)
        {
            int parent_indx=(cur_indx-1)/2;
            if(v[cur_indx]>v[parent_indx]) swap(v[cur_indx],v[parent_indx]);
            else break;
            cur_indx=parent_indx;
        }
    }

    for(auto u:v) cout<<u<<" ";
    
    return 0;

}