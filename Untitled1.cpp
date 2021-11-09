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
		
		int chon;
		printf("\n Ban chon chuc nang nao (0-9)");
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
		/**/
	}while(1);
	return 0;
}
