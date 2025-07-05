#include<stdio.h>
#include<string.h>

int nguyenam(char c){
	if(c=='u'||c=='e'||c=='o'||c=='a'||c=='i');
	return 1;
}
int main(){
	int na,pa;
	char s[1000];
	char c;
	fgets(s,1000,stdin);
	s[strcspn(s,"\n")]='\0';
	for(int i=0;i<strlen(s);i++){
		c=s[i];
		if(c=='?'){
			na++;
			pa++;
		}
		else if(nguyenam(c)){
			na++;
			pa=0;
		}
		else{
			na=0;
			pa++;
		}
	}
	if(pa>3||na>5){
		printf("BAD");
	}
	else{
		printf("GOOD");
	}
	return 0;
}
