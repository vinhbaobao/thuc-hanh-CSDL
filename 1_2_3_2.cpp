#include <stdio.h>
int Fibonacci(int n){
	if(n==0 || n==1)  return 1;
	return (Fibonacci(n-1)+Fibonacci(n-2));
}
int main()
{
	int n;
	printf("Nhap n: "); scanf("%d",&n);
	printf("\nFibonacci thu %d la: %d",n,Fibonacci(n));
	printf("\nDay so Fibonacci tu vi tri 1 den vi tri %d: \n",n);
	for(int i=1;i<=n;i++)
		printf("%4d",Fibonacci(i));

}

