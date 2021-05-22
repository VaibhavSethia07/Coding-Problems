// Problem: Problem 1. Switching on the Lights
// Contest: USACO - USACO 2015 December Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=570
// Memory Limit: 256 MB
// Time Limit: 4000 ms

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

int N,M,x,y,a,b;
bool toggle[105][105];
bool vis[105][105];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
map<pair<int,int>,vector<pair<int,int>>> adj;
void input(vl& v,int N){
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
}

bool isNotValid(int x,int y){
	return x<=0 || x>N || y<=0 || y>N || !toggle[x][y];
}

bool hasVisitedNeighbor(int x,int y){
	for(int i=0;i<4;i++){
		a=x+dx[i],b=y+dy[i];
		if(!isNotValid(a,b) && vis[a][b])
			return true;
	}
	return false;
}

void solve(int x,int y){
	if(isNotValid(x,y))
		return;
		
	vis[x][y]=1;

	for(auto& p:adj[{x,y}]){
		if(!toggle[p.f][p.s]){
			toggle[p.f][p.s]=1;
			if(hasVisitedNeighbor(p.f,p.s))
				solve(p.f,p.s);
		}
	}
	
	for(int i=0;i<4;i++){
		if(!vis[x+dx[i]][y+dy[i]] && toggle[x+dx[i]][y+dy[i]])
			solve(x+dx[i],y+dy[i]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	freopen("lightson.in","r",stdin);
	freopen("lightson.out","w",stdout);
	
	cin>>N>>M;
	for(int i=0;i<M;i++){
		cin>>x>>y>>a>>b;
		adj[{x,y}].pb({a,b});
	}
	toggle[1][1]=1;
	solve(1,1);
	int ans=0;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			
			if(toggle[i][j])
				ans++;
		}
	}
	cout<<ans;
	return 0;	
}
