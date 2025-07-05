#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef long long ll;
 int index=0;
 ll thuaso[1000]={0};
 
 ll mod(ll n, ll a,ll k){
 	ll b=1,A=a%n;
 	if(k%2==1){
 		b=a;
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
	while(r%2==0&r>0){
		s+=1;
		r/=2;
	}
	srand(time(NULL));
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
			if(y==n-1){
				break;
			}
		}
		if(y!=n-1){
			return 0;
		}
	}
	return 1;
	
 }
 void ptich(ll x){
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
 }
 int ktraptusinh(ll g,ll p){
 	for(int i=0;i<index;i++){
 		if(mod(p,g,(p-1)/thuaso[i])==1){
 			return 0;
		 }
	 }
	 return 1;
 }
 void nghichdao(ll a,ll b,ll res[]){
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
 	ll p,alpha,a,b,k,x,phi,gama;
 	printf("nhap p:\n");
 	scanf("%lld",&p);
 	while(!milerRabin(p)){
 		printf("nhap lai p:\n");
 		scanf("%lld",&p);
	 }
	printf("nhap alpha:\n");
 	scanf("%lld",&alpha);
 	while(!ktraptusinh(alpha,p)){
 		printf("nhap lai alpha:\n");
 		scanf("%lld",&alpha);
	 }
	printf("nhap a:\n");
 	scanf("%lld",&a);
 	printf("nhap k:\n");
 	scanf("%lld",&k);
 	printf("nhap x:\n");
 	scanf("%lld",&x);
 	gama=mod(p,alpha,k);
 	ll res[3];
 	nghichdao(p-1,k,res);
 	phi=mod(p-1,res[2],1);
 	phi=((x-a*gama)*phi)%(p-1);
 	printf("%lld %lld",gama,phi);
 	return 0;
 }
