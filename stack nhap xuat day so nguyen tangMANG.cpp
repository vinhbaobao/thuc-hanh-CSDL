
#include <stdio.h>
#define MAX 100
typedef struct _BT{
	int l;
	int r;
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
void swap(int &a,int &b);
void sxNhanh(int a[],int n);
void nhap(int a[],int n);
void xuat(int a[],int n);

int main()
{
	int a[100];
	int n;
	n=5;
	nhap(a,n);
	xuat(a,n);
	sxNhanh(a,n);
	xuat(a,n);
	return 0;
}
void nhap(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\n Nhap a[%d]:",i);
		scanf("%d",&a[i]);
	}
}
void  xuat(int a[],int n)
{
	printf("\n Day so la:");
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
void swap(int &a,int &b)
{
	int t;
	t=a;
	a=b;
	b=t;
}
void sxNhanh(int a[],int n)
{
	Stack s;
	init(s); 
	BT b;
	b.l=0; b.r=n-1;
	push(s,b);
	while(!empty(s))
	{
		BT x;
		pop(s,x);
		int i,j;
		int coc=a[(x.l+x.r)/2];
		i=x.l; j=x.r;
		do{ //sx tang
			while(a[i]<coc) i++;
			while(a[j]>coc) j--;
			if(i<=j)
			{
				swap(a[i],a[j]);
				i++; 
				j--;
			}
		}while(i<j);
		BT b1,b2;
		b1.l=x.l; b1.r=j;
		b2.l=i; b2.r=x.r;
		if(x.l<j) push(s,b1);
		if(i<x.r) push(s,b2);		
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


