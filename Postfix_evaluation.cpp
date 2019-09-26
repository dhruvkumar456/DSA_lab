//						Postfix_evaluation.cpp
//ROLL-NO->IIIT18153
// FOR ONE DIGITS NUMBERS
#include<bits/stdc++.h>
using namespace std;

int c[50];
int top=-1;

void push(int n)
{
	top++;
	c[top]=n;
}

char pop()
{
	top--;
	return c[top+1];
}


int main()
{
	int n;
	cin>>n;
	vector<char> s;
	for(int i=0;i<n;i++)
	{
		char c;
		cin>>c;
		s.push_back(c);
	}

	for(vector<char>::iterator i=s.begin();i<s.end();i++)
	{
		if(*i>='0'&& *i<='9')
		{
			push(*i-'0');
		}
		else 
		{
			int a=pop();
			int b=pop();
			if(i=='')
			push(a*b);
			else if(*i=='/')
			push(b/a);
			else if(*i=='+')
			push(a+b);
			else if(*i=='-')
			push(b-a);
		}
	}
	cout<<c[0];
}
