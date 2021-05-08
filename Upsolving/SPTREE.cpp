// Problem: A Special Tree
// Contest: CodeChef - April Lunchtime 2021 Division 2
// URL: https://www.codechef.com/LTIME95B/problems/SPTREE
// Memory Limit: 256 MB
// Time Limit: 1000 ms

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

const int MAXN=2e5+5;
vector<vector<int>> adj(MAXN);
bool is_spl[MAXN];
int parent[MAXN];
int depth[MAXN];
int ans[MAXN];
int node[MAXN];

int dfs1(int u,int par=-1){
	parent[u]=par;
	
	for(auto& v:adj[u]){
		if(v==par)
			continue;
		depth[v]=depth[u]+1;
		int temp=dfs1(v,u);
		if(temp!=-1 && node[u]==-1){
			ans[u]=depth[u];
			node[u]=temp;
		}
	}
	
	if(is_spl[u]){
		ans[u]=depth[u];
		node[u]=u;
		return u;
	}
	return node[u];
}

void dfs2(int u,int dpth,int par,int L){
	ans[u]=depth[L]-dpth;
	node[u]=node[L];
	
	for(auto& v:adj[u]){
		if(v==par)
			continue;
		dfs2(v,dpth+1,u,L);
	}
}

void init(){
	memset(is_spl,false,sizeof(is_spl));
	memset(parent,-1,sizeof(parent));
	memset(depth,0,sizeof(depth));
	memset(node,-1,sizeof(node));
	memset(ans,0,sizeof(ans));
	
	adj.clear();
	adj.resize(MAXN);
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int T,N,K,a,sp,u,v;
	cin>>T;
	while(T--){
		cin>>N>>K>>a;
		a--;
		
		init();
		for(int i=0;i<K;i++){
			cin>>sp;
			sp--;
			is_spl[sp]=1;
		}
		
		for(int i=0;i<N-1;i++){
			cin>>u>>v;
			u--;v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		// Marking all the nodes of type P
		dfs1(a);
		for(int i=0;i<N;i++){
			if(node[i]==-1 && parent[i]!=-1 && node[parent[i]]!=-1)
				dfs2(i,1,parent[i],parent[i]);
		}
		
		for(int i=0;i<N;i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
		for(int i=0;i<N;i++)
			cout<<node[i]+1<<" ";
		cout<<"\n";
		
	}
	
	return 0;	
}
