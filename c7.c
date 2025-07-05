#include<stdio.h>
#include<stdlib.h>

typedef long long ll; 
ll thuaso[1000]={0};
int index =0;
ll mod( ll n,ll a,ll k){
	ll b=1; ll A=a%n;
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
	int s=0;
	ll r=n-1;
	while(r%2==0&&r>0){
		s+=1;
		r=r/2;
	}
	for(int i=0;i<5;i++){
		ll a= 2+rand()%(n-3);
		ll y=mod(n,a,r);
		if(y==1||y==n-1){
			return 1;
		}
		for(int j=1;j<s;j++){
			y=(y*y)%n;
			if(y==1){
				return 0;
			}
			if(y!=(n-1)){
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
int ktraphantusinh(ll g,ll p){
	for(int i=0;i<index;i++){
		if(mod(p,g,(p-1)/thuaso[i])==1){
			return 0;
		}
	}
	return 1;
}
int main(){
	ll p,g,x;
	printf("nhap p:\n");
	scanf("%lld",&p);
	while(!milerRabin(p)){
		printf("nhap lai p:\n");
	    scanf("%lld",&p);
	}
	printf("nhap g:\n");
	scanf("%lld",&g);
	while(!ktraphantusinh(p,g)){
		printf("nhap lai g:\n");
	    scanf("%lld",&g);
	}
	printf("nhap x:\n");
	scanf("%lld",&x);
	while(x<1||x>p-2){
		printf("nhap lai x:\n");
	    scanf("%lld",&x);
	}
	ll y= mod(p,g,x);
	printf("%lld",y);
	
	
	
	
	
	return 0;
}
