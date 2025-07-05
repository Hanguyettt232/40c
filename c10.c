#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef long long ll;

void nghicdao(ll a,ll b,ll res[]){
	ll p=b;
	ll q,r,x1,x2,x,y1,y2,y;
	x1=y2=0;
	x2=y1=1;
	while(b>0){
		q=a/b;
		r=a%b;
		x=x2-x1*q;
		y=y2-y1*q;
		x2=x1;
		x1=x;
		y2=y1;
		y1=y;
		a=b;
		b=r;
	}
	res[0]=a;
	res[1]=(x2+p)%p;
	res[2]=y2;
}
int main(){
	ll k,N=1,Ni,Mi,x=0;
	ll a[100],n[100];
	printf("nhap k:\n");
	scanf("%lld",&k);
	for(int i=0;i<k;i++){
		printf("nhap ptu a%d,n%d:\n",i,i);
		scanf("%lld %lld",&a[i],&n[i]);
	}
	for(int i=0;i<k;i++){
		N*=n[i];
	}
	for(int i=0;i<k;i++){
		Ni=N/n[i];
		ll res[3];
		nghicdao(Ni,n[i],res);
		Mi=res[1];
		x+=a[i]*Ni*Mi;
	}
	ll nghiem=x%N;
	if(nghiem<0){
		printf("%lld",nghiem+N);
	}
	else{
		printf("%lld",nghiem);
	}
	return 0;
}
