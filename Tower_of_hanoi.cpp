//ROLL-NO->IIIT18153
#include<bits/stdc++.h>
using namespace std;

void toh(int n,char beg,char aux,char end)
{
	if(n==1)
	cout<<beg<<"->"<<end<<endl;
	else
	{
		toh(n-1,beg,end,aux);
		cout<<beg<<"->"<<end<<endl;
		toh(n-1,aux,beg,end);
	}
}

int main()
{
	int n;
	cin>>n;
	toh(n,'A','B','C');
}
