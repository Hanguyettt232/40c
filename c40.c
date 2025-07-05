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
int main(){
	int N;
	char w[100][100];
	printf("nhap n:\n");
	scanf("%d",&N);
	getchar();
	int lx[256];
	for(int i=0;i<N;i++){
		printf("nhap ptu %d:",i);
		fgets(w[i],1000,stdin);
		w[i][strcspn(w[i],"\n")]='\0';
	}
	int found=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i==j||strlen(w[j])>strlen(w[i])){
				continue;
			}
			taoLx(w[j],lx);
			if(Boyermoore(w[i],w[j],lx)){
				printf("%s ",w[j]);
				found=1;
				break;
			}
		}
	}
	if(!found){
		printf("none");
	}
	return 0;
}
