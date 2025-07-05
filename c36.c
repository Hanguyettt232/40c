#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isMatch(char p[],char q[]){
	int i=0,j=0;
	int n=strlen(p);
	int m=strlen(q);
	while(i<m){
		if(j<n&&p[j]==q[i]){
			i++;
			j++;
		}
		else{
			if(q[i]>='a'&&q[i]<='z'){
				i++;
			}
			else{
				return 0;
			}
		}
	}
	if(j!=n){
		return 0;
	}
	return 1;
}
int main(){
	int n;
	char q[1001][1001],p[1000];
	printf("nhap n:\n");
	scanf("%d",&n);
	getchar();
	printf("nhap cac dong :\n");
	for(int i=0;i<n;i++){
		fgets(q[i],1000,stdin);
	    q[i][strcspn(q[i],"\n")]='\0';
	}
	printf("nhap pattern:\n");
	fgets(p,1000,stdin);
	p[strcspn(p,"\n")]='\0';
	for(int i=0;i<n;i++){
		if(isMatch(p,q[i])){
			printf("true\n");
		}
		else{
			printf("false\n");
		}
	}
	return 0;
	
}
