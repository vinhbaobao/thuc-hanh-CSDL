#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

template <class T>
struct Stack{
	T a[MAX];
	int n;	
};

template <class T>
void init(Stack<T> &s);

template <class T>
int empty(Stack<T>  s);

template <class T>
void push(Stack<T> &s,T x);

template <class T>
void pop(Stack<T> &s,T &x);

template <class T>
void top(Stack<T> s,T &x);


char* hauto(char *s);
int laToanTu(char c);
int doUuTien(char c);
int laToanHang(char c);
float tinhHauTo(char *s);
float doiso(char c);
float thucHienPhepToan(float a,float b,char c);

int main()
{
	
	char stt[MAX];
	char *sht;
	printf("\n Nhap bieu thuc trung to:");
	gets(stt);
	sht=hauto(stt);
	printf("\n Bieu thu hau to:%s",sht);
	float t=tinhHauTo(sht);
	printf("\n Gia tri bieu thuc la:%8.2f",t);
	/**/
	/*
	Stack<int> s;
	init(s);
	
	int x=10;
	push(s,x);
	int y;
	pop(s,y);
	printf("x=%d,y=%d",x,y);
	/**/
	return 0;
}

float tinhHauTo(char *sht)
{
	float t=0;
	Stack<float> s;
	init(s);
	int n=strlen(sht);
	int i=0;
	while(i<n)
	{
		int c=sht[i]; i++;
		if(laToanHang(c))
			push(s,doiso(c));
		else 
		if(laToanTu(c))
		{
			float a,b;
			pop(s,a);
			pop(s,b);
			float kq=thucHienPhepToan(b,a,c);
			push(s,kq);			
		}
	}	
	pop(s,t);
	return t;
}
char* hauto(char *stt)
{	
	Stack<char> s;
	init(s);
	char *sht;
	sht=(char* )malloc(sizeof(char)*MAX);
	int n=strlen(stt);	
	int i=0; int j=0;	
	char x;
	while(i<n)
	{
		char c=stt[i];	
		i++;	
		
		if(c=='(')
			push(s,c);
		else
		if(c==')')
		{
			pop(s,x);
			while(x!='(')
			{
				sht[j]=x;
				j++;
				pop(s,x);				
			}
		}else
		if(laToanTu(c)) 
		{
			if(!empty(s))
			{
				top(s,x);
				while(!empty(s) && doUuTien(x)>=doUuTien(c))
				{
					pop(s,x);
					sht[j]=x;
					j++;
					top(s,x);
				}
			}
			push(s,c);
		}else
		if(laToanHang(c))
		{
			sht[j]=c;
			j++;
		}					
	}
	while(!empty(s))
	{
		pop(s,x);
		sht[j]=x;
		j++;
	}
		
	sht[j]='\0';
	return sht;
}

int laToanTu(char c)
{
	if(c=='+' || c=='-' || c=='*' || c=='/')
		return 1;
	return 0;
}

int doUuTien(char c)
{
	if(c=='+' || c== '-')	return 1;
	if(c=='*' || c== '/')	return 2;
	return 0;
}

int laToanHang(char c)
{
	if(c>='0' && c<='9') return 1;
	return 0;
}
float doiso(char c)
{
	return c-'0';
}
float thucHienPhepToan(float a,float b,char c)
{
	if(c=='+')
		return a+b;
	if(c=='-')
		return a-b;
	if(c=='*')
		return a*b;
	if(c=='/')
		return a/b;
}

template <class T>
void init(Stack<T> &s)
{
	s.n=0;	
}

template <class T>
int empty(Stack<T> s)
{
	return s.n==0;
}

template <class T>
void push(Stack<T> &s,T x)
{	
	if(s.n==MAX) return;
	s.a[s.n]=x;
	s.n++;
}

template <class T>
void pop(Stack<T> &s,T &x)
{
	if(empty(s)) return;
	x=s.a[s.n-1];
	s.n--;
}

template <class T>
void top(Stack<T> s,T &x)
{
	if(empty(s)) return;
	x=s.a[s.n-1];
}

