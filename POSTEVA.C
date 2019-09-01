#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<process.h>
#define size 50
void push(int item, char stack[], int *top)
{

	(*top)++;
	stack[*top]=item;

}
int pop(char stack[],int *top)
{
	char a;
	if(*top==-1)
	printf("expression invalid");
	else
	{	a=stack[*top];
		(*top)--;
	}
	return a;
}
void main()
{
	int top;
	char stack[20];
	char postfix[20];
	char x;
	int i;
	int n1,n2,n3,num;
	clrscr();
	top=-1;
	i=0;
	printf("Enter the postfix expression\n");
	gets(postfix);
	x=postfix[i];
	while(x!='\0')
	{
		if(isdigit(x))
		{
			num=x-'0';
			push(num,stack,&top);
		}
		else
		{
			n1=pop(stack,&top);
			n2=pop(stack,&top);
			switch(x)
			{
				case '*':
				{
					n3=n2*n1;
					break;
				}
				case '/':
				{
					n3=n2/n1;
					break;
				}
				case '+':
				{
					n3=n2+n1;
					break;
				}
				case '-':
				{
					n3=n2-n1;
					break;
				}
				default:
				printf("wrong\n");
			}

			push(n3,stack,&top);
		}
		i++;
		x=postfix[i];
	}
	printf("the result is: %d",pop(stack,&top));
	getch();
}


