#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

typedef long long ll;
static int stt=1;
typedef struct
{
	ll x,y;
}Eliptic;
Eliptic Eliptic_init(){
	Eliptic point;
	printf("nhap toa do thu %d\n",stt);
	scanf("%lld",&point.x);
	scanf("%lld",&point.y);
	stt++;
	return point;
	
}
void Eliptic_printf(Eliptic point){
	printf("Toa do diem(%lld %lld)\n",point.x,point.y);
}
ll nghichdao(ll a,ll b){
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
   return (x2+p)%p;
 }
ll mod(ll n, ll a,ll k){
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
	 return (b+n)%n;
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
 Eliptic Cong(Eliptic P,Eliptic Q,ll a,ll p){
 	ll ganma=0,tu,mau;
 	Eliptic R={0,0};
 	if(P.x==Q.x&&((P.y + Q.y) % p == 0)){
 		return R;
	 }
	 else if(P.x==Q.x&&P.y==Q.y){
	 	tu=(p,3*P.x*P.x+a)%p;
	 	mau=nghichdao(2*P.y,p);
	 	ganma=(tu*mau)%p;
	 }
	 else{
	 	tu=(Q.y-P.y)%p;
	 	mau=nghichdao(Q.x-P.x,p);
	 	ganma=(tu*mau)%p;
	 }
	R.x=(ganma*ganma-P.x-Q.x)%p;
	R.y=(p,ganma*(P.x-R.x)-P.y)%p;
	return R;
 }
 Eliptic Elipticosan(ll a,ll b){
 	Eliptic point;
 	point.x=a;
 	point.y=b;
 	return point;
 }
 int main(){
 	ll p,a,b,na,ga,gb;
 	printf("nhap p:\n");
 	scanf("%lld",&p);
 	while(!milerRabin(p)){
 		printf("nhap lai p:\n");
 	    scanf("%lld",&p);
	 }
	printf("nhap a:\n");
 	scanf("%lld",&a);
 	printf("nhap b:\n");
 	scanf("%lld",&b);
 	printf("nhap toa do G:");
 	scanf("%lld %lld",&ga,&gb);
 	printf("nhap na:\n");
 	scanf("%lld",&na);
 	Eliptic G=Elipticosan(ga,gb);
 	Eliptic R=Elipticosan(ga,gb);
 	Eliptic_printf(G);
 	for(int i=1;i<na;i++){
 		R=Cong(R,G,a,p);
	 }
 	Eliptic_printf(R); 
 	return 0;
 }

