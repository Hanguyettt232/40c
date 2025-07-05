#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int begin,end;
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
int Boyermoore(char p[],char t[],int lx[],int *index)
{
	int m=strlen(p);
	if(strlen(t)<strlen(p)){
		return 0;
	}
	int i=*index+m-1,j=m-1;
	while(i<strlen(t)){
		if(t[i]==p[j]){
			int check=1;
			while(j>=1){
				i--;
				j--;
				if(t[i]!=p[j]){
					check=0;
					break;
				}
			}
			if(check==1){
				begin=i;
				end=i+m-1;
				*index=end+1;
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
void in( char s[],int kt[])
{
	for(int i=0;s[i]!='\0';i++)
	{
		if(kt[i]==0){
			printf("%c",s[i]);
		}
	}
}
int main(){
	char s[100],t[100];
	fgets(s,100,stdin);
	s[strcspn(s,"\n")]='\0';
	fgets(t,100,stdin);
	t[strcspn(t,"\n")]='\0';
	int lx[256];
	taoLx(t,lx);
	int index=0;
	int kt[100]={0};
	while(Boyermoore(t,s,lx,&index)){
		for(int i=begin;i<=end;i++){
			kt[i]=1;
		}
	}
	in(s,kt);
	return 0;
}
