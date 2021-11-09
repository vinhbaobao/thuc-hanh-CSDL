#include<stdio.h>
#include<conio.h>
 //Khai bao cau truc node
struct node
{
	int data;
	struct node* next;
};
//Khoi tao danh sach lien ket
void init(node* &phead)
{
	phead = NULL;
}
//Kiem tra danh sach co rong hay khong
int empty(node* phead)
{
  return (phead == NULL);
}
//Node co du lieu (x)
node* createnode(int x)
{
  	node* p = new node;
  	p->data = x;
  	p->next = NULL;
  	return p;
}
//Phan tu moi vao dau danh sach
void insert (node* &phead,int x)
{
	node* p=createnode(x);
	if(phead==NULL)
		phead=p;
	else{
		p->next=phead;
	}
}
//Xuat danh sach ra man hinh
void showlist(node* &phead)
{
	node* p=phead;
	if (p==NULL)
		printf("danh sach rong");
	while(p!=NULL)
	{
		printf("\t%d",p->data);
		p=p->next;		
	}
}
//Phan tu moi vao cuoi danh sach
void insertlast(node* &phead, int x)
{
	node* tam,*p;
	p=createnode(x);
	if(phead==NULL)
	phead=p;
	else{
		tam=phead;
		while(tam->next!=NULL)
			tam=tam->next;
		tam->next=p;
	}
}
void inputlist (node* & phead)
{
	init (phead);
	int n,x;
	printf("nhap so luong phan tu ");
	scanf("\t%d:",&n);
	for( int i=0;i<n;i++)
	{
		printf("phan tu can nhap la:");
		scanf("%d",&x);
		insertlast(phead,x);
	}
}
//Tim  phan tu co gia tri (x)
node* search(node* phead,int y)
{
	for(node* p=phead;p!=NULL;p=p->next)
		if(p->data==y)
			return p;
	return NULL;
}
void insertAfter(node* p,int k)
{
	if(p==NULL)
	{
		printf("\n khong co node!");
		return;
	} 
	node* q=createnode(k);
	q->next=p->next;
	p->next=q;
}
//Dem so nut trong danh sach 
int Dem(node* &pHead)
{
	int count=0;
	node* n=pHead;
	while(n!=NULL)
	{
		count++;
		n=n->next; 
	} 
return count;
}
//Tim Node thu k trong danh sach lien ket
int get(node* &phead,int index)
{
	int k=0;
	node* p=phead;
	while(p->next!=NULL && k!=index){
		++k;
		phead=p->next;
	}
	return p->data;
}
// Tim Max lon nhat 
int Max(node* &phead)
{
	node *p;
	int Max;
	Max=phead->data;
	while(phead!=NULL)
	{
		if(Max<p->data)
		{
			Max= p->data;
		}
		phead=p->next;
	}
	return Max;
}
//Xoa 1 phan tu co khoa la (x)
void deleteFirst(node* &phead)
{
	if(phead==NULL) 
		return;
	node* p=phead;
	phead=phead->next;
	delete p;
}
void deleteAfter(node* p)
{
	if(p==NULL||p->next==NULL) 
		return;
	node* q=p->next;
	p->next=q->next;
	delete q;
}
void deleteN(node* &phead, int u)
{
	if(phead==NULL) 
		return;
	node* p=phead;
	node* q=p;
	while(p!=NULL && p->data!=u){
		q=p;
	    p=p->next;
	}
	if(p==phead) deleteFirst(phead);
	else
		deleteAfter(q);
	
}
int main ()
{
	node* phead ;
	inputlist(phead);
	printf("DSLK:");
	showlist(phead);
	int y;
	printf("\n Nhap vao gia tri can tim x:");
	scanf("%d",&y);
	printf("\n Nhap vao gia tri can xoa x:");
	scanf("%d",&y); 
	printf("\n So nut trong danh sach la: %d",Dem(phead));
	printf("\n Node thu k trong danh sach: %d");
	scanf("%d",&y);
	printf("\nPhan tu lon nhat trong danh sach la: %d",Max(phead));
	int z;
	printf("\n Nhap gia tri can chen :");
	scanf("%d",&z);
	node* p=search(phead,y);
	insertAfter(p,z);
	showlist(phead);
	return 0;
}

