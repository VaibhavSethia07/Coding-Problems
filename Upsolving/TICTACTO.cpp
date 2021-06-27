// Problem: Tic Tac Toe
// Contest: CodeChef - June Lunchtime 2021 Division 2
// URL: https://www.codechef.com/LTIME97B/problems/TICTACTO
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using l = long;
using ll = long long;
using ld = long double;
using db = double;
using str = string;

using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vl = vector<long>;
using vll = vector<ll>;

#define mp make_pair
#define f first
#define s second

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define modinv(a,m) modEx(a,m-2,m)
#define moddiv(a,b,m) (a*modinv(b,m))%m
const ll mod=1e9+7;

/* These template codes have been taken from cp-algorithms */
ll extEuclid(ll a,ll b,ll& x,ll& y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	
	ll x1,y1;
	ll d=extEuclid(b,a%b,x1,y1);
	x=y1;
	y=x1-(a/b)*y1;
	return d;
}

ll modInverse(ll a,ll n){
	ll x,y;
	extEuclid(a,n,x,y);
	return x;
}

ll linearCong(ll a,ll b,ll n){
	ll d=__gcd(a,n);
	
	if(b%d)
		return -1;
	a/=d;b/=d;n/=d;
	ll a_inv=modInverse(a,n);
	ll ans=(b*a_inv)%n;
	if(ans<0)
		ans+=n;
	return ans;
}

void divisors(map<int,int>& d,ll N){
	for(int div : {2,3,5}){
		int cnt=0;
		if(N%div==0){
			while((N%div)==0){
				N/=div;
				cnt++;
			}
			d[div]=cnt;
		}
	}
	static array<int,8> increments = {4,2,4,2,4,6,2,6};
	int i=0;
	for(ll div=7;div*div<=N;div+=increments[i++]){
		if((N%div)==0){
			int cnt=0;
			while((N%div)==0){
				N/=div;
				cnt++;
			}
			d[div]=cnt;
		}
		if(i==8)
			i=0;
	}
	if(N>1)
		d[N]=1;
}

/* Print the string of digits without leading zero */
void norm(string& str){
	bool zero=true;
	
	for(auto& c:str){
		if(c!='0')
			zero=false;
		if(c!='0' || !zero)
			cout<<c;
	}
}

void input(vl& v,int N){
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
}

int T,N,M,K;
const int MAXN=1005;
int arr[MAXN*MAXN][2];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin>>T;
		
	while(T--){
		cin>>N>>M>>K;
		
		for(int i=0;i<N*M;i++){
			cin>>arr[i][0]>>arr[i][1];
			arr[i][0]--,arr[i][1]--;
		}
		
		int grid[N][M];
		
		int start=K*K-1,end=N*M-1,ans=N*M;
		while(start<=end){
			int mid=start+(end-start)/2;
			
			for(int i=0;i<N;i++){
				for(int j=0;j<M;j++)
					grid[i][j]=0;
			}
			
			for(int i=0;i<=mid;i++){
				if((i%2)==0)
					grid[arr[i][0]][arr[i][1]]=1;
				else
					grid[arr[i][0]][arr[i][1]]=-1;
			}
			
			for(int i=0;i<N;i++){
				for(int j=0;j<M;j++){
					if(i-1>=0)
						grid[i][j]+=grid[i-1][j];
					if(j-1>=0)
						grid[i][j]+=grid[i][j-1];
					if(i-1>=0 && j-1>=0)
						grid[i][j]-=grid[i-1][j-1];
				}
			}
			
			bool ok=0;
			for(int i=0;i+K<=N;i++){
				for(int j=0;j+K<=M;j++){
					int r1=i,c1=j,r2=i+K-1,c2=j+K-1;
					int temp=grid[r2][c2];
					if(c1-1>=0)
						temp-=grid[r2][c1-1];
					if(r1-1>=0)
						temp-=grid[r1-1][c2];
					if(r1-1>=0 && c1-1>=0)
						temp+=grid[r1-1][c1-1];
					
					if(abs(temp)==K*K){
						ok=1;
						break;
					}
				}
				if(ok)
					break;
			}
			
			if(ok){
				ans=mid;
				end=mid-1;
			}else
				start=mid+1;
		}
		
		if(ans==N*M)
			cout<<"Draw\n";
		else if((ans%2)==0)
			cout<<"Alice\n";
		else
			cout<<"Bob\n";
	}
	
	return 0;	
}
