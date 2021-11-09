#include <stdio.h>
typedef struct _benhNhan{
	int stt;
	char ten[30];
	char diachi[50];
	int tuoi;
}BN;

typedef struct _node{
	BN info;
	struct _node *next;
}Node;

typedef struct _Queue{
	Node* head,*tail;
	int num;
}Queue;

void init(Queue &q);
int empty(Queue q);
void insert(Queue &q, BN x);
void remove(Queue &q,BN &x);
void clear(Queue &q);
void queueFirst(Queue q,BN &x);
void queueLast(Queue q,BN &x);
int queueSize(Queue q);
Node* createNode(BN x);

void nhap(BN &x);
void xuat(BN x);

int main()
{
	Queue hd;
	init(hd);
	int dk=0;
	do{
		printf("\n 1. Thoat");
		printf("\n 2. Them benh nhan can kham");
		printf("\n 3. Hien thi thong tin nguoi kham tiep theo");
		printf("\n 4. Cho biet so nguoi chua kham");
		printf("\n 5. Cho biet so nguoi da kham");
		printf("\n Ban chon chuc nang nao:");
		int chon;
		scanf("%d",&chon);
		if(chon==1)	
			return 0;
		if(chon==2)
		{
			BN x;
			nhap(x);
			insert(hd,x);
		}
		else if(chon==3)
		{
			BN x;
			remove(hd,x);
			xuat(x);
			dk++;
		}
		else if(chon==4)
		{
			printf("\n So nguoi chua kham la:%d",queueSize(hd));
		}
		else if(chon==5)
		{
			printf("\n So nguoi da kham la: %d",dk);
		}
		else
			printf("\n Chon tu 1 toi 5 trong menu!");
	}while(1);
	
	return 0;	
}
Node* createNode(BN x)
{
	Node* p;
	p=new Node();
	p->info=x;
	p->next=NULL;
	return p;
}
void init(Queue &q)
{
	q.head=q.tail=NULL;
	q.num=0;
}
int empty(Queue q)
{
	return q.head==NULL;
}
void insert(Queue &q,BN x)
{
	Node* p=createNode(x);
	q.num++;
	if(empty(q))
	{
		q.head=q.tail=p;		
	}else
	{
		q.tail->next=p;
		q.tail=p;		
	}
}

void remove(Queue &q,BN &x)
{
	if(empty(q)) return;
	Node* p=q.head;
	q.head=q.head->next;
	x=p->info;
	q.num--;
	delete p;
	if(empty(q)) q.tail=NULL;
}

void clear(Queue &q)
{
	Node* p;
	while(!empty(q))
	{
		p=q.head;
		q.head=q.head->next;
		delete p;
	}
	q.tail=NULL;
	q.num=0;
}
void queueFirst(Queue q,BN &x)
{
	if(empty(q)) return;
	x=q.head->info;
}
void queueLast(Queue q,BN &x)
{
	if(empty(q)) return;
	x=q.tail->info;
}

int queueSize(Queue q)
{
	return q.num;
}

void nhap(BN &x)
{
	printf("\n STT:");
	scanf("%d",&x.stt);
	printf("\n Ten:");
	fflush(stdin);
	gets(x.ten);
	printf("\n Dia chi:");
	fflush(stdin);
	gets(x.diachi);
	printf("\n Tuoi:");
	scanf("%d",&x.tuoi);
}

void xuat(BN x)
{
	printf("\n STT: %d",x.stt);
	printf("\n Ten:%s",x.ten);
	printf("\n Dia chi:%s",x.diachi);
	printf("\n Tuoi:%d",x.tuoi);
}

