#include<stdio.h>
#include<string.h>

int dem(char s[]){
	int count[256]={0};
	int n=strlen(s);
	int result=0;
	for(int i=0;i<n;i++){
		count[(int)s[i]]++;
	}
	for(int i=0;i<256;i++){
		if (count[i]>0){
			result+=count[i]+(count[i]*(count[i]-1)/2);
		}
	}
	return result;
}
int main(){
	char s[101];
	fgets(s,101,stdin);
	s[strcspn(s,"\n")]='\0';
	int result=dem(s);
	printf("%d",result);
	return 0;
}
