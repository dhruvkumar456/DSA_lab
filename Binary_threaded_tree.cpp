//                                          Binary_threaded_tree.cpp
//ROLL-NO->IIIT18153
#include<bits/stdc++.h>
using namespace std; 
  
struct Node 
{ 
    struct Node *left, *right; 
    int info;  
    bool ltag;
    bool rtag; 
}; 

struct Node *insert(struct Node *root, int ikey) 
{ 
    Node *ptr = root; 
    Node *par = NULL;
    while (ptr != NULL) 
    {
        if (ikey == (ptr->info)) 
        { 
            printf("Duplicate Key !\n"); 
            return root; 
        } 
        par = ptr;
        if (ikey < ptr->info) 
        { 
            if (ptr -> ltag == false) 
                ptr = ptr -> left; 
            else
                break; 
        } 
        else
        { 
            if (ptr->rtag == false) 
                ptr = ptr -> right; 
            else
                break; 
        } 
    }  
    Node *tmp = new Node; 
    tmp -> info = ikey; 
    tmp -> ltag = true; 
    tmp -> rtag = true; 
  
    if (par == NULL) 
    { 
        root = tmp; 
        tmp -> left = NULL; 
        tmp -> right = NULL; 
    } 
    else if (ikey < (par -> info)) 
    { 
        tmp -> left = par -> left; 
        tmp -> right = par; 
        par -> ltag = false; 
        par -> left = tmp; 
    } 
    else
    { 
        tmp -> left = par; 
        tmp -> right = par -> right; 
        par -> rtag = false; 
        par -> right = tmp; 
    } 
  
    return root; 
} 

struct Node *inorderSuccessor(struct Node *ptr) 
{ 
    if (ptr -> rtag == true)
        return ptr->right; 
    ptr = ptr -> right; 
    while (ptr -> ltag == false) 
        ptr = ptr -> left; 
    return ptr; 
} 
 
void inorder(struct Node *root) 
{ 
    if (root == NULL) 
        printf("Tree is empty"); 
		 
    struct Node *ptr = root; 
    while (ptr -> ltag == false) 
        ptr = ptr -> left; 
		 
    while (ptr != NULL) 
    { 
        printf("%d ",ptr -> info); 
        ptr = inorderSuccessor(ptr); 
    } 
} 

int main() 
{ 
    struct Node *root = NULL; 
    cout<<"Enter the number of elements:";
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int r;
        cin>>r;
        root=insert(root,r);
    }
    inorder(root); 
    cout<<endl;
    return 0; 
}
