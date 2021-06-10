// Problem: Quantum Superposition
// Contest: Kattis
// URL: https://open.kattis.com/problems/quantumsuperposition
// Memory Limit: 1024 MB
// Time Limit: 1000 ms

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

const int MAXN=1e3+1;
int a,b,Q;
int n[2],m[2];
vector<int> adj[2][MAXN];
vector<int> back[2][MAXN];
bitset<2*MAXN> dp[2][MAXN];

void gen(int x){
	int in_degree[MAXN]={0};
	
	for(int i=0;i<m[x];i++){
		cin>>a>>b;
		adj[x][a].pb(b);
		back[x][b].pb(a);
		in_degree[b]++;
		
	}
	
	queue<int> q;
	
	for(int i=1;i<=n[x];i++){
		if(in_degree[i]==0)
			q.push(i);
	}
	
	while(!q.empty()){
		int u=q.front();
		q.pop();
		
		if(back[x][u].empty())
			dp[x][u][0]=1;
		for(auto& v:back[x][u]){
			dp[x][u]|=(dp[x][v]<<1);
		}
		for(auto& v:adj[x][u]){
			in_degree[v]--;
			if(in_degree[v]==0)
				q.push(v);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin>>n[0]>>n[1]>>m[0]>>m[1];
	gen(0),gen(1);
	
	bitset<2*MAXN> ans;
	for(int i=0;i<=m[0];i++){
		if(dp[0][n[0]][i]){
			ans|=dp[1][n[1]]<<i;
		}
	}

	cin>>Q;
	for(int q=1;q<=Q;q++){
		cin>>a;
		if(ans[a])
			cout<<"Yes\n";
		else	
			cout<<"No\n";
	}
	
	return 0;	
}
