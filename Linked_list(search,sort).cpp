//						Linked_list(search,sort).cpp		
//ROLL-NO->IIIT18153
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

struct node* insert(struct node* root,int data)
{
	
	if(root==NULL)
	return newnode(data);
	else
	root->next=insert(root->next,data);

}


void traverse(struct node* s)
{
	if(s!=NULL)
	{
		if(s->data%2==0)
		cout<<"Even->"<<s->data<<"\n";
		else
		cout<<"Odd->"<<s->data<<"\n";
		traverse(s->next);
	}
}
int y=0;
int search(struct node* root,int find)
{

	if(root!=NULL)
	{	y++;
		if(root->data==find)
		cout<<"Index is"<<y<<"\n";
		search(root->next,find);
	}
	else
	return -1;
}

int z=0;
int size(struct node* root)
{
	if(root!=NULL)
	{
		z++;
		size(root->next);
	}
	else
	return z;
}

void swap(int *p,int *q)
{
	int t=*p;
	*p=*q;
	*q=t;
}

void sorting(struct node* root)
{
	if(root!=NULL && root->next!=NULL)
	{
		if(root->next->data < root->data)
		swap(&root->data,&root->next->data);	
		
		sorting(root->next);
	}
}

void print(struct node* root)
{
	if(root!=NULL)
	{
		cout<<root->data<<"\n";
	print(root->next);
	}
	
}

int main()
{
   struct node* root=NULL;
   int n;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
   	 	int no;
   		cin>>no;
   		root=insert(root,no);
   }
   traverse(root);
   int find;
   cin>>find;
   int index=search(root,find);

   int g=size(root);
 
   for(int i=0;i<g;i++)
   {
   		sorting(root);
   }
    print(root);
    cin>>find;
    y=0;
	index=search(root,find);
	
	int ins;
	cin>>ins;
	print(root);
   return 0;
   
}
