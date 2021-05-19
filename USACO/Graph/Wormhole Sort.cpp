// Problem: Problem 3. Wormhole Sort
// Contest: USACO - USACO 2020 January Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=992
// Memory Limit: 256 MB
// Time Limit: 4000 ms

#include <bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int V,E,a,b,w;
const int MAXN=1e5+5;
vector<pair<int,int>> adj[MAXN];
int comp[MAXN];
int loc[MAXN];

int parent[MAXN];
int sz[MAXN];
vector<vector<int>> edges;

void dfs(int u,int compNo,int minW){
	comp[u]=compNo;	
	for(pair<int,int> p:adj[u]){
		if(comp[p.first]!=-1)
			continue;
		if(p.second>=minW)
			dfs(p.first,compNo,minW);
	}
}

bool is_Valid(int minW){
	memset(comp,-1,sizeof(comp));
	
	int compNo=0;
	for(int u=1;u<=V;u++){
		if(comp[u]==-1)
			dfs(u,compNo++,minW);
	}
	
	for(int i=0;i<V;i++){
		if(comp[i]!=comp[loc[i]])
			return false;
	}
	return true;
}

void solve1(){
	for(int i=0;i<V;i++){
		cin>>loc[i];
		loc[i]--;
	}
		
	for(int i=0;i<E;i++){
		cin>>a>>b>>w;
		a--,b--;
		adj[a].push_back({b,w});
		adj[b].push_back({a,w});
	}
	
	int start=1,end=1e9+1,result=1e9+1;
	while(start<=end){
		int minW=start+(end-start)/2;
		if(is_Valid(minW)){
			result=minW;
			start=minW+1;
		}else
			end=minW-1;
	}
	
	if(result==1e9+1)
		cout<<-1;
	else
		cout<<result;
}

void make_par(){
	for(int i=0;i<V;i++){
		parent[i]=i;
		sz[i]=1;
	}
}

int find(int a){
	vector<int> ancestors;
	
	while(a!=parent[a]){
		ancestors.push_back(a);
		a=parent[a];
	}
	
	for(int i=0;i<(int)ancestors.size();i++)
		parent[ancestors[i]]=a;
	
	return a;
}

void unite(int a,int b){
	if(find(a)==find(b))
		return;
		
	a=find(a);
	b=find(b);
	
	if(sz[a]<sz[b])
		swap(a,b);
		
	parent[b]=a;
	sz[a]+=sz[b];
}

bool is_valid2(int minW){
	make_par();
	for(int i=0;i<E;i++){
		if(edges[i][2]>=minW)
			unite(edges[i][0],edges[i][1]);
	}
	
	for(int i=0;i<V;i++){
		if(find(loc[i])!=find(i))
			return false;
	}
	return true;
}

void solve2(){
	for(int i=0;i<V;i++){
		cin>>loc[i];
		loc[i]--;
	}
	
	for(int i=0;i<E;i++){
		cin>>a>>b>>w;
		a--,b--;
		edges.push_back({a,b,w});
	}
	
	int start=1,end=1e9+1,res=1e9+1;
	
	while(start<=end){
		int minW=start+(end-start)/2;
		if(is_valid2(minW)){
			res=minW;
			start=minW+1;
		}else
			end=minW-1;
	}
	
	if(res==1e9+1)
		cout<<-1<<"\n";
	else
		cout<<res<<"\n";
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	freopen("wormsort.in","r",stdin);
	freopen("wormsort.out","w",stdout);
	
	cin>>V>>E;
	// solve1();
	solve2();
	
	return 0;	
}
