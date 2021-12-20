#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100 //dinh nghia gia tri MAX cua a
#define inputfile1 "text.txt"
#define inputfile2 "text2.txt"
#define inputfile3 "text3.txt"
struct STACK{
	int array[100];
	int size;
};
typedef struct GRAPH{
	int n; // so dinh cua do thi
	int a[MAX][MAX]; // ma tran ke cua do thi
}DOTHI;
int DocMaTranKe(char TenFile[100],DOTHI &g){
	FILE* f; // mot bien file
	f=fopen(TenFile,"rt");//mo 1 file co duong dan luu o bien ten file
	if(f==NULL)// neu file mo dc thi bien f!=null va file k mo dc thi bien f=null
	{
		printf("khong mo duoc file\n");
		return 0;//k doc dc file tra ve kqua 0
	}
	//doc gia tri dinh cua do thi vao bien n cua cau truc dothi g
	fscanf(f,"%d",&g.n);
	//doc gia tri cua ma tran a tu file va dung 2 vong for, dong truoc cot sau de doc tung phan tu cua ma tran
	//voi a [i] [j] la gia tri ma tran i la dong j la cot
	int i,j;
	for(int i=0;i<g.n;i++){
		for(int j=0;j<g.n;j++){
			fscanf(f,"%d",&g.a[i][j]);//doc tung gia tri va gan vao mtran ke cua a
		}
	}
	//dong file da mo o tren
	fclose(f);
	return 1; //tra ve kqua 1 cho biet da doc file va su ly nhap thong tin do thi xong	
}
void XMaTranKe(DOTHI g){
	printf("So dinh cua do thi la %d\n",g.n);
	printf("Ma tran ke cua do thi la \n");
	for(int i=0;i<g.n;i++){
		printf("\t");
		for(int j=0;j<g.n;j++){
			printf("%d  ",g.a[i][j]);
		}
		printf("\n");
	}
}
void khoitaoStack(STACK &stack){
	stack.size=0;
}
void DayGiaTriVaoStack(STACK &stack,int value){
	if(stack.size+1>=100)
		return;
	stack.array[stack.size]=value;
	stack.size++;
}
int KiemTraDinhBacLe(DOTHI g){
	int c = 0;
	int count =0;
	for(int i =0; i<g.n; i++)
	{
		for(int j=0; j<g.n; j++){
			if(g.a[i][j] != 0)
				c++;
		}
	if(c%2!=0){
		count++;
	}
		c = 0;
	}
	if(count == 2)
		return 1;
	else if (count == 0)
		return 0;
	else 
		return -1;
}
void TimDuongDi(int i, DOTHI &g, STACK &stack){
	for(int j=0;j<g.n;j++){
		if(g.a[i][j]!=0){
			g.a[i][j]=g.a[j][i]=0;
			TimDuongDi(j,g,stack);
		}
	}
	DayGiaTriVaoStack(stack,i);
}
void KiemTraChuTrinhEuler(DOTHI g){
	int i,j;
	int x=0;
	DOTHI temp=g;
	STACK stack;
	khoitaoStack(stack);
	TimDuongDi(x,temp,stack);
		for(int i =0; i<temp.n; i++)
	{
		for(int j=0; j<temp.n; j++){
			if(temp.a[i][j] != 0)
			{
				printf("\nKhong co CT euler");	
				return;
			}
		}
	}
	for(int i =0; i<stack.size; i++)
	{
		if(stack.array[0] != stack.array[stack.size-1])
		{
			printf("\nKhong co CT euler");
			return;
		}
		
	}
	printf("\nChu Trinh Euler:");
	for(int i =stack.size-1; i>=0; i--)
	{
			printf(" %d ", stack.array[i]);
	}
}
int main()
{
	DOTHI g;
	if (DocMaTranKe("C:/test.txt", g) == 1){
		printf("Da lay thong tin do thi tu file thanh cong.\n\n");
		XMaTranKe(g);
	
	if(KiemTraDinhBacLe(g) == 0)
	{
		KiemTraChuTrinhEuler(g);
}
	else 
		printf("\nDo thi khong co chu trinh euler hay duong di euler");
	return 0;	
}
}
