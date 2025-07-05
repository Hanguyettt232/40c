#include<stdio.h>
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
			b=(b*A)%n;
		}
		k=k/2;
	}
	return b;
}
ll milerRabin(ll n){
	ll a,y;
	if(n==2||n==3){
		return 1;
	}
	if(n<2||n%2==0){
		return 0;
	}
	int s=0; ll r=n-1;
	while(r%2==0&&r>0){
		s+=1;
		r=r/2;
	}
	for(int i=0;i<5;i++){
		a=2+rand()%(n-3);
		y=mod(n,a,r);
		if(y==1||y==n-1){
			return 1;
		}
		for(int j=1;j<s;j++){
			y=(y*y)%n;
			if(y==1){
				return 0;
			}
			if(y==n-1){
				return 1;
			}
			if(y!=n-1)
			   return 0;
		}
	}
	return 1;
}

void chiangicdao(ll a,ll b, ll res[]){
	ll q,r,x,y,x1,x2,y1,y2;
	x2=y1=1;
	x1=y2=0;
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
	res[1]=x2;
	res[2]=y2;
}
int main(){
	ll p,a;
	srand(time(NULL));
	printf("nhap p: \n");
	scanf("%lld",&p);
	while(!milerRabin(p)){
		printf("nhap lai p: \n");
	    scanf("%lld",&p);
	}
	printf("nhap a: \n");
	scanf("%lld",&a);
	while(a<1||a>=p){
		printf("nhap lai a: \n");
	    scanf("%lld",&a);
	}
	ll kq[3];
	chiangicdao(a,p,kq);
	if(kq[0]!=1){
		printf("not found");
	}
	else{
		if(kq[1]<0){
			kq[1]+=p;
		}
		printf("%lld",kq[1]);
	}
	
	return 0;
}
