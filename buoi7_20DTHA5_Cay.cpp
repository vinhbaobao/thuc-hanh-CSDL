#include <stdio.h>

struct Node{
	int info;
	Node *left, *right;
};

void init(Node* &ptree);
int empty(Node* ptree);
Node* createNode(int x);

void insert(Node* &ptree,int x);
void insertLeft(Node* &ptree,int x);
void insertRight(Node* &ptree,int x);

void deleteLeft(Node* &ptree);
void deleteRight(Node* &ptree);
Node* searchBST(Node* ptree, int x);
void insertBST(Node* &ptree,int x);
void deleteBST(Node* &ptree,int x);
void xoayTraiBST(Node* &ptree);
void xoayPhaiBST(Node* &ptree);

void preOrder(Node* ptree);
void inOrder(Node* ptree);
void postOrder(Node* ptree);
void clear(Node* &ptree);
Node* search(Node* ptree,int x);

int demLa(Node* ptree);			
int demNode(Node* ptree);			
int doCaoCay(Node*  ptree);			
Node* timMax(Node* ptree);			
long tongCay(Node* ptree);			
int demX(Node* ptree,int x);

int main()
{
	Node* ptree;
	init(ptree);
	do{
		printf("\n 0: thoat");
		printf("\n 1: Them vao node goc");
		printf("\n 2: Them vao ben trai cua node y");
		printf("\n 3: Them vao ben phai cua node y");
		printf("\n 4: Xuat cay theo thu tu truoc");
		printf("\n 5: Xuat cay theo thu tu giua");
		printf("\n 6: Xuat cay theo thu tu sau");
		printf("\n 7: Xoa node ben trai node y");
		printf("\n 8: Xoa node ben phai node y");
		printf("\n 9: xoa cay");
		printf("\n 10: Dem so node la");
		printf("\n 11: Dem so node tren cay");
		printf("\n 12: Chieu cao cay");
		printf("\n 13: Tim gia tri lon nhat tren cay");
		printf("\n 14: Tinh tong gia tri cay");
		printf("\n 15: Dem so node co gia tri bang x");
		printf("\n 16: Tim x tren cay BST");
		printf("\n 17: Chen x tren cay BST");
		printf("\n 18: Xoa x tren cay BST");
		printf("\n 19: Xoay trai cay BST");
		printf("\n 20: Xoay phai cay BST");
		
		int chon;
		printf("\n Ban chon chuc nang nao:");
		scanf("%d",&chon);
		if(chon==0) return 0;
		if(chon==1)
		{
			int x;
			printf("\n Nhap x:");
			scanf("%d",&x);
			printf("\n ptree=%d",ptree);
			insert(ptree,x);
			printf("\n ptree=%d",ptree);
			continue;
		}
		if(chon==2)
		{
			int x,y;
			printf("\n Nhap x,y:");
			scanf("%d%d",&x,&y);
			Node *p=search(ptree,y);
			if(empty(p))
				printf("\n Khong ton tai node %d",y);
			else{
				printf("\n p=%d, L:%d, R:%d",p,p->left,p->right);
				insertLeft(p,x);
				printf("\n p=%d, L:%d, R:%d",p,p->left,p->right);
			}
			continue;
		}
		if(chon==3)
		{
			int x,y;
			printf("\n Nhap x,y:");
			scanf("%d%d",&x,&y);
			Node *p=search(ptree,y);
			if(empty(p))
				printf("\n Khong ton tai node %d",y);
			else{
				printf("\n p=%d, L:%d, R:%d",p,p->left,p->right);
				insertRight(p,x);
				printf("\n p=%d, L:%d, R:%d",p,p->left,p->right);
			}
			continue;
		}
		if(chon==4)
		{
			printf("\n Day so la:");
			preOrder(ptree);
			continue;
		}
		if(chon==5)
		{
			printf("\n Day so la:");
			inOrder(ptree);
			continue;
		}
		if(chon==6)
		{
			printf("\n Day so la:");
			postOrder(ptree);
			continue;
		}
		if(chon==7)
		{
			int y;
			printf("\n Nhap y:");
			scanf("%d",&y);
			Node *p = search(ptree,y);
			deleteLeft(p);
			continue;
		}
		if(chon==8)
		{
			int y;
			printf("\n Nhap y:");
			scanf("%d",&y);
			Node *p = search(ptree,y);
			deleteRight(p);
			continue;
		}
		if(chon==9)
		{
			clear(ptree);
			continue;
		}
		if(chon==10)
		{
			int d=demLa(ptree);
			printf("\n So node la la:%d",d);
			continue;
		}
		
		if(chon==11)
		{
			int d=demNode(ptree);
			printf("\n So node tren cay la:%d",d);
			continue;
		}
		if(chon==12)
		{
			int d=doCaoCay(ptree);
			printf("\n Do cao cua cay la:%d",d);
			continue;
		}
		if(chon==13)
		{
			Node *p=timMax(ptree);
			if(p!=NULL)
				printf("\n Gia tri Max cua cay la:%d",p->info);
			else
				printf("\n Cay rong!");
			continue;
		}
		if(chon==14)
		{
			long t=tongCay(ptree);
			printf("\n Tong gia tri cay la:%ld",t);
			continue;
		}
		if(chon==15)
		{
			int x;
			printf("\n Nhap x:");
			scanf("%d",&x);
			int d=demX(ptree,x);
			printf("\n So node co gia tri bang %d la:%d",x,d);
			continue;
		}
		if(chon==16)
		{
			int x;
			printf("\n Nhap x:");
			scanf("%d",&x);
			Node* p=searchBST(ptree,x);
			if(p==NULL)
				printf("\n Khong tim thay %d tren cay BST",x);
			else
				printf("\n Tim thay o node co dia chi %d",p);
			continue;
		}
		if(chon==17)
		{
			int x;
			printf("\n Nhap x:");
			scanf("%d",&x);
			insertBST(ptree,x);
			continue;
		}
		if(chon==18)
		{
			int x;
			printf("\n Nhap x:");
			scanf("%d",&x);
			deleteBST(ptree,x);
			continue;
		}
		if(chon==19)
		{
			xoayTraiBST(ptree);
			continue;
		}
		if(chon==20)
		{
			xoayPhaiBST(ptree);
			continue;
		}
		/**/
	}while(1);
	return 0;
}

void init(Node* &ptree)
{
	ptree=NULL;
}
int empty(Node* ptree)
{
	return ptree==NULL;
}
Node* createNode(int x)
{
	Node* p=new Node();
	p->info=x;
	p->left=NULL;
	p->right=NULL;
	return p;
}

void insert(Node* &ptree,int x)
{
	if(!empty(ptree)) return;
	ptree=createNode(x);
}
void insertLeft(Node* &ptree,int x)
{
	if(empty(ptree)) return;
	if(!empty(ptree->left)) return;
	ptree->left=createNode(x);
}
void insertRight(Node* &ptree,int x)
{
	if(empty(ptree)) return;
	if(!empty(ptree->right)) return;
	ptree->right=createNode(x);
}

void deleteLeft(Node* &ptree)
{
	if(empty(ptree)) return;
	if(empty(ptree->left)) return;
	Node *p=ptree->left;
	if(empty(p->left) && empty(p->right))
	{
		ptree->left=NULL;
		delete p;
	}
}
void deleteRight(Node* &ptree)
{
	if(empty(ptree)) return;
	if(empty(ptree->right)) return;
	Node *p=ptree->right;
	if(empty(p->left) && empty(p->right))
	{
		ptree->right=NULL;
		delete p;
	}
}

void preOrder(Node* ptree)
{
	if(empty(ptree)) return;
	printf("\n %d, Dia chi node: %d, L:%d, R:%d ", ptree->info,ptree,ptree->left,ptree->right);
	preOrder(ptree->left);
	preOrder(ptree->right);
}
void inOrder(Node* ptree)
{
	if(empty(ptree)) return;	
	inOrder(ptree->left);
	printf("%d ", ptree->info);
	inOrder(ptree->right);
}
void postOrder(Node* ptree)
{
	if(empty(ptree)) return;	
	postOrder(ptree->left);	
	postOrder(ptree->right);
	printf("%d ", ptree->info);
}
void clear(Node* &ptree)
{
	if(empty(ptree)) return;
	clear(ptree->left);
	clear(ptree->right);
	delete ptree;
}
Node* search(Node* ptree,int x)
{
	if(empty(ptree)) return NULL;
	if(ptree->info==x) return ptree;
	Node* p=search(ptree->left,x);
	if(empty(p)) p=search(ptree->right,x);
	return p;
}

int demLa(Node* ptree)
{
	if(empty(ptree)) return 0;
    if(empty(ptree->left) && empty(ptree->right))
    	return 1;
    return demLa(ptree->left) + demLa(ptree->right);
}			

int demNode(Node* ptree)
{
	if(empty(ptree)) return 0;
	return 1+ demNode(ptree->left) + demNode(ptree->right);
}			
int doCaoCay(Node*  ptree)
{
	if(empty(ptree)) return -1;
	int dt=doCaoCay(ptree->left);
	int dp=doCaoCay(ptree->right);
	if(dt>dp)
		return dt+1;
	return dp+1;
}		
Node* timMax(Node* ptree)
{
	if(empty(ptree)) return NULL;
	Node* mt=timMax(ptree->left);
	Node* mp=timMax(ptree->right);
	Node *pm=ptree;
	if(mt!=NULL && mt->info>pm->info) pm=mt;
	if(mp!=NULL && mp->info>pm->info) pm=mp;
	return pm;	
}
long tongCay(Node* ptree)
{
	if(empty(ptree)) return 0;
	return ptree->info+tongCay(ptree->left) + tongCay(ptree->right);
}
int demX(Node* ptree,int x)
{
	if(empty(ptree)) return 0;
	int d=0;
	if(ptree->info==x) d=1;
	return d+ demX(ptree->left,x) + demX(ptree->right,x);
}

Node* searchBST(Node* ptree, int x)
{
	if(empty(ptree)) return NULL;
	if(ptree->info==x) return ptree;
	if(x<ptree->info) 
		return searchBST(ptree->left,x);
	return searchBST(ptree->right,x);
}
void insertBST(Node* &ptree,int x)
{
	if(empty(ptree)) 
	{
		ptree=createNode(x);
		return;
	}
	if(x<ptree->info) 
		insertBST(ptree->left,x);
	else
		insertBST(ptree->right,x);
}
void deleteBST(Node* &ptree,int x)
{
	if(empty(ptree)) return;
	if(x<ptree->info) 
		return deleteBST(ptree->left,x);
	if(x>ptree->info)
		return deleteBST(ptree->right,x);
	Node* p=ptree;
	if(empty(ptree->left))
		ptree=ptree->right;
	else
	if(empty(ptree->right))
		ptree=ptree->left;
	else
	{
		Node *f, *rp;
		f=p;
		rp=p->right;
		while(!empty(rp->left))
		{
			f=rp;
			rp=rp->left;
		}
		p->info=rp->info;
		if(f==p)
			p->right=rp->right;
		else
			f->left=rp->right;
		p=rp;
	}
	delete p;
}
void xoayTraiBST(Node* &ptree)
{
	if(empty(ptree)) return;
	if(empty(ptree->right)) return;
	Node *p;
	p=ptree->right;
	ptree->right=p->left;
	p->left=ptree;
	ptree=p;
}
void xoayPhaiBST(Node* &ptree)
{
	if(empty(ptree)) return;
	if(empty(ptree->left)) return;
	Node *p;
	p=ptree->left;
	ptree->left=p->right;
	p->right=ptree;
	ptree=p;
}

