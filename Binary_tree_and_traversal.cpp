//                                              Binary_tree_and_traversal.cpp
//ROLL-NO->IIIT18153
#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node* left=NULL;
	node* right=NULL;
};

void inot(node* root){
     if(!root)
       return;
     inot(root->left);
     cout<<root->data<<"  ";
     inot(root->right);	
}

void postot(node* root){
     if(!root)
       return;
     postot(root->left);
     postot(root->right);
     cout<<root->data<<"  ";
}

void preot(node* root){
	if(!root)
	   return;
   	cout<<root->data<<"  ";	
 	preot(root->left);
	preot(root->right);	
}


void insert(node* root1,int data){
	 node* temp=new node;
	 temp->data=data;
	 
	 queue<node *>q;
	 q.push(root1);
	 
	 while(!q.empty()){
	 	root1=q.front();
	 	q.pop();
	 	
	 	if(root1->left==NULL)
	 	   {root1->left=temp;
	 	    break;
	 	    }
	 	else
	 	    q.push(root1->left);
	 	
	 	if(root1->right==NULL){
	 		 root1->right=temp;
	 		 break;
		   }
		else
		    q.push(root1->right);	
	 }
}



int main()
{
 	node* root=new node;
 	int d,n;
 	cout<<"enter no. of elements:";
 	cin>>n;
 	cout<<"enter data \n";
 	cin>>d;
 	root->data=d;
 	for(int i=0;i<n-1;i++){
	     cin>>d;
	     insert(root,d);
       }
     cout<<"preorder traversal of Binary tree is\n";
     preot(root);
     cout<<"\ninorder traversal of Binary tree is\n";
     inot(root);
     cout<<"\npostorder traversal of Binary tree is\n";
     postot(root);
     cout<<endl;
	return 0;
}
