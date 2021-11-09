#include <stdio.h>
struct SP{
	char msp[5];
	char tensp[20];
	float gn;
	
};

void nhap1SP(SP &x){
	printf("Ma SP: ") ; scanf("%s",&x.msp);
	printf("Nhap tenSp: "); 	fflush(stdin); 		gets(x.tensp);
	printf("GN: ");  scanf("%f",&x.gn);
}
void nhapDSSP(SP x[], int n){
	for(int i=0;i<n;i++)
		nhap1SP(x[i]);
}
void xuat1SP(SP x){
	printf("\n   %-4d%-12s%10.0f",x.msp,x.tensp,x.gn);

}
void xuatDSSP(SP x[], int n){
	for(int i=0;i<n;i++)
		xuat1SP(x[i]);
}
void XuatDSSPGiam(SP x[], int n){
	for(int i=0;i<n;i++)
			if(x[i].gn == '\0')
		xuat1SP(x[i]);	
}
void sapxep(SP x[], int n){ 
 SP tmp;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
         if(x[i].gn < x[j].gn){
                tmp = x[i];
                x[i] = x[j];
                x[j] = tmp;
         }
  }
    }
    xuatDSSP(x,n);
}
void ghiFileNP(char *tenFile,SP x[], int n){
	FILE *f=fopen(tenFile,"wb");
	for(int i=0;i<n;i++)
		fwrite(&x[i],sizeof(SP),1,f);//nhi phan ( sizeo kich thuoc moi o nho tinh = byte )
	fclose(f);
}
int main()
{
	int n;
	SP x[100];
	printf("Nhap SLSP: "); scanf("%d",&n);
	nhapDSSP(x,n);
	xuatDSSP(x,n);
	printf("\n Gia san pham giam dan ");
	sapxep(x,n);
//	printf("\tim MSP:%d"timMSP(x,n,k));
	char tenFile[15] = "DSSP.TXT";
	ghiFileNP(tenFile,x,n);
}
