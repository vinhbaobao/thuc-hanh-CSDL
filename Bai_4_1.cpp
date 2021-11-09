#include<stdio.h>

typedef struct node{
	int info;
	struct node* next;
}Node;
typedef Node* STACK;

void init(STACK &s)
{
	s == NULL;
}

int empty(STACK s)
{
  return (s == NULL);
}

int push(STACK &s, int x)
{
	Node* p = new Node;
	if(p==NULL)	return 0;
	p->info = x;
	p->next = s;
	s = p;
	return 1;
}

int pop(STACK &s, int &x)
{
		if(empty(s))		return 0;
		Node*  p = s;
		x = p->info;
		s = s->next;
	delete p;
	return 1;
}

void convert(STACK &s, int n)
{
	int Sodu;
	while(n!=0)
	{
		Sodu=n%2;
		push(s,Sodu);
		n=n/2;
	}
}

int output(STACK s)
{
	while(s!=NULL)
	{
		//Goi ham pop de lay ra 1 phan tu
		//in phan tu do ra
		int x;
		pop(s,x);
		printf("%d",x);
	}
}

int main()
{
	STACK s;
	init(s);
	int n;
	printf("Nhap so o he thap phan: ");
	scanf("%d",&n);
	convert(s,n);
	output(s);
}
