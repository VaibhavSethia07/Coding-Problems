/*
Byteland has n cities, and m roads between them. The goal is to construct new roads so that there is a route between any two cities.

Your task is to find out the minimum number of roads required, and also determine which roads should be built.

Input

The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,…,n.

After that, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.

A road always connects two different cities, and there is at most one road between any two cities.

Output

First print an integer k: the number of required roads.

Then, print k lines that describe the new roads. You can print any valid solution.

Constraints
1≤n≤105
1≤m≤2⋅105
1≤a,b≤n
Example

Input:
4 2
1 2
3 4

Output:
1
2 3

####################################################################################Solution#####################################################################################
*/

// Problem: Building Roads
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1666
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
vector<pair<int,int>> edges;
vector<vector<int>> g;
vector<bool> vis;
void input(vl& v,int N){
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
}

void solve(int u){
	vis[u]=true;
	for(auto& v:g[u]){
		if(!vis[v]){
			solve(v);
		}
	}
}

int main(){
	
	int V,E;
	cin>>V>>E;
	edges.resize(E);
	g.resize(V);
	vis.resize(V);
	
	int a,b;
	for(int i=0;i<E;i++){
		cin>>a>>b;
		a--;b--;
		edges[i]={a,b};
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int prev=-1,ans=-1;
	vector<pair<int,int>> roads;
	for(int i=0;i<V;i++){
		if(!vis[i]){
			ans++;
			roads.push_back({prev,i});
			solve(i);
		}
		prev=i;
	}
	cout<<ans<<"\n";
	for(int i=1;i<(int)roads.size();i++){
		cout<<roads[i].first+1<<" "<<roads[i].second+1<<"\n";
	}
	
	return 0;	
}
