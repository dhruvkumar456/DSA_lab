//                                              Min_heap.cpp
//ROLL-NO->IIIT18153
#include <bits/stdc++.h>
using namespace std;
const int N=(int)10e5+10;
int a[N];
int32_t main()
{
    auto min_heapify=[&](int i,int n)->void{
    int j, temp;
    temp = a[i];
    j = 2 * i;
    while (j <= n)
    {
        if (j < n && a[j+1] < a[j])
        j = j + 1;
        if (temp < a[j])
        break;
        else if (temp >= a[j])
        {
            a[j/2] = a[j];
            j = 2 * j;
        }
    }
        a[j/2] = temp;
    };
    auto build_minheap=[&](int n)->void{
    for(int i = n/2; i >= 1; i--)
    {
        min_heapify(i,n);
    }
    };
    int n;
    cout<<"enter no of elements of array\n";
    cin>>n;
    cout<<"Enter Elements"<<endl;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }   
    build_minheap(n);cout<<"Min Heap\n";
    for (int i = 1; i <= n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
