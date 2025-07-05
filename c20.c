#include<stdio.h>
#include<math.h>
typedef long long ll;
ll mod( ll a ,ll n, ll k){
	ll b=1,A=a%n;
	if(k%2==1){
		b=A;
	}
	k=k/2;
	while(k>0){
		A=(A*A)%n;
		if(k%2==1){
			b=(b*A)%n;
		}
		k=k/2;
	}
	return b;
}
int main(){
	ll n,r,a;
	int j_max;
	printf("nhap n:\n");
	scanf("%lld",&n);
	printf("nhap r:\n");
	scanf("%lld",&r);
	while(r<1||r>n-1||r%2==0){
		printf("nhap lai r:\n");
	    scanf("%lld",&r);
	}
	printf("nhap a:\n");
	scanf("%lld",&a);
	while(a<2||a>n-2){
		printf("nhap lai a:\n");
	    scanf("%lld",&a);
	}
	printf("nhap j_max:\n");
	scanf("%d",&j_max);
	ll temp=n-1;
	ll s=0;
	while(temp%2==0){
		s++;
		temp=temp/2;
	}
	if(j_max>s-1){
		printf("Too many steps");
	}else{
		ll y=mod(a,n,r);
		for(int j=1;j<=j_max;j++){
			y=(y*y)%n;
			if(y==n-1){
				printf("%lld",y);
				return 0;
			}
			else if(y==1){
				printf("%lld",y);
				return 0;
			}
		}
		printf("%lld",y);
	}
	return 0;
    
}
