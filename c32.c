#include<stdio.h>
#include<string.h>

void laytiento(char t[],int k,char x[])
{
	for(int i=0;i<k;i++){
		x[i]=t[i];
	}
	x[k]='\0';
}
void layhauto(char p[],int k,char x[])
{
	int m=strlen(p);
	int j=0;
	for(int i=m-k;i<m;i++){
		x[j]=p[i];
		j++;
	}
	x[k]='\0';
}
int sosanh(char t[],char p[]){
	for(int i=0;t[i]!='\0';i++){
		if(t[i]!=p[i]){
			return 0;
		}
	}
	return 1;
}

int main(){
	char s[101];
	fgets(s,101,stdin);
	s[strcspn(s,"\n")]='\0';
	char tiento[100],hauto[100];
	int k=strlen(s)/2;
	laytiento(s,k,tiento);
	layhauto(s,k,hauto);
	while(!sosanh(tiento,hauto)){
		k--;
		laytiento(s,k,tiento);
	    layhauto(s,k,hauto);
	}
	printf("%d",k);
	return 0;
}
