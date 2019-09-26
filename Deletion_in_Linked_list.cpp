//                                      Deletion_in_Linked_list.cpp
//ROLL-NO->IIITU18153
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* next;
};

struct node* newnode(int data)
{
    struct node* s=new struct node;
    s->data=data;
    s->next=NULL;
    return s;
}

struct node* insert(struct node* head,int data)
{
    if(head==NULL)
    return newnode(data);
    else
    head->next=insert(head->next,data);
}


int y=0;
void deletion(struct node* head,int loc)
{
    if(head!=NULL)
    {
        y++;
        if(y==loc-1)
        head->next=head->next->next;
        else
        deletion(head->next,loc);
    }
}

void traverse(struct node* s)
{
    if(s!=NULL)
    {
        cout<<s->data<<" ";
        traverse(s->next);
    }
}

int main()
{
    int n;
    cin>>n;
    struct node* head=NULL;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        head=insert(head,x);
    }

    for(int i=0;i<=2;i++)
    {
        int loc;
        cin>>loc;
        y=0;
        if(loc==1)
        head=head->next;  //DELETION IN BEGNNING
        else
        deletion(head,loc);
        traverse(head);
    }
    return 0;
}
