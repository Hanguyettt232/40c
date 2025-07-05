#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef long long ll;

ll mod(ll n, ll a, ll k){
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
int milerRabin(int n){
	if(n==2||n==3){
		return 1;
	}
	if(n<2||n%2==0){
		return 0;
	}
	srand(time(NULL));
	int s=0; ll r=n-1;
	while(r%2==0&&r>0){
		s+=1;
		r/=2;
	}
	for(int i=0;i<5;i++){
	    ll a=2+rand()%(n-3);
	    ll y=mod(n,a,n-1);
	    if(y==1||y==n-1){
	    	return 1;
		}
		for(int j=0;j<s;j++){
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
	int N;
	int t=5;
	scanf("%d",&N);
	int a[N];
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			if (a[i]==a[j]){
				for(int k=j;k<N-1;k++){
					a[k]=a[k+1];
				}
				N--;
				j--;
			}
		}
	}
	for(int i=0;i<N;i++){
		if(!milerRabin(a[i])){
		   for(int k=i;k<N-1;k++){
		   	a[k]=a[k+1];
		   }
		   	N--;
		    i--;
		}
	}
	for(int i=0;i<N;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
