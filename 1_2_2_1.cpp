#include <stdio.h>
struct SACH{
	int ma;
	char ten[10];
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
int timTuanTu(Sach a[], int n, int X){

int timNhiPhan(Sach a[], int n, int X){
	int l=0, r=n-1, mid;
	while(l<=r){
		m=(l+r)/2;
		if(a[mid]==x)		return mid;
		else
			if(a[]>x)		r=m-1;
			else			l=m+1;
	}
	return -1;
}
int main()
{
	int n=5;
	nhapN(n);
	SACH a[n],b[n];
	nhapDSSach(a,n);
	xuatDSSach(a,n);
	xuatDSSach(b,n);
	int x;
	printf("\nNhap gia tri can tim: "); scanf("%d",&x);
	int vt=timNhiPhan(a,n,x);
	if(vt==-1)    printf("\nKHONG TIM THAY!");
	else  printf("\nGIA TRI %d TAI VI TRI %d",x,vt);	
}

