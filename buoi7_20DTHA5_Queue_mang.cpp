#include <stdio.h>
#include <string.h>
#define MAX 100

struct SoKham{
	int stt;
	char ten[30];
	int tuoi;
};

template <class T>
struct Queue{
	T a[MAX];
	int head, tail;
	int count;
};
template <class T>
void init(Queue<T> &q);

template <class T>
int empty(Queue<T> q);

template <class T>
void insert(Queue<T> &q, T x);

template <class T>
void remove(Queue<T> &q, T &x);

template <class T>
void queueFirst(Queue<T> q, T &x);

template <class T>
void queueLast(Queue<T> q, T &x);

template <class T>
int queueSize(Queue<T> q);

template <class T>
void clear(Queue<T> &q);


void nhap(SoKham &x);
void xuat(SoKham x);

int main()
{
	Queue<SoKham> q;
	init(q);
	int dk=0;
	do{
		printf("\n 0: thoat");
		printf("\n 1: Dang ky kham");
		printf("\n 2: Thong tin nguoi kham tiep theo");
		printf("\n 3: So nguoi chua kham");
		printf("\n 4: So nguoi da kham");
		int chon;
		printf("\n Ban cho chuc nang can lam (0-4):");
		scanf("%d",&chon);
		if(chon==0) return 0;
		if(chon==1)
		{
			SoKham x;
			nhap(x);
			insert(q,x);			
		}else
		if(chon==2)
		{
			SoKham x;
			remove(q,x);
			xuat(x);
			dk++;
		}else
		if(chon==3)
		{
			printf("\n so nguoi chua kham la:%d",queueSize(q));
		}else
			printf("\n so nguoi da kham la:%d",dk);
		
	}while(1);
	return 0;
}
void nhap(SoKham &x)
{
	printf("\n STT:");
	scanf("%d",&x.stt);
	printf("\n Ten:");
	fflush(stdin);
	gets(x.ten);
	printf("\n Tuoi:");
	scanf("%d",&x.tuoi);
}
void xuat(SoKham x)
{
	printf("%d \t %s \t %d",x.stt,x.ten,x.tuoi);
}


template <class T>
void init(Queue<T> &q)
{
	q.head=0;
	q.tail=-1;
	q.count=0;
}

template <class T>
int empty(Queue<T> q)
{
	return q.count==0;
}
template <class T>
void insert(Queue<T> &q, T x)
{
	if(q.count==MAX) return;
	q.tail++;
	if(q.tail==MAX) q.tail=0;
	q.a[q.tail]=x;
	q.count++;
}

template <class T>
void remove(Queue<T> &q, T &x)
{
	if(empty(q)) return;
	x=q.a[q.head];
	q.head++;
	if(q.head==MAX) q.head=0;
	q.count--;	
}

template <class T>
void queueFirst(Queue<T> q, T &x)
{
	if(empty(q)) return;
	x=q.a[q.head];
}

template <class T>
void queueLast(Queue<T> q, T &x)
{
	if(empty(q)) return;
	x=q.a[q.tail];
}

template <class T>
int queueSize(Queue<T> q)
{
	return q.count;
}

template <class T>
void clear(Queue<T> &q)
{
	init(q);
}

