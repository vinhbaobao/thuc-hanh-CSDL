#include <stdio.h>
#include<iostream>
using namespace std;
struct node
{
	 int data; 
	 struct node *left; 
	 struct node *right; 
};
typedef struct node Node;


void init(Node* &proot)
{
	proot = NULL;
}

Node *CreateNode(int x)
{
	Node *p = new Node;
	p->data = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void CreateTree(Node* &proot, int a[], int begin, int end )
{
	if (begin>end) return;
	int i = (begin+end)/2;
	proot = CreateNode(a[i]);
	CreateTree(proot ->left, a, begin, i-1);
	CreateTree(proot ->right, a, i+1, end);
}

void NLR(Node * proot){
	if (proot!=NULL)
	{
		proot ->data;
		printf("%d",proot->data);
		NLR(proot->left);
		NLR(proot->right);
	}
}


void LNR(Node * proot)
{
	if (proot!= NULL)
	{
		LNR(proot->left); 
		printf("%d",proot->data);
		LNR(proot->right); 
	}
}


void RNL(Node * proot)
{
	
	if (proot != NULL)
	{
		RNL(proot->right); 
		printf("%d",proot->data);
		RNL(proot->left); 
	}
}

int DEMLA(Node* proot){  
	 if(proot!=NULL) 
	return 0;
    else
       if(proot->left==NULL && proot->right==NULL) return 1;
       else 
	   	return DEMLA(proot->left)+DEMLA(proot->right);
}
int main ()
{
	
	Node *proot=NULL;
	
	int a[] ={1,2,3,4,5,6,7,8,9,10};
    CreateTree(proot, a, 0,9 );
	
	NLR(proot);
	LNR(proot);
	return 0;
}

