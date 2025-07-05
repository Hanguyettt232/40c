#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool isPrefix(char prefix[],char word[])
{
	int len=strlen(prefix);
	for(int i=0;i<len;i++){
		if(prefix[i]!=word[i]){
			return false;
		}
	}
	return true;
}
int main()
{
	int n;
	char s[100][1001];
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++){
		fgets(s[i],101,stdin);
	    s[i][strcspn(s[i],"\n")]='\0';
	}
	for(int i=0;i<n;i++){
		int len=strlen(s[i]);
		for(int j=1;j<=len;j++){
			char prefix[100];
			strncpy(prefix,s[i],j);
			prefix[j]='\0';
			bool unique=true;
		    for(int t=0;t<n;t++){
			    if(t!=i&&isPrefix(prefix,s[t])){
				   unique=false;
				   break;
			   } 
		    }
		    if(unique){
			   printf("%s ",prefix);
			   break;
		    }
		}
		
	}
	printf("\n");
	return 0;
}
