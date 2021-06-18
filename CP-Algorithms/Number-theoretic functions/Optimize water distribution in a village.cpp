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

const int MAXN=1e5+5;
int par[MAXN];
int sz[MAXN];

void make_par(){
	for(int i=1;i<MAXN;i++){
		par[i]=i;
		sz[i]=1;
	}
}

int find(int x){
	vector<int> anc;
	while(x!=par[x]){
		anc.push_back(x);
		x=par[x];
	}
	
	for(int i=0;i<(int)anc.size();i++)
		par[anc[i]]=x;
	return x;
}

bool unite(int a,int b){
	if(find(a)==find(b))
		return false;
		
	a=find(a);
	b=find(b);
	
	if(sz[b]>sz[a])
		swap(a,b);
	par[b]=a;
	sz[a]+=sz[b];
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    make_par();
    long N,K,cost,a,b;
	cin>>N;

	vector<vector<int>> edges(N);
	// Node 0 represents well
	for(int i=1;i<=N;i++){
		cin>>cost;
		edges[i-1]={cost,0,i};
	}
	cin>>K;
	for(int i=0;i<K;i++){
		cin>>a>>b>>cost;
		edges.push_back({cost,a,b});
	}
	
	sort(all(edges));
	
	long totalCost=0;
	for(int i=0;i<(int)edges.size();i++){
		if(unite(edges[i][1],edges[i][2]))
		totalCost+=edges[i][0];
	}
	
	cout<<totalCost<<"\n";
	return 0;	
}
