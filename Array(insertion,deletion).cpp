//                                      Array(insertion,deletion).cpp
//ROLL-NO->IIITU18153
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++)
    cin>>a[i];

    cout<<"Insertion:\n";
    int loc,data;
    cin>>loc>>data;
    for(int i=n+1;i>loc-1;i--)
    a[i]=a[i-1];
    n++;
    a[loc-1]=data;

    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    cout<<"Deletion:\n";
    cin>>loc;
    for(int i=loc-1;i<n-1;i++)
    a[i]=a[i+1];
    n--;
    
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
