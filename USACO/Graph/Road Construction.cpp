// Problem: Road Construction
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1676
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
#include <unordered_set>
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
		int cnt=0;
		if(N%div==0){
			while((N%div)==0){
				N/=div;
				cnt++;
			}
			d[div]=cnt;
		}
	}
	static array<int,8> increments = {4,2,4,2,4,6,2,6};
	int i=0;
	for(ll div=7;div*div<=N;div+=increments[i++]){
		if((N%div)==0){
			int cnt=0;
			while((N%div)==0){
				N/=div;
				cnt++;
			}
			d[div]=cnt;
		}
		if(i==8)
			i=0;
	}
	if(N>1)
		d[N]=1;
}

/* Print the string of digits without leading zero */
void norm(string& str){
	bool zero=true;
	
	for(auto& c:str){
		if(c!='0')
			zero=false;
		if(c!='0' || !zero)
			cout<<c;
	}
}

void input(vl& v,int N){
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
}

void solve(vl& v,int N){
	
}
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
		anc.pb(x);
		x=par[x];
	}
	
	for(int i=0;i<(int)anc.size();i++){
		par[anc[i]]=x;
		sz[anc[i]]=sz[x];
	}
	
	return x;
}

void unite(int a,int b){
	if(find(a)==find(b))
		return;
		
	a=find(a);
	b=find(b);
	
	if(sz[b]>sz[a])
		swap(a,b);
		
	par[b]=a;
	sz[a]+=sz[b];
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V,E,a,b;
    unordered_set<int> cache;
    cin>>V>>E;
    make_par();
    for(int i=1;i<=V;i++)
    	cache.insert(i);
    
    int mx_size=1;
    for(int i=0;i<E;i++){
    	cin>>a>>b;
    	cache.erase(find(a));
    	cache.erase(find(b));
    	unite(a,b);
    	a=find(a);
    	b=find(b);
    	cache.insert(a);
    	cache.insert(b);
    	mx_size=max({mx_size,sz[a],sz[b]});
    	cout<<(int)cache.size()<<" "<<mx_size<<"\n";
    }
    
	
	return 0;	
}
