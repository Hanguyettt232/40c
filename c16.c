#include<stdio.h>
#include<stdlib.h>

typedef long long ll;

ll mod(ll n, ll a, ll k){
	ll b=1,A=a%n;
	if(k%2==1){
		b=A;
	}
	k=k/2;
	while(k>0){
		A=(A*A)%n;
		if(k%2==1){
			b=(A*b)%n;
		}
		k=k/2;
	}
	return b;
}
 int fermat(ll n,int t,ll a[]){
 	if(n==2||n==3){
 		return 1;
	 }
	if(n<2||n%2==0){
		return 0;
	}
	for(int i=1;i<t;i++){
		ll r =mod(n,a[i],n-1);
		if(r!=1){
		return 0;
	}
	}
	return 1;
 }
 int main(){
 	ll n,t;
 	printf("nhap n:\n");
 	scanf("%lld",&n);
 	printf("nhap t:\n");
 	scanf("%lld",&t);
 	ll a[t];
 	for(int i=1;i<=t;i++){
 		printf("nhap a:\n");
 		scanf("%lld",&a[i]);
	 }
	if(!fermat(n,t,a)){
		printf("%lld",t);
	}
	else{
		printf("-1");
	}
 	return 0;
 }
