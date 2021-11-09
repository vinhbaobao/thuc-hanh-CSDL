#include <stdio.h>

struct Node
{
	int info;
	Node *left,*right;	
};

void init(Node* &ptree);
int empty(Node* ptree);
Node* createNode(int x);

void insertLeft(Node* &ptree,int x);
void insertRight(Node* &ptree,int x);
void insert(Node* &ptree,int x);
void deleteLeft(Node* &ptree);
void deleteRight(Node* &ptree);
Node* searchNP(Node* ptree, int x);
void insertBST(Node* &ptree,int x);
void deleteBST(Node* &ptree,int x);
void xoayTraiBST(Node* &ptree);
void xoayPhaiBST(Node* &ptree);

Node* search(Node* ptree,int x);
void xuatNLR(Node* ptree);
void xuatLNR(Node* ptree);
void xuatLRN(Node* ptree);
void xoa(Node* &ptree);

int demLa(Node* ptree);
int demNode(Node* ptree);
int doSau(Node* ptree);
int maxCay(Node* ptree);
int tongCay(Node* ptree);
int demNodex(Node* ptree,int x);



int main()
{
	Node* ptree;
	init(ptree);
	do{
		printf("\n 0: thoat");
		
		//nhap day so nguyen vao cay va xuat day so nguyen ra man minh bang cac phuong phap duyet cay
		printf("\n 1: Them vao node goc");
		printf("\n 2: Them vao ben trai cua node y");
		printf("\n 3: Them vao ben phai cua node y");
		printf("\n 4: Xuat day so theo thu tu truoc");
		printf("\n 5: Xuat day so theo thu tu giua");
		printf("\n 6: Xuat day so theo thu tu sau");
		printf("\n 7: xoa ben trai node y");
		printf("\n 8: xoa ben phai node y");
		printf("\n 9: xoa toan bo cay");
		printf("\n 10: Dem so node la");
		printf("\n 11: Dem so node tren cay");
		printf("\n 12: Do sau cua cay");
		printf("\n 13: Tim Max");
		printf("\n 14: Tinh tong");
		printf("\n 15: Dem so node gia tri bang x");
		printf("\n 16: Tim nhi phan tren cay BST");
		printf("\n 17: Chen x vao cay BST");
		printf("\n 18: Xoa x tren cay BST");
		printf("\n 19: Xoay trai cay BST");
		printf("\n 20: Xoay phai cay BST");
		
		int chon;
		printf("\n Ban chon chuc nang nao (0-9):");		
		scanf("%d",&chon);
		if(chon==0) return 0;
		if(chon==1)
		{
			int x;
			printf("\n Nhap x:");
			scanf("%d",&x);
			insert(ptree,x);
		}else
		if(chon==2)
		{
			int x,y;
			printf("\n Nhap x,y:");
			scanf("%d%d",&x,&y);
			Node* p=search(ptree,y);
			if(p==NULL)
				printf("\n Khong ton tai node %d",y);
			else
			{
				printf("%d, l:%d, r:%d ",p->info,p->left,p->right);
				insertLeft(p,x);
				printf("%d, l:%d, r:%d ",p->info,p->left,p->right);
			}
		}else
		if(chon==3)
		{
			int x,y;
			printf("\n Nhap x,y:");
			scanf("%d%d",&x,&y);
			Node* p=search(ptree,y);
			if(p==NULL)
				printf("\n Khong ton tai node %d",y);
			else
			{
				printf("%d, l:%d, r:%d ",p->info,p->left,p->right);
				insertRight(p,x);
				printf("%d, l:%d, r:%d ",p->info,p->left,p->right);
			}
		}else
		if(chon==4)
		{
			printf("\n Day so la (NLR):");
			xuatNLR(ptree);
		}else
		if(chon==5)
		{
			printf("\n Day so la (LNR):");
			xuatLNR(ptree);
		}else
		if(chon==6)
		{
			printf("\n Day so la (LRN):");
			xuatLRN(ptree);
		}else
		if(chon==7)
		{
			int y;
			printf("\n Nhap y:");
			scanf("%d",&y);
			Node* p=search(ptree,y);
			if(p==NULL)
				printf("\n Khong ton tai node %d",y);
			else
				deleteLeft(p);
		}
		else
		if(chon==8)
		{
			int y;
			printf("\n Nhap y:");
			scanf("%d",&y);
			Node* p=search(ptree,y);
			if(p==NULL)
				printf("\n Khong ton tai node %d",y);
			else
				deleteRight(p);
		}else
		if(chon==9)
		{
			xoa(ptree);
		}
		else
		if(chon==10)
		{
			int d=demLa(ptree);
			printf("\n So la la:%d",d);
		}
		else
		if(chon==11)
		{
			int d=demNode(ptree);
			printf("\n So node trong cay la:%d",d);
		}
		else
		if(chon==12)
		{
			int d=doSau(ptree);
			printf("\n Do sau la:%d",d);
		}
		else
		if(chon==13)
		{
			int maxc=maxCay(ptree);
			printf("\n Gia tri lon nhat trong cay la:%d",maxc);
		}
		else
		if(chon==14)
		{
			int tong=tongCay(ptree);
			printf("\n Tong cay la:%d",tong);
		}
		else
		if(chon==15)
		{
			printf("\n Nhap x:");
			int x;
			scanf("%d",&x);
			int d=demNodex(ptree,x);
			printf("\n So node co gia tri bang %d la:%d",x,d);
		}else
		if(chon==16)
		{
			printf("\n Nhap x de tim nhi phan:");
			int x;
			scanf("%d",&x);
			Node* p=searchNP(ptree,x);
			if(p==NULL)
				printf("\n Khong tim thay %d trong cay!",x);
			else
				printf("\n Tim thay x o dia chi %d",p);
		}else
		if(chon==17)
		{
			printf("\n Nhap vao x de chen cay BST");
			int x;
			scanf("%d",&x);
			insertBST(ptree,x);
		}else
		if(chon==18)
		{
			printf("\n Nhap vao x de xoa tre cay BST");
			int x;
			scanf("%d",&x);
			deleteBST(ptree,x);
		}else
		if(chon==19)
			xoayTraiBST(ptree);
		else
		if(chon==20)
			xoayPhaiBST(ptree);
	}while(1);
	return 0;
}
int demLa(Node* ptree)
{
	int d=0;
	if(ptree==NULL) return d;
	if(ptree->left==NULL && ptree->right==NULL) return 1;
	d=demLa(ptree->left) + demLa(ptree->right);
	return d;
}
int demNode(Node* ptree)
{
	int d=0;
	if(empty(ptree)) return 0;
	d=1+ demNode(ptree->left) + demNode(ptree->right);
	return d;
}
int doSau(Node* ptree)
{
	int d=-1;
	if(empty(ptree)) return -1;	
	int dt,dp;
	dt=doSau(ptree->left);
	dp=doSau(ptree->right);
	if(dt>dp)
		d=1+ dt;
	else
		d=1+dp;
	return d;
	
}
int maxCay(Node* ptree)
{
	int d=0;
	
	return d;
}
int tongCay(Node* ptree)
{
	int d=0;
	
	return d;
}
int demNodex(Node* ptree,int x)
{
	int d=0;
	
	return d;
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
	Node *p=new Node();
	p->info=x;
	p->left=NULL;
	p->right=NULL;
	return p;
}

void insertLeft(Node* &ptree,int x)
{
	if(ptree==NULL) return;
	if(ptree->left!=NULL) return;
	ptree->left=createNode(x);
}
void insertRight(Node* &ptree,int x)
{
	if(ptree==NULL) return;
	if(ptree->right!=NULL) return;
	ptree->right=createNode(x);
}
void insert(Node* &ptree,int x)
{
	if(ptree!=NULL) return;
	ptree=createNode(x);
}

Node* search(Node* ptree,int x)
{
	if(ptree==NULL) return NULL;
	if(ptree->info==x) return ptree;
	Node* p=search(ptree->left,x);
	if(p==NULL)
		p=search(ptree->right,x);
	return p;
}


void deleteLeft(Node* &ptree)
{
	if(ptree==NULL) return;
	if(ptree->left==NULL) return;
	Node* p=ptree->left;
	if(p->left==NULL && p->right==NULL)
	{
		ptree->left=NULL;
		delete p;
	}
}
void deleteRight(Node* &ptree)
{
	if(ptree==NULL) return;
	if(ptree->right==NULL) return;
	Node* p=ptree->right;
	if(p->left==NULL && p->right==NULL)
	{
		ptree->right=NULL;
		delete p;
	}
}

void xuatNLR(Node* ptree)
{
	if(ptree==NULL) return;
	
	printf("\n %d, Dia chi node: %d, L:%d, R:%d ",ptree->info,ptree,ptree->left, ptree->right);
	
	xuatNLR(ptree->left);
	xuatNLR(ptree->right);
}

void xuatLNR(Node* ptree)
{
	if(ptree==NULL) return;	
	xuatLNR(ptree->left);
	printf("%d ",ptree->info);	
	xuatLNR(ptree->right);
}
	
void xuatLRN(Node* ptree)
{
	if(ptree==NULL) return;	
	xuatLRN(ptree->left);	
	xuatLRN(ptree->right);
	printf("%d ",ptree->info);	
}

void xoa(Node* &ptree)
{
	if(ptree==NULL) return;
	xoa(ptree->left);
	xoa(ptree->right);
	delete ptree;
}
Node* searchNP(Node* ptree, int x)
{
	if(empty(ptree)) return NULL;
	if(ptree->info==x) return ptree;
	if(x<ptree->info) return searchNP(ptree->left,x);
	return searchNP(ptree->right,x);
}
void insertBST(Node* &ptree,int x)
{
	if(empty(ptree))
	{
		ptree=createNode(x);
		return;
	}
	if(ptree->info==x) return;
	if(x<ptree->info)
		insertBST(ptree->left,x);
	else
		insertBST(ptree->right,x);
}
void deleteBST(Node* &ptree,int x)
{
	if(empty(ptree)) return;
	if(x<ptree->info) 
	{ 
		deleteBST(ptree->left,x);
		return;
	}
	if(x>ptree->info) 
	{ 
		deleteBST(ptree->right,x);
		return;
	}
	//truong hop co mot cay con
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
		while(rp->left!=NULL)
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
	//node la node la hoac node doc lap co the xoa
	delete p;
}

void xoayTraiBST(Node* &ptree)
{
	if(empty(ptree)) return;
	if(empty(ptree->right)) return;
	Node *p = ptree->right;
	ptree->right=p->left;
	p->left=ptree;
	ptree=p;
}
void xoayPhaiBST(Node* &ptree)
{
	if(empty(ptree)) return;
	if(empty(ptree->left)) return;
	Node *p = ptree->left;
	ptree->left=p->right;
	p->right=ptree;
	ptree=p;
}



