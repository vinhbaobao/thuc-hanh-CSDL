#include <stdio.h>

#define MAX 100

struct Graph{
	int a[MAX][MAX];
	int c[MAX][MAX];
	int n;
};
void nhapG(Graph &g);
void xuatG(Graph g);

int main()
{
	Graph g;
	nhapG(g);
	xuatG(g);

	return 0;
}
void nhapG(Graph &g)
{
	freopen("graph.txt","r",stdin);
	scanf("%d",&g.n);
	for(int i=1;i<=g.n;i++)
		for(int j=1;j<=g.n;j++)
			scanf("%d",&g.a[i][j]);
	for(int i=1;i<=g.n;i++)
		for(int j=1;j<=g.n;j++)
			scanf("%d",&g.c[i][j]);	
}
void xuatG(Graph g)
{
	//freopen("graph2.txt","w",stdout);
	printf("%d\n",g.n);	
	for(int i=1;i<=g.n;i++)
	{
		for(int j=1;j<=g.n;j++)
			printf("%d ",g.a[i][j]);
		printf("\n");
	}
	
	for(int i=1;i<=g.n;i++)
	{
		for(int j=1;j<=g.n;j++)
			printf("%d ",g.c[i][j]);
		printf("\n");
	}
}


