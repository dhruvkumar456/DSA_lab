//                                            QUEUES(INSERTION,DELETION).CPP
//ROLL-NO->IIIT18153
#include<bits/stdc++.h>
using namespace std;
int front=-1;
int rear=-1;
int n;
void insert_at_rear(int *p,int no)
{
    if(rear==n-1)
    cout<<"Overflow\n";
    else
    {
        if(rear==-1)
        front++;
        p[++rear]=no;
    }    
}

int Pop_at_front(int *p)
{
    int r=-1;
    if(front>rear||front==-1)
    {
        cout<<"Underflow\n";
        return -1;
    }
    else
    {
        r=p[front];
        front++;
    }
    return r;
}

int main()
{
    cin>>n;
    int* p=new int[n];
    while(1)
    {
        cout<<"1.For insertion\n";
        cout<<"2.For deletion\n";
        cout<<"3.For exit\n";
        int s,pop,no;
        cin>>s;
        switch (s)
        {
        case 1:
            cin>>no;
            insert_at_rear(p,no);
            break;
        case 2:
        pop=Pop_at_front(p);
        if(pop!=-1)
        cout<<pop<<endl;
        break;
        
        default:
        return 0;
            break;
        }
    }
    return 0;
}
