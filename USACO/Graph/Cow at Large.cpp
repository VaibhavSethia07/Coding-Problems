// Problem: Problem 2. Cow at Large
// Contest: USACO - USACO 2018 January Contest, Gold
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=790
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

int V,K,a,b;
const int MAXN=1e5+5;
vector<int> adj[MAXN];
int distStart[MAXN];
int distLeaf[MAXN];
int ans=0;

void distances1(int u,int par){
	if(par!=-1)
		distStart[u]=distStart[par]+1;
	else
		distStart[u]=0;
		
	distLeaf[u]=MAXN;
	
	bool isLeaf=1;
	for(auto& v:adj[u]){
		if(v==par)
			continue;
		isLeaf=0;
		distances1(v,u);
		distLeaf[u]=min(distLeaf[u],1+distLeaf[v]);
	}
	
	if(isLeaf)
		distLeaf[u]=0;
}

void distances2(int u,int par){
	if(par!=-1)
		distLeaf[u]=min(distLeaf[u],1+distLeaf[par]);
		
	for(auto& v:adj[u]){
		if(v==par)
			continue;
		distances2(v,u);
	}
}

void dfs(int u,int par){
	// If Farmer can reach this node at the same/earlier than Bessie and Bessie can reach its parent earlier than the Farmer
	if(par!=-1 && distLeaf[u]<=distStart[u] && distStart[par]<distLeaf[par])
		ans++;
		
	for(auto& v:adj[u]){
		if(v==par)
			continue;
		dfs(v,u);
	}
		
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	freopen("atlarge.in","r",stdin);
	freopen("atlarge.out","w",stdout);
	
	cin>>V>>K;
	
	for(int i=1;i<V;i++){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	// Finding distance of every node from root as well as from nearest leaf in its subtree
	distances1(K,-1);
	// Minimzing the distance using leaf nodes other than from the subtree
	distances2(K,-1);
	// Computing the # of farmers required
	dfs(K,-1);
	cout<<ans;
	
	return 0;	
}
