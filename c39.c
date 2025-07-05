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
		lx[p[i]]=i;
	}
}
int Boyermoore(char p[],char t[],int lx[])
{
	int m=strlen(p);
	int i=m-1,j=m-1;
	while(i<strlen(t)){
		if(t[i]==p[j]){
			if(j==0){
				return i;
			}
			i--;
			j--;
		}
		else{
			i=i+m-min(j,1+lx[t[i]]);
			j=m-1;
		}
	}
	return -1;
}
int main()
{
	char s[1001],w[1001];
	fgets(s,1001,stdin);
	s[strcspn(s,"\n")]='\0';
	fgets(w,1001,stdin);
	w[strcspn(w,"\n")]='\0';
	char *t=strtok(s," ");
	int index=1;
	int lx[256];
	taoLx(w,lx);
	int found=0;
	while(t!=NULL){
		int kq=Boyermoore(w,t,lx);
		if(kq==0){//pattern nam vtri dau
			printf("%d",index);
			found=1;
			break;
		}
		index++;
		t=strtok(NULL," ");
	}
	if(!found){
		printf("-1");
	}
	
	return 0;
}
