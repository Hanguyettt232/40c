#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

typedef long long ll;

ll mod(ll n,ll a,ll k){
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
int fermat(ll n,int t){
	if(n==3||n==2){
		return 1;
	}
	if(n<2||n%2==0){
		return 0;
	}
	srand(time(NULL));
	for(int i=1;i<t;i++){
		ll a=2+rand()%(n-3);
		ll r=mod(n,a,n-1);
		if(r!=1){
			return 0;
		}
	}
	return 1;
}
int main(){
	ll a,b;
	ll sum=0;
	int t=5;
	printf("nhap a:\n");
	scanf("%lld",&a);
	printf("nhap b:\n");
	scanf("%lld",&b);
	for(int i=a;i<=b;i++){
		if(fermat(i,t)){
			sum+=i;
		}
	}
	printf("%lld",sum);
	return 0;
}
