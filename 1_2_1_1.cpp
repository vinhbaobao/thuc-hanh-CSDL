#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void nhapN(int &n){
	do{
		printf("Nhap n: "); scanf("%d",&n);
	}while (n<=0 || n>100);
}
void sinhMang(int a[], int n){
	srand(time(0));
	for(int i=0;i<n;i++)
		a[i]=rand()%10;
}
void xuatMang(int a[], int n){
	for(int i=0;i<n;i++)
		printf("%3d",a[i]);
}
int TinhTong(int a[],int n) {
	if(n==0) return 0;
	int tong=TinhTong(a,n-1);
	tong=tong+a[n-1];
	return tong;
}
float TinhTrungBinhCong(int a[],int n){
	  float tbc, tong=0;
    int dem=0;
    for(int i=0;i<n;i++){
        if(a[i]){
            tong=tong+a[i];
            dem++;
        }
    }
    if(dem==0)
        return 0;
    else
        {
            tbc=tong/dem;
            return tbc;
        }
}
int timTuyenTinh(int a[], int n,int x){   // tim vi tri cua x dau tien
	for(int i=0;i<n;i++)
		if(a[i]==x)
			return i;
	return -1; // tim khong thay
}
void sortMang(int a[], int n){
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j])   // doi cho
			{
				int tam=a[i];
				a[i]=a[j];
				a[j]=tam;
			}
}
int timNhiPhan(int a[], int n,int x){
	int l=0,r=n-1,m; // left   right 	mid
	while(l<=r){
		m=(l+r)/2; // lay diem giua
		if(a[m]==x)      return m;
		if(a[m]<x)   	l=m+1;
		else 			r=m-1;
	}
	return -1;
}
int main()
{
	int n,a[100];
	nhapN(n);
	sinhMang(a,n);
	printf("Mang vua co: ");
	xuatMang(a,n);

	sortMang(a,n);
	printf("\nMang sau khi sap xep: ");
	xuatMang(a,n);	
	int tong = TinhTong(a, n);
	printf("\nTong cac phan tu =%d\n",tong);
	scanf("%d",&n);
	float tbc = TinhTrungBinhCong(a, n);
	int x;
	printf("\nNhap gia tri can tim: "); scanf("%d",&x);
	int vt=timNhiPhan(a,n,x);
	if(vt==-1)    printf("\nKHONG TIM THAY!");
	else  printf("\nGIA TRI %d TAI VI TRI %d",x,vt);
}

