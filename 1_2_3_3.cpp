#include <stdio.h>

int UCLN(int a,int b){
	if(a==0)    return a;
	if (a > b)
	return UCLN(a-b, b);
	else
	return UCLN(a, b-a);
}
int main()
{
	int a,b;
	printf("Nhap a b : "); scanf("%d%d",&a,&b);
	printf("\nUCLN(%d,%d)= %d",a,b,UCLN(a,b));

}

