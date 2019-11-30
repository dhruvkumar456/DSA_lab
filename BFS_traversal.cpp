//                                             BFS_traversal.cpp
//ROLL-NO->IIIT18153
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector <int> v[n+1];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    
    queue <int> q;
    bool vis[n+1];
    int node;
    cout<<"Enter the node about which you want to traverse:";
    cin>>node;
    vis[node]=true;
    q.push(node);
    while(q.size()!=0)
    {
        node=q.front();
        q.pop();
        for(int i=0;i<v[node].size();i++)
        {
            if(vis[v[node][i]]==false)
            {
                cout<<v[node][i]<<" ";
                vis[v[node][i]]=true;
                q.push(v[node][i]);
            }
        }
    }
    cout<<endl;
    return 0;
}
