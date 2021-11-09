#include<stdio.h>
typedef struct node
{
	 int info; 
	 struct node *left; 
	 struct node *right; 
}node;
void init(node* &proot)
{
	proot=NULL;
}
int empty(node* proot){
	return proot==NULL;
}
node* Createnode(int x)
{
	node *p = new node;
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void Createnode(node* &proot, int a[], int begin, int end )
{
	if (begin>end) return;
	int i = (begin+end)/2;
	proot = Createnode(a[i]);
	Createnode(proot ->left, a, begin, i-1);
	Createnode(proot ->right, a, i+1, end);
}
void insert(node* &proot, int x){
	if(empty(proot))
		proot = Createnode(x);
	else
		if(x==proot->info)
			return;
		else
			if(x<proot->info)
			insert(proot->left,x);
		else
			insert(proot->right,x);		
}
void LNR(node* proot){
	if(proot!=NULL){
		LNR(proot->left);
		printf("%4d",proot->info);
		LNR(proot->right);
	}
}
/*int remove(node* &proot, int x) {
	if ( proot == NULL)
	return false;
	if (proot->info>x) //tìm và xóa bên trái	
		return remove(proot->left, x);
	if (proot->info<x) //tìm và xóa bên trái	
		return remove(proot->right, x);
	if(proot->info==x)
		node* p,f,rp;
		p=proot;
	if(proot->left==NULL)
		proot=proot->right;
	else
	if(proot->right==NULL)
		proot=proot->left;
	else{
		f=p;
		
	}


}*/
int main(){
	node* proot=NULL;
	init (proot);
	int x,i;
	int a[]={1,2,3,4,5,6,7,8,9,10};
	
	for(int i=0;i<10;i++){
	
		insert(proot,a[i]);
	}
	printf("\nDuyet cay theo thu tu giua LNR:\n");
	//cay sa khi insert
	LNR(proot);
	printf("\n");
	
//	remove(proot);
	
	//cay sau khi remove
//	LRN(proot);
	
	return 0;
}
