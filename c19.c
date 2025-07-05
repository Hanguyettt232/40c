#include<stdio.h>
#include<stdlib.h>

typedef long long ll;
 int mod( ll n, ll a, ll k){
 	ll b=1, A=a%n;
 	if(k%2==1){
 		b=A;
	 }
	 k=k/2;
	 while(k>0){
	 	A=(A*A)%n;
	 	if(k%2==1){
	 		b=(b*A)%2;
		 }
		 k=k/2;
	 }
	 return b;
 }
 int milerRabin(ll n){
 	if(n==2||n==3){
 		return 1;
	 }
	 if(n<2||n%2==0){
	 	return 0;
	 }
	 int s=0;ll r=n-1;
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
			 if(y!=n-1){
			 	return 0;
			 }
		 }
	 }
	 return 1;
 }
 int main(){
 	ll a,b,sum=0;
 	scanf("%lld %lld",&a,&b);
 	for(int i=a;i<=b;i++){
 		if(milerRabin(i)){
 			sum+=i;
		 }
	 }
	 printf("%lld",sum);
 	return 0;
 }
