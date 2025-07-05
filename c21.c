#include<stdio.h>
#include<stdlib.h>
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
int Boyermoore(char t[],char p[],int lx[]){
	int m=strlen(p);
	int i=m-1,j=m-1;
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
			return 1;
		}
	}else{
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
	printf("nhap chuoi A:");
	fgets(a,1000,stdin);
	a[strcspn(a,"\n")]='\0';
	printf("nhap chuoi B:");
	fgets(b,1000,stdin);
	b[strcspn(b,"\n")]='\0';
	int lx[256],dem=1;
	taoLx(b,lx);
	strcpy(t,a);
	while(!Boyermoore(a,b,lx)||strlen(a)<strlen(b)){
		if(strlen(a)+strlen(b)>=1000){
			printf("-1");
			return 0;
		}
		char new_a[1000];
		saochepchuoi(new_a,a,t);
		strcpy(a,new_a);
		dem++;
	}
    printf("%d",dem);
	return 0;
	
}
