#include<stdio.h>
#include<string.h>


int isMatch(char s[],char p[]){
	int i=0,j=0;
	int temp=-1;
	int match=0;
	while(s[i]!='\0'){
		if(p[j]==s[i]||p[j]=='?'){
			i++;
			j++;
		}
		else if(p[j]=='*'){
			temp=j;
			match=i;
			j++;
		}
		else if(temp!=-1){
			j=temp+1;
			match++;
			i=match;
		}
		else{
			return 0;
		}
	}
	while(p[j]=='*'){
		j++;
	}
	return p[j]=='\0';
}
int main()
{
	char s[1000],p[1000];
	fgets(s,1000,stdin);
	s[strcspn(s,"\n")]='\0';
	fgets(p,1000,stdin);
	p[strcspn(p,"\n")]='\0';
	if(isMatch(s,p)){
		printf("true");
	}
	else{
		printf("false");
	}
	return 0;
}
