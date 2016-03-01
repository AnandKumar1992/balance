//program to check balanced paranthesis
#include <stdio.h>
#define MAX 10
int top=-1;
int stack[MAX];
//function to push symbol
void push(char symbol)
{
	top=top+1;
	stack[top]=symbol;
}
//function to pop symbol
char pop()
{
	char k;
	k=stack[top];
	top=top-1;
	return(k);
}
//main function
int main(void)
{
	char exp[MAX],symbol,temp;
	int i,flag=1;
	clrscr();
	printf("Enter any algebric expression:");
	gets(exp);
	for(i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
			push(exp[i]);
		if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
		{
			if(top==-1)
				flag=0;
			else
			{
				temp=pop();
				if(temp=='('&&(exp[i]=='}'||exp[i]==']'))
					flag=0;
				if(temp=='{'&&(exp[i]==')'||exp[i]==']'))
					flag=0;
				if(temp=='['&&(exp[i]==')'||exp[i]=='}'))
					flag=0;
			}
		}
	}
	if(top>=0)
		flag=0;
	if(flag==1)
		printf("valid expression");
	else
		printf("invalid expression");
	getch();
	return 0;
}


