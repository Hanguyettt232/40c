#include<stdio.h>
#include<string.h>

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
		lx[(int)p[i]]=i;
	}
}
void Boyermoore(char t[],char p[],int bold[]){
	int n=strlen(t),m=strlen(p);
	int i=0;
	int lx[256];
	taoLx(p,lx);
	while(i<=n-m){
		int j=m-1;
		while(j>=0&&t[i+j]==p[j]){
			j--;
	 }
	 if(j<0){
	 	for(int k=i;k<i+m;k++){
	 		bold[k]=1;
		 }
		 i+=m;
	 }else{
	 	i=i+m-min(j,1+lx[t[i]]);
	 }
	}
}
int main()
{
	char s[101];
	int n;
	fgets(s,101,stdin);
	s[strcspn(s,"\n")]='\0';
	scanf("%d",&n);
	getchar();
	char word[10][101];
	for(int i=0;i<n;i++){
		fgets(word[i],101,stdin);
	    word[i][strcspn(word[i],"\n")]='\0';
	}
	int len=strlen(s);
	int bold[len];
	for(int i=0;i<len;i++){
		bold[i]=0;
	}
	for(int i=0;i<n;i++){
		Boyermoore(s,word[i],bold);
	}
	for(int i=0;i<len;i++){
		if(bold[i]&&(i==0||!bold[i-1])){
			printf("<b>");
		}
		printf("%c",s[i]);
		if(bold[i]&&(i==len-1||!bold[i+1])){
			printf("</b>");
		}
	}
	printf("\n");
	return 0;
}
