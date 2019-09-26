//                                        Insertion_in_linked_list.cpp
//IIITU18153
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

struct node* createLL(struct node* head,int data)
{
    if(head==NULL)
    return newnode(data);
    else
    head->next=createLL(head->next,data);
}

struct node* insert_at_beg(struct node* s,int data,int loc)
{
    struct node* temp=newnode(data);
    temp->next=s;
    return temp;
}

int y;
void insert(struct node* head,int data,int loc)
{
  if(head!=NULL)
  {
    y++;
    if(y==loc-1)
    {
      struct node* temp=newnode(data);
      temp->next=head->next;
      head->next=temp;
    }
    else
    insert(head->next,data,loc);
  }
}

void traverse(struct node* head)
{
  if(head!=NULL)
  {
    cout<<head->data<<" ";
    traverse(head->next);
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
    head=createLL(head,x);
    
  }
  int loc,data;
  for(int i=0;i<=2;i++)
  {y=0;
    cin>>loc>>data;
    if(loc==1)
    head=insert_at_beg(head,data,1); //INSERTION AT BEGNNING
    else
    insert(head,data,loc);
    traverse(head);
  }
  return 0;
}
