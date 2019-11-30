//                                          Floyd_warshell_algorithm.cpp
//ROLL-NO->IIIT18153
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int e[n+1][n+1];
    memset(e,0,sizeof(e));
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        e[a][b]=w;
        e[b][a]=w;
    }

    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                e[j][k]=min(e[j][k],e[j][i]+e[i][k]);
            }
        }
    }
    cout<<"Minimum distance between each pair of vertex is:\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<e[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
