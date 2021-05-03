// Problem: Lowest Common Ancestor
// Contest: Library Checker
// URL: https://judge.yosupo.jp/problem/lca
// Memory Limit: 1024 MB
// Time Limit: 5000 ms

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

const int MAXN=5e5+5;
const int MAXP=25;

int V,Q,a,b;
vector<int> adj[MAXN];
int parent[MAXN];
int level[MAXN];
int sparse[MAXN][MAXP];
void init(){
	for(int i=0;i<MAXN;i++){
		for(int j=0;j<MAXP;j++)
			sparse[i][j]=-1;
	}
	
	for(int i=0;i<V;i++){
		sparse[i][0]=parent[i];
	}
	
	for(int j=1;j<MAXP;j++){
		for(int i=0;i<MAXN;i++){
			int par=sparse[i][j-1];
			if(par!=-1)
				sparse[i][j]=sparse[par][j-1];
		}
	}
}

int lca(int a,int b){
	if(level[a]>level[b])
		swap(a,b);
		
	int d=level[b]-level[a];
	while(d>0){
		int L=log2(d);
		b=sparse[b][L];
		d-=(1<<L);
	}
	
	if(a==b)
		return a;
		
	for(int i=MAXP-1;i>=0;i--){
		if(sparse[a][i]!=-1 && (sparse[a][i]!=sparse[b][i]))
			a=sparse[a][i],b=sparse[b][i];
	}
	
	return sparse[a][0];
}

void dfs(int u,int par){
	for(auto& v:adj[u]){
		if(v==par)
			continue;
		level[v]=level[u]+1;
		dfs(v,u);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin>>V>>Q;
	parent[0]=-1;
	for(int i=1;i<V;i++){
		cin>>parent[i];
		adj[parent[i]].push_back(i);
		adj[i].push_back(parent[i]);
	}
	dfs(0,-1);
	init();
	for(int q=0;q<Q;q++){
		cin>>a>>b;
		cout<<lca(a,b)<<"\n";
	}
	return 0;	
}
