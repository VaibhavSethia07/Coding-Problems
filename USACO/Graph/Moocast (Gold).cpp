
// Problem: Problem 1. Moocast
// Contest: USACO - USACO 2016 December Contest, Gold
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=669
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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

const int MAXN=1e3+5;
int V,a,b;
int x[MAXN];
int y[MAXN];
int parent[MAXN];
int sz[MAXN];
bool vis[MAXN];
vector<vector<int>> edges;

int dist(int a,int b){
	return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
}

void make_par(){
	for(int i=0;i<V;i++){
		parent[i]=i;
		sz[i]=1;
	}
}

int find(int a){
	vector<int> ancestors;
	
	while(parent[a]!=a){
		ancestors.push_back(a);
		a=parent[a];
	}
	
	for(int i=0;i<(int)ancestors.size();i++)
		parent[ancestors[i]]=a;
	
	return a;
}

void unite(int a,int b){
	a=find(a);
	b=find(b);
	
	if(find(a)==find(b))
		return;
		
	if(sz[b]>sz[a])
		swap(a,b);
		
	parent[b]=a;
	sz[a]+=sz[b];
}

void dfs(int u,int minCost){
	vis[u]=1;
	
	for(int v=0;v<V;v++){
		if(!vis[v] && dist(u,v)<=minCost){
			dfs(v,minCost);
		}
	}
}

bool can_communicate(int minCost){
	memset(vis,0,sizeof(vis));
	
	dfs(0,minCost);
	
	for(int i=0;i<V;i++)
		if(!vis[i])
			return false;
			
	return true;
}

void solve1(){
	for(int i=0;i<V;i++){
		cin>>x[i]>>y[i];
	}
	
	int start=1,end=1e9+1,result=1e9+1;
	
	while(start<=end){
		int minCost=start+(end-start)/2;
		if(can_communicate((minCost))){
			result=minCost;
			end=minCost-1;
		}else
			start=minCost+1;	
	}
	cout<<result<<"\n";
}

void solve2(){
	for(int i=0;i<V;i++){
		cin>>x[i]>>y[i];
	}
	
	for(int i=0;i<V;i++){
		for(int j=i+1;j<V;j++){
			edges.push_back({dist(i,j),i,j});
		}
	}
	sort(all(edges));
	make_par();
	int comp=V-1;
	int result=0;
	for(int i=0;i<(int)edges.size() && comp;i++){
		int a=edges[i][1],b=edges[i][2];
		if(find(a)!=find(b)){
			unite(a,b);
			comp--;
			result=edges[i][0];
		}
	}
	cout<<result<<"\n";
}

int main(){
	freopen("moocast.in","r",stdin);
	freopen("moocast.out","w",stdout);
	
	cin>>V;
	
	// solve1();
	solve2();
	
	return 0;	
}
