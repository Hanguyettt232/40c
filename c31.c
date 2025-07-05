#include<stdio.h>
#include<string.h>

int taoLps(char s[],int lps[]){
	int len=0;
	lps[0]=0;
	int i=1;
	while(s[i]!='\0'){
		if(s[i]==s[len]){
			len++;
			lps[i]=len;
			i++;
		}
		else{
			if(len!=0){
				len=lps[len-1];
			}
			else{
				lps[i]=0;
				i++;
			}
		}
	}
	return i;
}
int main(){
	char s[101];
	fgets(s,101,stdin);
	s[strcspn(s,"\n")]='\0';
	int lps[256];
	int len_of_string=taoLps(s,lps);
	int prefix=lps[len_of_string-1];
	if(prefix>0&&len_of_string%(len_of_string-prefix)==0){
		printf("YES\n");
	}
	else{
		printf("NO");
	}
	return 0;
}
