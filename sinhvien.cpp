#include <stdio.h>

typedef struct _SV{
	int ma;
	char ten[30];
	float dtb;
}SV;
typedef struct _NODE{
	SV info;
	struct _NODE * next;	
}Node;
typedef struct _LIST{
	Node* phead;
	Node* ptail;
}LinkList;

void init(LinkList &ll)
{
	ll.phead=ll.ptail=NULL;
}

void init(Node* &phead)
{
	phead=NULL;
}
Node* createNode(SV x)
{
	Node* p=new Node();
	p->info=x;
	p->next=NULL;
	return p;
}
void insertFirst(Node* &phead,SV x)
{
	Node* p=createNode(x);
	p->next=phead;
	phead=p;
}
void xuat1SV(SV x)
{
	printf("\n Ma: %d",x.ma);
	printf("\n Ten: %s",x.ten);
	printf("\n DTB: %f",x.dtb);	
}
void showList(Node* phead)
{
	printf("\n Day so la:");
	for(Node* p=phead;p!=NULL;p=p->next)
	    xuat1SV(p->info);
}
Node* search(Node* phead,float y)
{
	for(Node* p=phead;p!=NULL;p=p->next)
		if(p->info.dtb==y)
			return p;
	return NULL;
}

void insertAfter(Node* p,SV z)
{
	if(p==NULL)
	{
		printf("\n Khong co node de chen sau!");
		return;
	} 
	Node* q=createNode(z);
	q->next=p->next;
	p->next=q;
}

void deleteFirst(LinkList &ll)
{
	if(ll.phead==NULL) return; //danh sach rong
	
	Node* p=ll.phead;
	ll.phead=ll.phead->next;
	delete p;
}
void deleteAfter(LinkList &ll, Node* p)
{
	if(p==NULL || p->next==NULL) return;
	if(p->next==ll.ptail) ll.ptail=p;
	Node* q=p->next;
	p->next=q->next;
	delete q;
}

void deleteN(LinkList &ll, int u)
{
	if(ll.phead==NULL) return; //danh sach rong	
	Node* q=ll.phead;
	Node* p=q;
	while(q!=NULL && q->info.ma!=u){
		p=q;
	    q=q->next;
	}
	if(q==ll.phead) deleteFirst(ll);
	else
		deleteAfter(ll,p);	
}


void nhap1SV(SV &x)
{
	printf("\n Nhap ma:"); 
	scanf("%d",&x.ma);
	printf("\n Nhap ten:"); 
	fflush(stdin);
	gets(x.ten);
	printf("\n Nhap dtb:"); 	
	scanf("%f",&x.dtb);
}
void insertLast(LinkList &ll,SV x)
{
	Node* p=createNode(x);
	if(ll.phead==NULL)
	{
		ll.phead=ll.ptail=p;
	}else
	{
		ll.ptail->next=p;
		ll.ptail=p;
	}
		
}
void nhapDSSV1(Node* &phead)
{
	//nhap 1 danh n so
	int n;
	printf("Nhap so luong sinh vie n:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Nhap phan tu thu %d:",i);
		SV x;
		nhap1SV(x);		
		insertFirst(phead,x);
	}
}

void nhapDSSV(LinkList &ll)
{
	//nhap 1 danh n so
	int n;
	printf("Nhap so luong sinh vien:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Nhap phan tu thu %d:",i);
		SV x;
		nhap1SV(x);
		insertLast(ll,x);				
	}
}
Node* searchMa(Node* phead,int x)
{
	for(Node* p=phead;p!=NULL;p=p->next)
		if(p->info.ma==x)
			return p;
	return NULL;
}
void insertAfter(LinkList &ll,Node* p,SV x)
{
	if(p==NULL)
		return;
	Node* q=createNode(x);
	if(p==ll.ptail)
	{
		ll.ptail->next=q;
		ll.ptail=q;
	}else
	{
		q->next=p->next;
		p->next=q;
	}
}
int main()
{
	//Node* phead;
	LinkList ll;	
	//khoi tao danh sach rong
	//init(phead);
	init(ll);
	nhapDSSV(ll);
	showList(ll.phead);
	/*
	float y;
	printf("\n Nhap vao gia tri can tim y:");
	scanf("%f",&y);
	Node* p=search(phead,y);
	if(p!=NULL)
		xuat1SV(p->info);
	/**/
	/*
	int x;
	printf("\n Nhap vao ma sinh vien x:");
	scanf("%d",&x);
Node* p=searchMa(ll.phead,x);
	SV z;
	nhap1SV(z);
	//insertAfter(p,z);
	insertAfter(ll,p,z);
	showList(ll.phead);
	/**/
	/*
	int z;
	printf("\n Nhap gia tri can chen z:");
	scanf("%d",&z);
	
	insertAfter(p,z);
	/**/
	
	//showList(phead);
	
	int u;
	printf("\n Nhap vao ma sinh vien can xoa u:");
	scanf("%d",&u);
	deleteN(ll,u);
	showList(ll.phead);
	/**/
	return 0;
}
