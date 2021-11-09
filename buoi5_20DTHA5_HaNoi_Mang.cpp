#include <stdio.h>
#define MAX 100
typedef struct _BT{
	int n;
	int nguon;
	int dich;
}BT;
typedef struct _Stack
{
	BT a[MAX];
	int n;
}Stack;

void init(Stack &s);
int empty(Stack s);
void push(Stack &s,BT x);
void pop(Stack &s,BT &x);

void HN(int n, int nguon,int dich, int tam);
void HNKDQ(int n, int nguon,int dich);


int main()
{
	int n=4;
	printf("\n Ket qua de quy:");
	HN(n,1,2,3);
	printf("\n Ket qua khong de quy:");
	HNKDQ(n,1,2);
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
void HNKDQ(int n, int nguon,int dich)
{
	Stack s;
	init(s);
	BT b;
	b.n=n; b.nguon=nguon;b.dich=dich;
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
			int tam=6-x.nguon-x.dich;
			b1.n=x.n-1; b1.nguon=x.nguon; b1.dich=tam; 
			b2.n=1; b2.nguon=x.nguon;b2.dich=x.dich;
			b3.n=x.n-1; b3.nguon=tam; b3.dich=x.dich;
			push(s,b3);
			push(s,b2);
			push(s,b1);
		}
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
void push(Stack &s,BT x)
{
	s.a[s.n]=x;
	s.n++;
}
void pop(Stack &s,BT &x)
{
	x=s.a[s.n-1];
	s.n--;
}


