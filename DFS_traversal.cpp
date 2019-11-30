//                                              DFS_traversal.cpp
//ROLL-NO->IIIT18153
#include<bits/stdc++.h>
using namespace std;

vector<int> v[1000];
bool vis[1000];

void DFS(int r)
{
        cout<<r<<" ";
        vis[r]=true;
        for(int i=0;i<v[r].size();i++)
        {
            if(vis[v[r][i]]==false) 
            DFS(v[r][i]);
        }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int r;
    cin>>r;
    cout<<"DFS traversal of given graph is:\n";
    DFS(r);
    cout<<"\n";
    return 0;
}
