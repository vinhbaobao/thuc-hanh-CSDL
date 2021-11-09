#include <stdio.h>
//
typedef struct _benhNhan{
	int stt;
	char ten[30];
	char diachi[50];
	int tuoi;
}BN;
//
typedef struct _node{
	BN info;
	struct _node *next;
}Node;
//
typedef struct _Queue{
	Node* Phead;
	Node* Ptail;
	int num;
}Queue;
Node* createNode(BN x)
{
	Node* p;
	p=new Node();
	p->info=x;
	p->next=NULL;
	return p;
}
//
void init(Queue &q)
{
	q.Phead=q.Ptail=NULL;
	q.num=0;
}
int empty(Queue q)
{
	return q.Phead==NULL;
}
//
void insert(Queue &q,BN x)
{
	Node* p=createNode(x);
	q.num++;
	if(empty(q))
	{
		q.Phead=q.Ptail=p;		
	}else
	{
		q.Ptail->next=p;
		q.Ptail=p;		
	}
}
//
void remove(Queue &q,BN &x)
{
	if(empty(q)) return;
	Node* p=q.Phead;
	q.Phead=q.Phead->next;
	x=p->info;
	q.num--;
	delete p;
	if(empty(q)) q.Ptail=NULL;
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
int main()
{
	Queue hd;
	init(hd);
	int dk=0;
	do{
		printf("\n 1. Thoat");
		printf("\n 2. Them benh nhan can kham");
		printf("\n 3. Hien thi thong tin nguoi kham tiep theo");
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

		else if(chon==5)
		{
			printf("\n So nguoi da kham la: %d",dk);
		}
		else
			printf("\n Chon tu 1 toi 5 trong menu!");
	}while(1);
	
	return 0;	
}


