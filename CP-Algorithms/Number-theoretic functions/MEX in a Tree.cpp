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

vector<int> val;
vector<int> inTime;
vector<int> outTime;
vector<int> parent;
vector<int> mex;
vector<vector<int>> tree;
int Time=0;
void dfs(int u,int par){
	parent[u]=par;
	inTime[u]=++Time;
	
	for(auto& v:tree[u]){
		if(v==par)
			continue;
		dfs(v,u);
	}
	
	outTime[u]=++Time;
}

bool isAncestor(int u,int v){
	return inTime[u]<=inTime[v] && outTime[u]>=outTime[v];
}

void cal(int u,int par,set<int>& s){
	for(auto& v:tree[u]){
		if(v==par)
			continue;
		cal(v,u,s);
	}
	s.erase(val[u]);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
 	int N,a,b;
 	cin>>N;
 	
 	val.resize(N);
 	inTime.resize(N);
 	outTime.resize(N);
 	parent.resize(N);
 	mex.resize(N);
 	tree.resize(N);
 	Time=0;
 	
 	for(int i=0;i<N-1;i++){
 		cin>>a>>b;
 		tree[a].push_back(b);
 		tree[b].push_back(a);
 	}
 	
 	for(auto& i:val)
 		cin>>i;
 	
 	int zero=find(val.begin(),val.end(),0)-val.begin();
 	
 	dfs(0,-1);
 	set<int> s;
 	for(int i=0;i<=N;i++)
 		s.insert(i);
 	
 	for(int i=0;i<N;i++){
 		if(isAncestor(zero,i))
 			s.erase(val[i]);
 		else
 			mex[i]=0;
 	}
 	
 	mex[zero]=*s.begin();
 	s.erase(val[zero]);
 	
 	int curr=parent[zero];
 	
 	while(curr!=-1){
 		cal(curr,parent[curr],s);
 		mex[curr]=*s.begin();
 		curr=parent[curr];
 	}
 	
 	for(auto& x:mex)
 		cout<<x<<" ";
	
	return 0;	
}
