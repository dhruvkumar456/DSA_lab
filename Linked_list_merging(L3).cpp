//  					Linked_list_merging(L3).cpp
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

void traverse(struct node* root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		traverse(root->next);
	}
}

int main()
{
	int n;
	cin>>n;
	struct node* root1=NULL;
	struct node* root2=NULL;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		root1=insert(root1,x);
	}
	
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		root2=insert(root2,x);
	}
	
	struct node* root3=NULL;
	while(root1!=NULL)
	{
//		cout<<root1->data<<" "<<root2->data<<" ";
		root3=newnode(root1->data);
		root3=root3->next;
		root3=newnode(root2->data);
		root3=root3->next;
		root1=root1->next;
		root2=root2->next;
	}
	traverse(root3);
	return 0;
}
