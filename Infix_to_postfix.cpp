// 						INFIX TO POSTFIX
//ROLL-NO->IIIT18153
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>

char stack[50];
int top=-1;

int isEmpty()
{
	return(top==-1);
}
void push(char item)
{
	    stack[++top]=item;
}

char pop()
{
    char item;
    if(!isEmpty())
        {
	    item=stack[top--];
	    return(item);
        }
    return '$';
}

char peek()
{
    return(stack[top]);
}

int prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}
int isOperand(char ch)
{
    return (ch>='a' && ch<='z' ) || (ch>='A' && ch<='Z');
}

void infix_to_postfix(char exp[])
{
    int i,k;
    for(i=0,k=-1;exp[i];i++)
    {
        if(isOperand(exp[i]))
            exp[++k]=exp[i];

        else if(exp[i]=='(')
            push(exp[i]);

        else if(exp[i]==')')
        {
            while( !isEmpty() && peek()!= '(' )
                    exp[++k]=pop();
            if(!isEmpty() && peek()!= '(' )
                return -1;
            else
                pop();

        }
        else
        {
           while( !isEmpty() && prec(exp[i]) <= prec(peek()) )
                exp[++k]=pop();
            push(exp[i]);
        }
    }

 while(!isEmpty())
        exp[++k]=pop();

    exp[++k]='\0';
    printf("%s",exp);
}
			/*********MAIN BODY****************/
int main()
{   system("cls");
    char exp[30];
    gets(exp);
    infix_to_postfix(exp);
    getch();
    return 0;
}
