#include <stdio.h>
struct SACH{
	int ma;
	char ten[40];
	float gia;
};
void nhapN(int &n){
	do{
		printf("Nhap n: "); scanf("%d",&n);
	}while(n<=0);
}
void nhap1Sach(SACH &x){
	printf("Ma (so nguyen): "); scanf("%d",&x.ma);
	printf("Ten: "); fflush(stdin); gets(x.ten);
	printf("Gia: ");  scanf("%f",&x.gia);
}
void nhapDSSach(SACH x[], int n){
	for(int i=0; i<n;i++)
	{
		printf("\tNHAP SACH THU %d:\n",i+1);
		nhap1Sach(x[i]);
	}
}
void xuat1Sach(SACH x){
	printf("\n   %-4d%-12s%10.0f",x.ma,x.ten,x.gia);
}
void xuatDSSach(SACH x[], int n){
	for(int i=0;i<n;i++)
		xuat1Sach(x[i]);
}

int main()
{
	int n=5;
	nhapN(n);
	SACH a[n],b[n];
	nhapDSSach(a,n);
	xuatDSSach(a,n);
}


