#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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
int Boyermoore(char t[],char p[],int lx[],int *index,int *res){
	int m=strlen(p);
	int i=*index+m-1,j=m-1;
	while(i<strlen(t)){
		if(t[i]==p[j]){
			int check=1;
		while(j>0){
			i--;
			j--;
			if(t[i]!=p[j]){
				check=0;
				break;
			}
		}
		if(check==1){
			*index=i+1;
			*res=i+1;
			return 1;
		}
	}else{
		i=i+m-min(j,1+lx[t[i]]);
		j=m-1;
	}
		
	}
	return 0;
}
int main(){
	char x[100],y[100];
	printf("nhap chuoi x:");
	fgets(x,100,stdin);
	x[strcspn(x,"\n")]='\0';
	printf("nhap chuoi y:");
	fgets(y,100,stdin);
	y[strcspn(y,"\n")]='\0';
	int lx[256];
	taoLx(y,lx);
	int index=0;
	int res;
	int found=0;
	while(Boyermoore(x,y,lx,&index,&res)&&index<strlen(x)){
		found=1;
	}
	if(found){
		printf("%d",res);
	}
	else{
		printf("-1");
	}
	return 0;
}
