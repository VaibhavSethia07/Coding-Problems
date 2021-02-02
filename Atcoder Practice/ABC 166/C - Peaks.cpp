
// Problem: C - Peaks
// Contest: AtCoder - AtCoder Beginner Contest 166
// URL: https://atcoder.jp/contests/abc166/tasks/abc166_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
vector<vector<int>> g;
vector<bool> vis;
vector<int> ht;
int V,E,a,b,ans;
void input(int V,int E){
	g.clear();
	vis.clear();
	ht.clear();
	g.resize(V);
	vis.resize(V);
	ht.resize(V);
	
	for(int i=0;i<V;i++)
		cin>>ht[i];
	
	for(int i=0;i<E;i++){
		cin>>a>>b;
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
}

void solve(int u){
	vis[u]=1;
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		u=q.front();
		q.pop();
		bool ok=true;
		for(auto& v:g[u])
			ok&=(ht[v]<ht[u]);
			
		if(ok)
			ans++;
		for(auto& v:g[u]){
			if(!vis[v]){
				vis[v]=1;
				q.push(v);
			}
		}
	}
}

int main(){
	
	cin>>V>>E;
	input(V,E);
	
	for(int i=0;i<V;i++){
		if(!vis[i])
			solve(i);
	}
	cout<<ans<<"\n";
	return 0;	
}
