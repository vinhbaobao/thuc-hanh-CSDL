#include <stdio.h>
#include <conio.h>
#define VOCUC 1000
#define MAX 30
#define inputfile "C:\\VBB.txt"


int luuVet[MAX];
int chuaXet[MAX];
int doDaiDuongDi[MAX];

struct GRAPH {
	int n;
	int a[MAX][MAX];
};

int DocMaTranKe(char TenFile[100], GRAPH &g) {
	FILE* f;
	f = fopen(TenFile,"rt");
	if (f == NULL) {
		printf("khong mo duoc file\n");
		return 0;
	}
	fscanf(f,"%d",&g.n);
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			fscanf(f,"%d",&g.a[i][j]);
		}
	}
	fclose(f);
	return 1;	
}

void XuatMaTranKe(GRAPH g) {
	printf("So dinh cua do thi: %d\n",g.n);
	printf("Ma tran ke cua do thi la:\n");
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			printf("%5d",g.a[i][j]);
		}
		printf("\n");
	}
}

int timDuongNganNhat(GRAPH g) {
	int li = -1;
	float p = VOCUC;
	for (int i = 0; i < g.n; i++) {
		if (chuaXet[i] == 0 && doDaiDuongDi[i] < p) {
			p = doDaiDuongDi[i];
			li = i;
		}
	}
	return li;
}

void capNhatDuongDi(int u, GRAPH g) {
	chuaXet[u] = 1;
	for (int v = 0; v < g.n; v++) {
		if (chuaXet[v] == 0 && g.a[u][v] > 0 && g.a[u][v] < VOCUC) {
			if (doDaiDuongDi[v] > doDaiDuongDi[u] + g.a[u][v]) {
				doDaiDuongDi[v] = doDaiDuongDi[u] + g.a[u][v];
				luuVet[v] = u;
			}
		}
	}
}

void dijkstra(int s, int f, GRAPH g) {
	int i;
	for (i = 0; i < g.n; i++) {
		chuaXet[i] = 0;
		doDaiDuongDi[i] = VOCUC;
		luuVet[i] = -1;
	}
	doDaiDuongDi[s] = 0;
	while (chuaXet[f] == 0) {
		int u = timDuongNganNhat(g);
		if (u == -1)
			break;
		capNhatDuongDi(u,g);
		
	}
	if (chuaXet[f] == 1) {
		printf("Duong di ngan nhat tu dinh %d den dinh %d la: \n\t",s,f);
		i = f;
		printf("%d",f);
		while (luuVet[i] != s) {
			printf("<- %d",luuVet[i]);
			i = luuVet[i];
		}
		printf("<-%d\n",luuVet[i]);
		printf("\tVoi do dai la %d \n",doDaiDuongDi[f]);
	}
	else {
		printf("Khong co duong di tu dinh %d den dinh %d !!!!\n",s,f);
	}
}


int main() {
	GRAPH g;
	int s,f;
	if (DocMaTranKe(inputfile,g) == 1) {
		printf("\nDa doc file thanh cong\n");	
		XuatMaTranKe(g);
		printf("Nhan Enter de tiep tuc !!!!");
		getch();
		printf("\nNhap dinh bat dau: "); scanf("%d",&s);
		printf("\nNhap dinh ket thuc: "); scanf("%d",&f);
		dijkstra(s,f,g);
	}
	return 0;
}
