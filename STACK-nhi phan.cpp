#include <stdio.h>
#define MAX 100

typedef struct _Stack
{
	int a[MAX];
	int n;
}Stack;
void init(Stack &s);
int empty(Stack s);
void push(Stack &s,int x);
void pop(Stack &s,int &x);
void np(int n);
void npKDQ(int n);
int main()
{
	Stack s;
	init(s);
	int n=13;
	for(int i=1;i<=5;i++)
		push(s,i);
	while(!empty(s))
	{
		int x;
		pop(s,x);
		printf("%d ",x);
	}
	//ham hien thi n o he nhi phan su dung stack
	printf("\n Hien thi he nhi phan de quy:");
	np(n);
	printf("\n Hien thi he nhi phan khu de quy:");
	npKDQ(n);
	return 0;
}
void np(int n)
{
	if(n<2)
	{
		printf("%d",n);
		return;
	}
	np(n/2);
	printf("%d",n%2);
}
void npKDQ(int n)
{
	Stack s;
	init(s);
	while(n>0)
	{
		push(s,n%2);
		n=n/2;
	}
	while(!empty(s))
	{
		int x;
		pop(s,x);
		printf("%d",x);
	}
}

void init(Stack &s)
{
	s.n=0;
}
int empty(Stack s)
{
	return s.n==0;
}
void push(Stack &s,int x)
{
	s.a[s.n]=x;
	s.n++;
}
void pop(Stack &s,int &x)
{
	x=s.a[s.n-1];
	s.n--;
}


