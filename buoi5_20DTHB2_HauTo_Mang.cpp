#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct _Stack
{
	char a[MAX];
	int n;
}Stack;
typedef char DataType;

void init(Stack &s);
int empty(Stack s);
void push(Stack &s,DataType x);
void pop(Stack &s,DataType &x);
char* doiSangHauTo(char* stt);

void top(Stack s,DataType &x);

int laToanHang(char x);
int y;
int laPhepToan (char y);
int doUuTien(char x);

int main()
{
	char stt[30];
	printf("\n Nhap chuoi trung to:");
	scanf("%s",stt);
	char* sht;
	sht=doiSangHauTo(stt);
	printf("\n Bieu dien hau to la:%s",sht);
	return 0;
}
void top(Stack s,DataType &x)
{
	x=s.a[s.n-1];	
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
	if(x=='*' || x=='/') return 10;
	if(x=='+' || x=='=') return 5;
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

void init(Stack &s)
{
	s.n=0;
}
int empty(Stack s)
{
	return s.n==0;
}
void push(Stack &s,DataType x)
{
	s.a[s.n]=x;
	s.n++;
}
void pop(Stack &s,DataType &x)
{
	x=s.a[s.n-1];
	s.n--;
}


