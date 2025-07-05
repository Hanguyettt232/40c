#include<stdio.h>
#include<string.h>



int min(int a,int b){
	return b<a?a:b;
}
void taoLx(char p[],int lx[]){
	int m=strlen(p);
	for(int i=0;i<256;i++){
		lx[i]=-1;
	}
	for(int i=0;i<m;i++){
		lx[(int)p[i]]=i;
	}
}
int Boyermoore(char p[],char t[],int lx[]){
	int m=strlen(p);
	int check;
	int i=m-1,j=m-1;
	while(i<strlen(t)){
		if(t[i]==p[j]){
			check=1;
		    while(j>0){
			i--;
			j--;
			if(t[i]!=p[j]){
				check=0;
				break;
			}
		}
		if(check==1){
			return 1;
		}
	}
	i=i+m-min(j,1+lx[t[i]]);
	j=m-1;
    }
    return 0;
}
void dichvong(char s[]){
	int n=strlen(s);
	char first=s[0];
	for(int i=0;i<n;i++){
		s[i]=s[i+1];
	}
	s[n-1]=first;
	s[n]='\0';
}
int main(){
	char s[1000],goal[1000];
	printf("nhap s:");
	fgets(s,1000,stdin);
	s[strcspn(s,"\n")]='\0';
	printf("nhap goal:");
	fgets(goal,1000,stdin);
	int found=0;
	int n=strlen(s);
	goal[strcspn(goal,"\n")]='\0';
	int lx[256];
	for(int i=0;i<n;i++){
		taoLx(s,lx);
		if(Boyermoore(s,goal,lx)){
			found=1;
			break;
		}
		dichvong(s);
	}
	if(found){
		printf("true");
	}
	else{
		printf("false");
	}
	return 0;
}
