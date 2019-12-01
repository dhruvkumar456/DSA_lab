//					Binary_search_tree_insertion_and_traversal.cpp
//ROLL-NO->IIITU18153
#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
	node(){
		left=NULL;right=NULL;
	}
};

struct node* newnode(int data)
{
	struct node* s=new node;
	s->data=data;
}

struct node* insert(struct node* rootnode,int data)
{
	if(rootnode==NULL)
	return newnode(data);
	else if(rootnode->data<=data)
	rootnode->right=insert(rootnode->right,data);
	else
	rootnode->left=insert(rootnode->left,data);
}

void preorder_traversal(struct node* rootnode)
{
	if(rootnode!=NULL)
	{
		cout<<rootnode->data<<" ";
		preorder_traversal(rootnode->left);
		preorder_traversal(rootnode->right);
	}
}

void inorder_traversal(struct node* rootnode)
{
	if(rootnode!=NULL)
	{
		inorder_traversal(rootnode->left);
		cout<<rootnode->data<<" ";
		inorder_traversal(rootnode->right);
	}
}

void postorder_traversal(struct node* rootnode)
{
	if(rootnode!=NULL)
	{
		postorder_traversal(rootnode->left);
		postorder_traversal(rootnode->right);
		cout<<rootnode->data<<" ";
	}
}


int main()
{
	int n;
	cin>>n;
	struct node* rootnode=NULL;
    cout<<"Enter the numbers:\n";
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		rootnode=insert(rootnode,x);
	}
	cout<<"preorder_traversal:";
	preorder_traversal(rootnode);
	cout<<"\ninorder_traversal:";
	inorder_traversal(rootnode);
	cout<<"\npostorder_traversal:";
	postorder_traversal(rootnode);
	cout<<"\n";
	return 0;
}

