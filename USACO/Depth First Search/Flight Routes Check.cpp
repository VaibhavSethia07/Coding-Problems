
// Problem: Flight Routes Check
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1682
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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
		int cnt=1;
		if(N%2==0){
			while((N%2)==0){
				N/=2;
				cnt++;
			}
			d[div]=cnt;
		}
	}
	static array<int,8> increments = {4,2,4,2,4,6,2,6};
	int i=0;
	for(ll div=7;div*div<=N;div+=increments[i++]){
		if((N%div)==0){
			int cnt=1;
			while((N%i)==0){
				N/=i;
				cnt++;
			}
			d[i]=cnt;
		}
		if(i==8)
			i=0;
	}
	if(N>1)
		d[N]=2;
}

int V,E,a,b;
vector<vector<int>> g;
vector<vector<int>> t;
vector<bool> vis;
stack<int> path;
void input(){
	g.clear();
	g.resize(V);
	t.clear();
	t.resize(V);
	
	vis.clear();
	vis.resize(V);
	
	for(int i=0;i<E;i++){
		cin>>a>>b;
		a--;b--;
		g[a].push_back(b);
	}
}

void dfs(int u,vector<vector<int>>& g){
	vis[u]=true;
	
	for(auto& v:g[u]){
		if(!vis[v])
			dfs(v,g);
	}	
	path.push(u);
}

int main(){
	
	cin>>V>>E;
	input();
	for(int i=0;i<V;i++){
		if(!vis[i])
			dfs(i,g);
	}
	for(int u=0;u<V;u++){
		for(auto& v:g[u]){
			t[v].push_back(u);
		}
	}
	vis.clear();
	vis.resize(V);
	
	int u=-1,v=-1;
	while(!path.empty()){
		v=path.top();
		path.pop();
		if(!vis[v]){
			if(u!=-1){
				cout<<"NO\n"<<v+1<<" "<<u+1<<"\n";
				return 0;
			}
			dfs(v,t);
			u=v;
		}
	}
	cout<<"YES\n";
	
	return 0;	
}
