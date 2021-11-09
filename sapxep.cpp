#include <stdio.h>
#define MAX 100

void NhapSL (int &n){
	do{
		printf("Nhap so phan tu 0<sl<%d:", MAX);
		scanf("%d", &n);
	}while (n<=0||n>MAX);
}

void nhapMang (int a[], int n){
	for (int i=0;i<n;i++)
	{
		printf("a[%d]=",i);
		scanf("%d", &a[i]);
	}
}
void xuatMang (int a[], int n){
	for(int i=0;i<n;i++)
		printf("%5d", a[i]);
}
void bubleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++){
		for (int j = n - 1; j > i; j--)
		   if(a[j] < a[j-1]){
            	int t = a[i];
				a[i]=a[j];
				a[j]= t;
			}
        }
    printf("\nMang da sap xep bubleSort: ");
	xuatMang(a,n);
    }


void insertSort(int a[], int n){
	int pos, x;
	for(int i = 1; i < n; i++){ 
		x = a[i]; 
		pos = i;
		while(pos > 0 && x < a[pos-1]){
			a[pos] = a[pos-1];	
			pos--;
		}
		a[pos] = x;
	}
	printf("\nMang da sap xep insertSort: ");
	xuatMang(a,n);
}

void interChangeSort(int a[], int n){
	
	for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++)
	        if(a[i] > a[j]){
				int t = a[i];
				a[i]=a[j];
				a[j]= t;
			}
	}
	printf("\nMang da sap xep interChangeSort: ");
	xuatMang(a,n);
}
  
void selectionsort(int a[], int n)
{
 for (int i = 0; i < n - 1; i++)
 {
  int min = i;
  for (int j = i + 1; j < n; j++)
  { 
   if (a[min] > a[j])
       min = j;
		{
				int t = a[i];
				a[i]=a[min];
				a[min]= t;
			}
  }
} 	printf("\nMang da sap xep selectionsort: ");
	xuatMang(a,n);
}
int main(){
 	int a[MAX],n,x;
 	NhapSL(n);
 	nhapMang(a,n);
 	printf("\n Mang da nhap:");
 	xuatMang(a,n);
 	bubleSort(a,n);
 	insertSort(a,n);
 	interChangeSort(a,n);
 	selectionsort(a,n);
}
