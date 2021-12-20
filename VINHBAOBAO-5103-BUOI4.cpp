#include<stdio.h>
#include<conio.h>
#define MAX 100
#define inputfile "D:\\TEXT4_1.txt"

typedef struct{
    int n;
    int a[MAX][MAX];
}DOTHI;

typedef struct{
    int size;
    int a[MAX];
}Queue;
int ChuaXet[MAX];
int LuuVet[MAX];
int NhapDoThiTuFile(DOTHI &g,char input[MAX])
{
    FILE *f;
    f=fopen(input,"rt");
    if(f==NULL)
    {
        printf("Khong mo duoc file!");
        return 0;
    }
    fscanf(f,"%d",&g.n);
    int i,j;
    for(i=0;i<g.n;i++)
    {
        for(j=0;j<g.n;j++)
        {
            fscanf(f,"%d",&g.a[i][j]);
        }
    }
    return 1;
}
void DFS(DOTHI g,int v)
{
    ChuaXet[v]=1;
    int u;
    for(u=0;u<g.n;u++)
    {
        if(g.a[v][u]!=0&&ChuaXet[u]==0)
        {
            LuuVet[u]=v;
            DFS(g,u);
        }
    }
}
int DuyetDFS(DOTHI g,int s,int f)
{
    int i;
    for(i=0;i<MAX;i++)
    {
        ChuaXet[i]=0;
        LuuVet[i]=-1;
    }
    DFS(g,s);
    if(ChuaXet[f]==1)
    {
        printf("\nDuong di cua DFS la:");
        printf("%d",f);
        int i=f;
        while(i!=s)
        {
            printf("<-%d",LuuVet[i]);
            i=LuuVet[i];
        }
    }
    else
    {
        printf("\nKhong co duong di DFS!!!");
    }
    
}
void XuatMaTran(DOTHI g)
{
    int i,j;
    printf("\nMa Tran:\n");
       for(i=0;i<g.n;i++)
    {
        for(j=0;j<g.n;j++)
        {
            printf("%2d",g.a[i][j]);
        }
        printf("\n");
    }
}
//BFS
void KhoiTaoQueue(Queue &Q)
{
    Q.size=0;
}
int DayGiaTriVaoQueue(Queue &Q,int x)
{
    if(Q.size+1>MAX)
    {
        return 0;
    }
    Q.a[Q.size]=x;
    Q.size++;
    return 1;
}
int KiemTraRong(Queue Q)
{
    if(Q.size<=0)
    {
        return 1;
    }
    return 0;
}
int LayGiaTriKhoiQueue(Queue &Q, int &x)
{
    if(KiemTraRong(Q)==1)
    {
        return 0;
    }
    x=Q.a[0];
    int i;
    for(i=0;i<Q.size;i++)
    {
        Q.a[i]=Q.a[i+1];
    }
    Q.size--;
    return 1;
}

void ThemGiaTri(Queue &Q)
{
    int i;
    for(i=0;i<10;i++)
    {
        DayGiaTriVaoQueue(Q,i);
    }
    while(KiemTraRong(Q)!=1)
    {
        int x;
        LayGiaTriKhoiQueue(Q,x);
        printf("%2d",x);
    }
}
void BFS(int v,DOTHI g)
{
    Queue Q;
    KhoiTaoQueue(Q);
    DayGiaTriVaoQueue(Q,v);
    while(KiemTraRong(Q)!=1)
    {
        LayGiaTriKhoiQueue(Q,v);
        ChuaXet[v]=1;
        int u;
        for(u=0;u<g.n;u++)
        {
            if(g.a[v][u]!=0&&ChuaXet[u]==0)
            {
                DayGiaTriVaoQueue(Q,u);
                if(LuuVet[u]==-1)
                	LuuVet[u]=v;
            }
        }
    }
}
void DuyetBFS(DOTHI g,int s,int f)
{
    int i;
    for(i=0;i<g.n;i++)
    {
        ChuaXet[i]=0;
        LuuVet[i]=-1;
    }
    BFS(s,g);
    if(ChuaXet[f]==1)
    {
        printf("\nCo duong di BFS la:\n");
        printf("%d",f);
        i=f;
        while(i!=s)
        {
            printf("<-%d",LuuVet[i]);
            i=LuuVet[i];
        }
    }
    else
    {
        printf("\nKhong co duong di BFS!!!");
    }
    
}
int main()
{
    DOTHI g;
    if(NhapDoThiTuFile(g,inputfile)==1)
    {
        printf("\nNhap do thi thanh cong tu file!!");
        XuatMaTran(g);
        DuyetDFS(g,2,4);
        DuyetBFS(g,2,4);
    }
 
    return 1;
}

