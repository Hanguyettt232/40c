#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isMatch(char b[],char p[]){
	int map1[256],map2[256];
	int i;
	for(int i=0;i<256;i++){
		map1[i]=-1;
		map2[i]=-1;
	}
	int len1=strlen(b);
	int len2=strlen(p);
	if(len1!=len2){
		return 0;
	}
	for(int i=0;i<len1;i++){
		char c1=p[i];
		char c2=b[i];
	    if(map1[(int)c1]==-1&&map2[(int)c2]==-1){
		    map1[(int)c1]=c2;
		    map2[(int)c2]=c1;
	    }
	    else{
		    if(map1[(int)c1]!=c2||map2[(int)c2]!=c1){
			return 0;
		}
    }
}
return 1;
}
int main(){
	int N;
	char b[100][100],p[100];
	int found=0;
	printf("nhap n:\n");
	scanf("%d",&N);
	printf("nhap cac dong :\n");
	getchar();
	for(int i=0;i<N;i++){
		fgets(b[i],1000,stdin);
		b[i][strcspn(b[i],"\n")]='\0';
	}
	printf("nhap chuoi so sanh:\n");
	fgets(p,1000,stdin);
	p[strcspn(p,"\n")]='\0';
	for(int i=0;i<N;i++){
		if(isMatch(b[i],p)){
			printf("%s ",b[i]);
			found=1;
		}
	}
	if(!found){
		printf("khong co hanh vi phu hop");
	}
   return 0;
}
