#include<stdio.h>
int tong(int n)
{
	if(n==0)
		return 0;
		return tong(n-1) + n;
}
int main()
{  
	int n;
    printf("nhap n: ");
    scanf("%d", &n);
    printf("tong thu %d la:",tong(n));
}
