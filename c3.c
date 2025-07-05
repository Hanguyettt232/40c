#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 1000

typedef long long ll;

ll nhiphan(ll k,int arr[])
{
	int i=0;
	while(k>0){
		arr[i++]=k%2;
		k=k/2;
	}
	return i;
}

ll mod(ll n,ll a,ll k){
	int arr[MAX];
	ll b=1;
	ll A=a;
	int len=nhiphan(k,arr);
	if(arr[0]==1){
		b=A;
	}
	for(int i=1;i<len;i++){
		A=(A*A)%n;
		if(arr[i]==1){
			b=(A*b)%n;
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
void chuyennum_arr(ll a,int arr[],int t){
	int i;
	for(i=t-1;i>=0;i--){
		arr[i]=a/pow(2,i*8);
		a=a-arr[i]*pow(2,i*8);
	}
}
ll chuyenarr_num(int arr[],int t)
{
	ll res=0;
	for(int i=t-1;i>=0;i--){
		res+=arr[i]*pow(2,i*8);
	}
	return res;
}
void tinhuv(ll uv,int res[]){
	int arr[16]={0};
	int i=15;
	res[0]=res[1]=0;
	while(uv>0){
		arr[i]=uv%2;
		uv=uv/2;
		i--;
	}
	for(int i=1;i<8;i++){
		res[0]+=arr[i]*pow(2,7-i);//phan nho
	}
	int j=7;
	for(i=8;i<16;i++){
		res[1]+=arr[i]*pow(2,j);
		j--;
	}
}
void nhanmang(int t,int a[],int b[],int c[])
{
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
	srand(time(NULL));
	ll p,q,n,m,c;
	int t=4;
	int mang_p[4]={0},mang_q[4]={0},mang_tich[8]={0};
	printf("nhap p:\n");
	scanf("%lld",&p);
	while(!milerRabin(p)||p%4!=3){
		printf("vui long nhap lai p:\n");
		scanf("%lld",&p);
	}
	printf("nhap q:\n");
	scanf("%lld",&q);
	while(!milerRabin(q)||q%4!=3){
		printf("vui long nhap lai q:\n");
		scanf("%d",&q);
		}
	printf("nhap so m:\n");
	scanf("%lld",&m);
	chuyennum_arr(p,mang_p,t);
	chuyennum_arr(q,mang_q,t);
	nhanmang(t,mang_p,mang_q,mang_tich);
	n=chuyenarr_num(mang_tich,t);
	c=mod(n,m,2);
	printf("%lld",c);
	return 0;
}
