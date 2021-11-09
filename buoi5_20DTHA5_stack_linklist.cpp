#include <stdio.h>
#define MAX 100

typedef struct _Node
{
	int info;
	struct _Node *next;
}Node;
typedef Node* Stack;

Node* createNode(int x);
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
	int n=43;
	
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
Node* createNode(int x)
{
	Node* p;
	p=new Node();
	p->info=x;
	p->next=NULL;
	return p;
}
void init(Stack &s)
{
	s=NULL;
}
int empty(Stack s)
{
	return s==NULL;
}
void push(Stack &s,int x)
{
	Node* p=createNode(x);
	p->next=s;
	s=p;
}
void pop(Stack &s,int &x)
{
	if(empty(s)) return;
	x=s->info;
	Node* p;
	p=s;
	s=s->next;
	delete p;
}


