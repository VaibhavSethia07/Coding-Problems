// Problem: Problem 1. Time is Mooney
// Contest: USACO - USACO 2020 January Contest, Gold
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=993
// Memory Limit: 256 MB
// Time Limit: 4000 ms

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

int n,m,c,a,b;
const int MAXN=1e3+5;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	freopen("time.in","r",stdin);
	freopen("time.out","w",stdout);
	
	cin>>n>>m>>c;
	
	long moonies[n+10];
	vector<int> adj[n+10];
	
	for(int i=1;i<=n;i++)
		cin>>moonies[i];
		
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		adj[a].push_back(b);
	}
	
	vector<vector<long>> dp(1005,vector<long>(1005,-1));
	dp[0][1]=0;
	
	long ans=0;
	for(int t=0;t<1001;t++){
		for(int x=1;x<=n;x++){
			if(dp[t][x]==-1)
				continue;
			
			// calculating max profit whenever we reach city 1
			if(x==1)	
				ans=max(ans,dp[t][x]-c*t*t);
			
			// tranfering moonies to the neighbouring cities on the next day when we are visting
			for(auto& v:adj[x]){
				dp[t+1][v]=max(dp[t+1][v],dp[t][x]+moonies[v]);
			}
		}
	}	
	cout<<ans<<"\n";
	return 0;	
}
