#include<stdio.h>
#include<string.h>
int min(int a,int b){
	return a<b?a:b;
}
void taoLx( char p[],int lx[]){
	int m=strlen(p);
	for(int i=0;i<256;i++){
		lx[i]=-1;
	}
	for(int i=0;i<m;i++){
		lx[(int)p[i]]=i;
	}
}
int Boyermoore(char p[],char t[],int lx[],int *index){
	int m=strlen(p);
	int i=*index+m-1,j=m-1;
	while(i<strlen(t)){
		if(t[i]==p[j]){
			int check=1;
		while(j>0){
			i--;
			j--;
			if(t[i]!=p[j]){
				check=0;
				break;
			}
		}
		if(check==1){
			*index=i+1;
		    printf("%d ",i+1);
		    return 1;
		}
    }
		else{
			i=i+m-min(j,1+lx[t[i]]);
			j=m-1;
		}
		
	}
	return 0;
}
int main(){
	char a[1000],mau[1000];
	printf("nhap chuoi a:");
	fgets(a,1000,stdin);
	a[strcspn(a,"\n")]='\0';
	printf("nhap chuoi mau:");
	fgets(mau,1000,stdin);
	mau[strcspn(mau,"\n")]='\0';
	int lx[256];
	taoLx(mau,lx);
	int index=0;
	int found;
	while(index<=strlen(a)-strlen(mau)){
		if(!Boyermoore(mau,a,lx,&index)){
			break;
		}
		else{
			found=1;
		}
	}
	if(!found){
		printf("-1");
	}
	return 0;
}
