#include<stdio.h>
#include<string.h>
int min(int a,int b){
	return a<b?a:b;
}
void taoLx(char p[],int lx[]){
	int m=strlen(p);
	for(int i=0;i<256;i++){
		lx[i]=-1;
	}
	for(int i=0;i<m;i++){
		lx[(int)p[i]]=i;
	}
}
int Boyermoore(char p[],char t[],int lx[]){
	int m=strlen(p);
	int check;
	int i=m-1,j=m-1;
	while(i<strlen(t)){
		if(p[j]==t[i]){
			check=1;
			while(j>0){
				j--;
				i--;
				if(t[i]!=p[j]){
					check=0;
					break;
				}
			}
			if(check==1){
				return 1;
			}
		}
		else{
			i=i+m-min(j,1+lx[t[i]]);
			j=m-1;
		}
	}
	return 0;
}
void saochepchuoi(char s[],char a[],char t[]){
	int i=0;
	for(int j=0;a[j]!='\0';j++){
		s[i]=a[j];
		i++;
	}
	for(int j=0;t[j]!='\0';j++){
		s[i]=t[j];
		i++;
	}
	s[i]='\0';
}
int main(){
	char a[1000],b[1000],t[1000];
	printf("nhap chuoi ky tu:");
	fgets(a,1000,stdin);
	a[strcspn(a,"\n")]='\0';
	printf("nhap tu:");
	fgets(b,1000,stdin);
	b[strcspn(b,"\n")]='\0';
	strcpy(t,b);
	int dem=0;
	int lx[256];
	taoLx(b,lx);
	while(Boyermoore(b,a,lx)){
		char new_b[100];
		saochepchuoi(new_b,b,t);
		strcpy(b,new_b);
		taoLx(b,lx);
		dem++;
	}
	if(dem==0){
        printf("0");
	}
	else{
		printf("%d",dem);
	}
	
	return 0;
}
