// Problem: Subtree Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1137
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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
const int MAXN=2e5;

vector<int> tree[MAXN];
ll seg[2*MAXN];
int arr[MAXN];
int inTime[MAXN];
int outTime[MAXN];
int V,Q,t,a,b;
int Time=0;

void update(int i,int x){
	i+=V;
	seg[i]=x;
	while(i>1){
		i>>=1;
		seg[i]=seg[i<<1]+seg[i<<1|1];
	}
}

ll query(int l,int r){
	l+=V;
	r+=V;
	ll sum=0;
	while(l<=r){
		if(l&1)
			sum+=seg[l++];
	
		if(!(r&1))
			sum+=seg[r--];
		l>>=1;
		r>>=1;
	}
	return sum;
}

void dfs(int u,int p){
	inTime[u]=Time++;
	for(auto& v:tree[u]){
		if(v==p)
			continue;
		dfs(v,u);
	}
	outTime[u]=Time-1;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>V>>Q;
    for(int i=1;i<=V;i++)
    	cin>>arr[i];
    	
    for(int i=0;i<V-1;i++){
    	cin>>a>>b;
    	tree[a].push_back(b);
    	tree[b].push_back(a);
    }
    Time=0;
    dfs(1,0);
    for(int i=1;i<=V;i++)
		update(inTime[i],arr[i]);
    	
	
    for(int i=0;i<Q;i++){
    	cin>>t;
    	if(t==1){
    		cin>>a>>b;
    		update(inTime[a],b);
    	}else{
    		cin>>a;
    		cout<<query(inTime[a],outTime[a])<<"\n";
    	}
    }
    
	
	return 0;	
}
