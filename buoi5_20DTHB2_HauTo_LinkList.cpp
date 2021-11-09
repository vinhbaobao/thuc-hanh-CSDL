#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef char datatype;
typedef struct _Node
{
	datatype info;
	struct _Node *next;
}Node;
typedef Node* Stack;




typedef struct _Nodef
{
	float info;
	struct _Nodef *next;
}Nodef;
typedef Node* Stackf;



Node* createNodef(float x);
void initf(Stackf &s);
int emptyf(Stackf s);
void pushf(Stackf &s,float x);
void popf(Stackf &s,float &x);
void topf(Stackf s,float &x);




Node* createNode(datatype x);
void init(Stack &s);
int empty(Stack s);
void push(Stack &s,datatype x);
void pop(Stack &s,datatype &x);
void top(Stack s,datatype &x);



int laToanHang(char x);
int y;
int laPhepToan (char y);
int doUuTien(char x);
char* doiSangHauTo(char* stt);
float tinh(char* s);
float doiso(char x);

int main()
{
	char stt[30];
	printf("\n Nhap chuoi trung to:");
	scanf("%s",stt);
	char* sht;
	sht=doiSangHauTo(stt);
	printf("\n Bieu dien hau to la:%s",sht);
	printf("\n Gia tri bieu thuc la: %f",tinh(sht));
	return 0;
}

float doiso(char x)
{
	return (float)(x-'0');
}
float tinh(char* ht)
{
	Stackf s;
	initf(s);
	int n=strlen(ht);
	int i=0;
	int t=0;
	while(i<n)
	{
		char x=ht[i]; 
		i++;
		if(laToanHang(x)) pushf(s,doiso(x));
		if(laPhepToan(x))
		{
			float a,b;
			float t;
			popf(s,a);
			popf(s,b);
			if(x=='+') t=b + a;
			if(x=='-') t=b - a;
			if(x=='*') t=b * a;
			if(x=='/') t=b / a;
			pushf(s,t);
		}		
	}	
	float x;
	popf(s,x);
	return x;
}

void top(Stack s,datatype &x)
{
	x=s->info;
}
int laToanHang(char x)
{
	if(x>='0' && x<='9') return 1;	
	return 0;
}

int laPhepToan(char y)
{
	if(y=='+' || y=='-' || y=='*' || y=='/')	
		return 1;
	return 0;
}


int doUuTien(char x)
{
	if(x=='*' || x=='/') return 2;
	if(x=='+' || x=='-') return 1;
	return 0;	
}
char* doiSangHauTo(char* stt)
{
	Stack s;
	init(s);
	char* ht;
	int t=0;
	ht=(char*)malloc(sizeof(char)*30);
	
	int n;
	n=strlen(stt);
	for(int i=0;i<n;i++)
	{
		char x=stt[i];
		if(laToanHang(x))
		{
			ht[t]=x; 
			t++;
		}		
		if(x=='(')
		{
			push(s,x);
		}
		if(x==')')
		{
			char y;
			do{
				pop(s,y);
				if(laPhepToan(y))
				{	
					ht[t]=y; t++;
				}
			}while(y=='(');
		}
		
		if(laPhepToan(x))
		{
			char y;
			do{
				top(s,y);
				if(doUuTien(y)>doUuTien(x))
				{
					pop(s,y);
					ht[t]=y;t++;
				}else
					break;
			}while(!empty(s));
			push(s,x);
		}
		
	}
	//con ky tu thi dua vao hau
	while(!empty(s))
	{
		char x;		
		pop(s,x);
		if(laPhepToan(x))
		{	ht[t]=x;
			t++;	
		}
	}
	ht[t]='\0';
	return ht;
}


 
 
Node* createNode(datatype x)
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
void push(Stack &s,datatype x)
{
	Node* p=createNode(x);
	p->next=s;
	s=p;
}
void pop(Stack &s,datatype &x)
{
	if(empty(s)) return;
	x=s->info;
	Node* p;
	p=s;
	s=s->next;
	delete p;
}



Node* createNodef(float x)
{
	Node* p;
	p=new Node();
	p->info=x;
	p->next=NULL;
	return p;
}
void initf(Stackf &s)
{
	s=NULL;
}
int emptyf(Stackf s)
{
	return s==NULL;
}
void pushf(Stackf &s,float x)
{
	Node* p=createNode(x);
	p->next=s;
	s=p;
}
void popf(Stackf &s,float &x)
{
	if(empty(s)) return;
	x=s->info;
	Node* p;
	p=s;
	s=s->next;
	delete p;
}

