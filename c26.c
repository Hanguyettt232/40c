#include<stdio.h>
#include<string.h>

int isPrefix(char s1[],char s2[],int k){
	for(int i=0;i<k;i++){
		if(s1[i]!=s2[i]){
			return 0;
		}
		if(s1[i]=='\0'||s2[i]=='\0'){
			return 0;
		}
	}
	return 1;
}
int main(){
	int k,n;
	char s1[100][100],s2[100];
	printf("nhap k:\n");
	scanf("%d",&k);
	printf("nhap n:\n");
	scanf("%d",&n);
	getchar();
	printf("nhap cac dong:\n");
	for(int i=0;i<n;i++){
		printf("nhap chuoi %d:",i);
		fgets(s1[i],1000,stdin);
		s1[i][strcspn(s1[i],"\n")]='\0';
	}
	printf("nhap chuoi mau:");
	fgets(s2,1000,stdin);
	s2[strcspn(s2,"\n")]='\0';
	int dem=0;
	for(int i=0;i<n;i++){
		if(isPrefix(s1[i],s2,k)){
		dem++;
	}
	}
	printf("%d",dem);
	return 0;
}
