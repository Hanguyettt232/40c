#include<stdio.h>
#include<string.h>


int demMau(char s[]){
	int n=strlen(s);
	int count=0;
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			int j=i+1;
			int zero_count=0;
			while(j<n&&s[j]=='0'){
				zero_count++;
				j++;
			}
			if(zero_count>0&&j<n&&s[j]=='1'){
				count++;
				i=j-1;
			}
		}
	}
	return count;
}
int main(){
	char s[1000];
	int kq;
	fgets(s,1000,stdin);
	s[strcspn(s,"\n")]='\0';
	kq=demMau(s);
	printf("%d",kq);
}
