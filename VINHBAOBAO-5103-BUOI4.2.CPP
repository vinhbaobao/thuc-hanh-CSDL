#include<stdio.h>
#include<conio.h>
#define MAX 10
#define inputfile "C:/test05_2.txt"
typedef struct GRAPH
{
    int n;
    int a[MAX][MAX];
}DOTHI;
int ChuaXet[MAX];
typedef struct EDGE
{
	int u;
	int v;
	int value;
}CANH;
CANH T[MAX];
int DocMaTranKe(char Tenfile[100],DOTHI &g)
{
    FILE *f;
    f=fopen(Tenfile,"rt");
    if(f==NULL)
    {
        printf("Khong mo duoc file");
        return 0;
    }
    fscanf(f,"%d",&g.n);
    for(int i=0;i<g.n;i++)
    {
        for(int j=0;j<g.n;j++)
        {
            fscanf(f,"%d",&g.a[i][j]);
        }
    }
    fclose(f);
    return 1;
}
void XuatMaTranKe(DOTHI g)
{
    printf("So dinh cua do thi la %d\n",g.n);
    printf("Ma tran ke cua do thi la\n");
    for(int i=0;i<g.n;i++)
    {
        for(int j=0;j<g.n;j++)
        {
            printf("%d\t",g.a[i][j]);
        }
        printf("\n");
    }
}
void DiTimLT(DOTHI g,int nhan[MAX],int i)
{
	for(int j=0;j<g.n;j++)
	{
		if(g.a[i][j]!=0 && nhan[i]!=nhan[j])
		{
			nhan[j]=nhan[i];
			DiTimLT(g,nhan,j);
		}
	}
}
int XetLT(DOTHI g)
{
	int Nhan[MAX];
	for(int i=0;i<g.n;i++)
	{
		Nhan[i]=0;
	}
	int TPLT=0;
	for(int i=0;i<g.n;i++)
	{
		if(Nhan[i]==0)
		{
			TPLT++;
			Nhan[i]=TPLT;
			DiTimLT(g,Nhan,i);
		}
	}
	return TPLT;
}
void Prim(DOTHI g)
{
	if(XetLT(g)!=1)
	{
		printf("Do thi khong lien thong, do do khong thuc hien duoc thuat toan Prim tim cay khung nho nhat\n\n");
		return;	
	}
	int nT = 0;
	for(int i=0;i<g.n;i++)
	{
		ChuaXet[i] = 0;
	}
	ChuaXet[0]=1;
	while(nT < g.n)
	{
		CANH CanhNhoNhat;
		for (int i = 0; i < g.n; i++)
		{
			int GiaTriNhoNhat = 100;
			if(ChuaXet[i]==1)
			{
				for(int j = 0; j < g.n ; j++)
				{
					if(g.a[i][j] != 0 && ChuaXet[j] == 0 && GiaTriNhoNhat > g.a[i][j])
					{
								CanhNhoNhat.u=i;
								CanhNhoNhat.v=j;
								CanhNhoNhat.value = g.a[i][j];
								GiaTriNhoNhat = g.a[i][j];
					}
				}
			}
			T[nT] = CanhNhoNhat;
			nT++;
			ChuaXet[CanhNhoNhat.v] = 1;
		}
	}
	int TongTrongSoCuaCayKhung = 0;
	printf("cay khung nho nhat cua do thi la\n");
	for(int i=0 ;i < nT-2;i++)
	{
		printf("(%d,%d)",T[i].u,T[i].v );
		TongTrongSoCuaCayKhung += T[i].value;
	}
	printf("(%d,%d)\n",T[nT-1].u,T[nT-1].v );
	TongTrongSoCuaCayKhung += T[nT-1].value;
	printf("Tong gia tri cua cay khung la %d\n",TongTrongSoCuaCayKhung );
}
int main()
{
	DOTHI g;
	if(DocMaTranKe(inputfile,g)==1){
		XuatMaTranKe(g);
		Prim(g);
	}
	
}
