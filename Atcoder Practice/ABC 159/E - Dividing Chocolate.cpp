// Problem: E - Dividing Chocolate
// Contest: AtCoder - AtCoder Beginner Contest 159
// URL: https://atcoder.jp/contests/abc159/tasks/abc159_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

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

int mat[1000][1000];
int prefix[1001][1001];
int R,C,K;
void input(vl& v,int N){
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
}

int solve(int fromX,int fromY,int toX,int toY){
	return prefix[toX][toY]-prefix[fromX-1][toY]-prefix[toX][fromY-1]+prefix[fromX-1][fromY-1];
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin>>R>>C>>K;
	char ch;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin>>ch;
			mat[i][j]=ch-'0';
		}
	}
	
	for(int i=1;i<1001;i++){
		for(int j=1;j<1001;j++){
			prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+mat[i-1][j-1];
		}
	}
	int res=1e9;
	for(int mask=0;mask<1<<(R-1);mask++){
		vector<int> row_cuts;
		row_cuts.pb(0);
		
		int curr=0;
		for(int i=0;i<R-1;i++){
			if((mask&(1<<i))!=0){
				row_cuts.pb(i+1);
				curr++;
			}
		}
		row_cuts.pb(R);
		int col=1;
		bool ok=1;
		for(int i=1;i<=C;i++){
			int curr_max=0;
			for(int j=0;j<(int)row_cuts.size()-1;j++){
				curr_max=max(curr_max,solve(row_cuts[j]+1,col,row_cuts[j+1],i));
			}
			
			if(curr_max>K){
				if(col==i){
					ok=0;
					break;
				}
				curr++;
				col=i;
			}
		}
		if(ok)
			res=min(res,curr);
		
	}
	

	cout<<res;
	
	return 0;	
}
