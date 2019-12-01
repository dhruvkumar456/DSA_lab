//                                          Selection_sort.cpp
//ROLL-NO->IIIT18153
#include <bits/stdc++.h> 
using namespace std; 

void swap(int *xp, int *yp) 
{ 
	int temp=*xp; 
	*xp=*yp; 
	*yp=temp; 
} 

void selectionSort(int arr[], int n) 
{ 
	int i,j,mi; 
	for (i=0;i<n-1;i++) 
	{ 
		mi=i; 
		for (j=i+1;j<n;j++) 
		if (arr[j]<arr[mi]) 
		mi=j; 
		swap(&arr[mi],&arr[i]); 
	} 
} 


int main() 
{ 
	int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
	selectionSort(arr,n); 
	cout<<"Sorted array after selection sort is:\n"; 
	for (int i=0;i<n;i++) 
	cout<<arr[i]<<" "; 
	cout<<endl; 
	return 0; 
} 
