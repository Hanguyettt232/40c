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
		s+=1;
		r=r/2;
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
int ktraptusinh(ll g,ll p){
	for(int i=0;i<index;i++){
		if(mod(p,g,(p-1)/thuaso[i])!=1){
			return 0;
		}
	}
	return 1;
}

void nghichdao(ll a,ll b,int res[]){
	ll q,r,x1,x2,y1,y2,x,y;
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
	res[1]=x2;
	res[2]=y2;
}
int main(){
	ll p,g,x,a,b,m;
	int t=4;
	printf("nhap p:\n");
	scanf("%lld",&p);
	while(!milerRabin(p)){
		printf("nhap lai  p:\n");
	    scanf("%lld",&p);
	}
	printf("nhap g:\n");
	scanf("%lld",&g);
	while(!ktraptusinh(g,p)){
		printf("nhap lai g:\n");
	    scanf("%lld",&g);
	}
	printf("nhap x:\n");
	scanf("%lld",&x);
	if(x<1||x>p-2){
		printf("nhap lai x:\n");
	    scanf("%lld",&x);
	}
	printf("nhap a,b:\n");
	scanf("%lld %lld",&a,&b);
	int res[3];
	ll a_x=mod(p,a,x);
	nghichdao(a_x,p,res);
	if(res[1]<0){
		res[1]=res[1]+p;
	}
	else{
		res[1]=res[1];
	}
	m=(b*res[1])%p;
	printf("%lld",m);
	return 0;
}
