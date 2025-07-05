#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

#define MAX 1000
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
			b=(b*A)%n;
			k=k/2;
		}
	}
	return b;
}
ll milerRabin(ll n){
	if(n==2||n==3){
		return 1;
	}
	if(n<2||n%2==0){
		return 0;
	}
	int s=0;
	ll r=n-1;
	while(r%2==0&&r>0){
		s+=1;
		r=r/2;
    }
		for(int i=0;i<5;i++){
		ll a=2+rand()%(n-3);
		ll y=mod(n,a,r);
		if(y==1||y==n-1){
			return 1;
		}
		for(int j=1;j<s;j++){
			y=(y*y)%n;
			if(y==1){
				return 0;
			}
			if(y!=n-1){
				return 0;
			}
		}
	}
	return 1;
}

int main(){
	ll p,g,a,b,K1,K2,A,B;
	printf("nhap p:\n");
	scanf("%lld",&p);
	while(!milerRabin(p)){
		printf("vui long nhap lai p:\n");
		scanf("%lld",&p);
	}
	printf("nhap so g:\n");
	scanf("%lld",&g);
	printf("nhap so a:\n");
	scanf("%lld",&a);
	printf("nhap so b:\n");
	scanf("%lld",&b);
	A=mod(p,g,a);
	B=mod(p,g,b);
	K1=mod(p,A,b);
	K2=mod(p,B,a);
	if(K1==K2){
		ll K=K1=K2;
		printf("%lld",K);
	}
	else{
		printf("khong co khoa chung");
	}
	return 0;
}
