//                                              PUSH AND POP IN STACK
//ROLL-NO->IIIT18153
#include<bits/stdc++.h>
using namespace std;

struct stackarray{
    int capacity;
    int top;
    int *arr;
};

struct stackarray* createstack(int size)
{
    struct stackarray* s=new struct stackarray;
    s->capacity=size;
    s->top=-1;
    s->arr=new int[size];
    return s;
}

void push(struct stackarray* s,int data)
{
    if(s->top==s->capacity-1)
    cout<<"Stack is full.This element cannot be inserted.\n";
    else
    {
        s->top++;
        s->arr[s->top]=data;
    }
}

int pop(struct stackarray* s)
{
    if(s->top==-1)
    {
        cout<<"Stack is empty\n";
        return -1;
    }
    else
    {
        int data=s->arr[s->top--];
        return data;
    }
}

int main()
{
    int n;
    cin>>n;
    struct stackarray* S=createstack(n);
    while(1)
    {
        cout<<"1. For Push:\n";
        cout<<"2. For pop\n";
        cout<<"3. Exit\n";
        int t,data;
        cin>>t;
        switch (t)
        {
        case 1:
            data;
            cin>>data;
            push(S,data);
            break;
        
        case 2:
            data=pop(S);
            if(data!=-1)
            cout<<data<<endl;
            break;
        default:
            return 0;

        }

    }
    return 0;
}
