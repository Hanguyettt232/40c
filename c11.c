#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

typedef long long ll;

void chuyennum_arr(ll a,ll arr[],int t){
	for(int i=t-1;i>=0;i--){
		arr[i]=a/pow(2,i*8);
		a=a-arr[i]*pow(2,i*8);
	}
}
ll chuyenarr_num(ll arr[],int t){
	ll res=0;
	for(int i=t-1;i>=0;i--){
		res+=arr[i]*pow(2,i*8);
	}
	return res;
}
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
ll milerRabin(ll n){
	if(n==2||n==3){
		return 1;
	}
	if(n<2||n%2==0){
		return 0;
	}
	int s=0;
	ll r=n-1;
	srand(time(NULL));
	for(int i=1;i<=5;i++){
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
void tinhuv(ll uv,int res[]){
	res[0]=res[1]=0;
	int arr[16]={0};
	int i=15;
	while(uv>0){
		arr[i]=uv%2;
		uv=uv/2;
		i--;
	}
	for(int i=0;i<8;i++){
		res[0]+=arr[i]*pow(2,7-i);
	}
	int j=7;
	for(int i=8;i<16;i++){
		res[1]+=arr[i]*pow(2,j);
		j--;
	}
}
void tinhmang(int t,ll a[],ll b[],ll c[]){
	int res[2]={0};
	ll uv,u;
	for(int i=0;i<t;i++){
		u=0;
		for(int j=0;j<t;j++){
			uv=c[i+j]+(ll)a[i]*b[j]+u;
			tinhuv(uv,res);
			c[i+j]=res[1];
			u=res[0];
		}
		c[i+t]=u;
	}
}

 int main(){
 	ll p,q,m,d,s,n;
 	int t=4;
 	printf("nhap p:\n");
 	scanf("%lld",&p);
 	while(!milerRabin(p)){
 		printf("nhap lai p:\n");
 		scanf("%lld",&p);
	 }
	printf("nhap q:\n");
 	scanf("%lld",&q);
 	while(!milerRabin(q)){
 		printf("nhap lai q:\n");
 		scanf("%lld",&q);
	 }
	printf("nhap m:\n");
 	scanf("%lld",&m);
	printf("nhap d:\n");
 	scanf("%lld",&d);
 	ll mang_p[4]={0},mang_q[4]={0},mang_tich[8]={0};
 	chuyennum_arr(p,mang_p,t);
 	chuyennum_arr(q,mang_q,t);
 	tinhmang(t,mang_p,mang_q,mang_tich);
 	n=chuyenarr_num(mang_tich,t*2);
// 	printf("%lld",n);
    s=mod(n,m,d);
    printf("%lld",s);
 	return 0;
 }

