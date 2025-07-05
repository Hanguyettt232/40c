#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int X[20],Xet[20],lenP,k=0,res[1000];
char v[1000][20];
int v_size=0;
int min(int a,int b){
	return a<b?a:b;
}
void taoLx(char p[],int lx[])
{
	int m=strlen(p);
	for(int i=0;i<256;i++){
		lx[i]=-1;
	}
	for(int i=0;i<m;i++){
		lx[p[i]]=i;
	}
}
void Taohoanvi(char p[],char x[]){
	int m=strlen(p);
	for(int i=0;p[i]!='\0';i++){
		x[i]=p[X[i]];
	}
	x[m]='\0';
}
int Boyermoore(char p[],char t[],int lx[],int *index)
{
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
				res[k++]=i;
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
void Try(int i,char p[])
{
	for(int j=0;j<lenP;j++){
		if(!Xet[j]){
			Xet[j]=1;
			X[i]=j;
			if(i==lenP-1){
				char x[20];
				Taohoanvi(p,x);
				int unique=1;
				for(int u=0;u<v_size;u++){
					if(strcmp(v[u],x)==0){
						unique=0;
						break;
					}
				}
				if(unique){
					strcpy(v[v_size++],x);
				}
				}
				else{
					Try(i+1,p);
			}
				Xet[j]=0;
		}
	}
}
void SX(){
	for(int i=0;i<k-1;i++){
		for(int j=i+1;j<k;j++){
			if(res[i]>res[j]){
				int tmp=res[i];
				res[i]=res[j];
				res[j]=tmp;
			}
		}
	}
}
int main(){
	char s[1000],p[20];
	fgets(s,101,stdin);
	s[strcspn(s,"\n")]='\0';
	fgets(p,20,stdin);
	p[strcspn(p,"\n")]='\0';
	lenP=strlen(p);
	Try(0,p);
	for(int i=0;i<v_size;i++){
		int lx[256];
		int index=0;
		taoLx(v[i],lx);
		while(Boyermoore(v[i],s,lx,&index)){
			
		}
	}
	if(k==0){
		printf("-1");
	}
	else{
		SX();
		for(int i=0;i<k;i++){
			printf("%d ",res[i]);
		}
	}
	return 0;
	
}
