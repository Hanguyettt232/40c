#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef long long ll;
ll thuaso[1000]={0};
int index=0;

ll mod(ll n,ll a,ll k){
	ll b=1;ll A=a%n;
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
ll milerRabin(ll n){
	if(n==2||n==3){
		return 1;
	}
	if(n<2||n%2==0){
		return 0;
	}
	int s=0;ll r=n-1;
	while(r%2==0&&r>0){
		s=s+1;
		r=r/2;
	}
	for(int i=1;i<=5;i++){
		ll a= 2+rand()%(n-3);
		ll y= mod(n,a,r);
		if(y==1|y==n-1){
			return 1;
		}
		for(int j=1;j<s;j++){
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
void phantich(ll x){
	int i=2;
	while(!milerRabin(x)&&x!=1){
		if(x%i==0){
			while(x%i==0){
				x=x/i;
			}
			thuaso[index]=i;
			index++;
		}
		i++;
	}
	if(x>1){
		thuaso[index]=x;
		index++;
	}
}
int ktraptusinh(ll g,ll p ){
	for(int i=0;i<index;i++){
		if(mod(p,g,(p-1)/thuaso[i])==1){
			return 0;
		}
	}
	return 1;
}


int main(){
	ll p,g,k,y,m,a,b;
	printf("nhap p:\n");
	scanf("%lld",&p);
	while(!milerRabin(p)){
		printf("nhap lai p:\n");
	    scanf("%lld",&p);
	}
	printf("nhap g:\n");
	scanf("%lld",&g);
	while(!ktraptusinh(g,p)){
		printf("nhap lai g:\n");
	    scanf("%lld",&g);
	}
	printf("nhap k:\n");
	scanf("%lld",&k);
	while(k<1||k>p-2){
		printf("nhap lai k:\n");
	    scanf("%lld",&k);
	}
	printf("nhap y :\n");
	scanf("%lld",&y);
	printf("nhap m:\n");
	scanf("%lld",&m);
	a=mod(p,g,k);
	b=mod(p,y,k);
	b=(m*b)%p;
	printf("%lld\n",a);
	printf("%lld\n",b);
	return 0;
	
}
