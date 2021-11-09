#include <stdio.h>
#define MAX 100
typedef struct _BT{
	int n;
	int nguon;
	int dich;
	int tam;
}BT;
typedef struct _Node
{
	BT info;
	struct _Node *next;
}Node;
typedef Node* Stack;

Node* createNode(BT x);
void init(Stack &s);
int empty(Stack s);
void push(Stack &s,BT x);
void pop(Stack &s,BT &x);

void HN(int n, int nguon,int dich, int tam);
void HNKDQ(int n, int nguon,int dich, int tam);

int main()
{
	int n;
	n=3;
	printf("\n Lam theo cach de quy:");
	HN(n,1,2,3);
	printf("\n Lam theo cach khu de quy:");
	HNKDQ(n,1,2,3);
	return 0;
}

void HN(int n, int nguon,int dich, int tam)
{
	if(n==1)
	{	printf("\n %d --> %d", nguon,dich);
		return;
	}
	HN(n-1,nguon,tam,dich);
	HN(1,nguon,dich,tam);
	HN(n-1,tam,dich,nguon);
}
void HNKDQ(int n, int nguon,int dich, int tam)
{
	Stack s;
	init(s);
	BT b;
	b.n=n; b.nguon=nguon; b.dich=dich; b.tam=tam;
	push(s,b);
	while(!empty(s))
	{
		BT x;
		pop(s,x);
		if(x.n==1)
			printf("\n %d --> %d",x.nguon,x.dich);
		else
		{
			BT b1,b2,b3;
			b1.n=x.n-1; b1.nguon=x.nguon;b1.dich=x.tam;b1.tam=x.dich;
			b2.n=1; b2.nguon=x.nguon;b2.dich=x.dich;b2.tam=x.tam;
			b3.n=x.n-1; b3.nguon=x.tam;b3.dich=x.dich;b3.tam=x.nguon;
			push(s,b3);
			push(s,b2);
			push(s,b1);
		}
	}
}
Node* createNode(BT x)
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
void push(Stack &s,BT x)
{
	Node* p=createNode(x);
	p->next=s;
	s=p;
}
void pop(Stack &s,BT &x)
{
	if(empty(s)) return;
	x=s->info;
	Node* p;
	p=s;
	s=s->next;
	delete p;
}


