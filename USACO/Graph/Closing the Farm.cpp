// Problem: Problem 2. Closing the Farm
// Contest: USACO - USACO 2016 US Open Contest, Gold
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=646
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

int V,E,a,b;
const int MAXN=2e5+5;
vector<int> adj[MAXN];
int par[MAXN];
int sz[MAXN];
bool isOpen[MAXN];
void make_par(){
	for(int i=1;i<=V;i++){
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

void unite(int a,int b){
	if(find(a)==find(b))
		return;
		
	a=find(a),b=find(b);
	if(sz[b]>sz[a])
		swap(a,b);
		
	par[b]=a;
	sz[a]+=sz[b];
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("closing.in","r",stdin);
	freopen("closing.out","w",stdout);
    
	cin>>V>>E;
	for(int i=0;i<E;i++){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	vector<int> closedFarm(V);
	vector<int> res(V);
	set<int> rep;
	for(int i=0;i<V;i++)
		cin>>closedFarm[i];
		
	make_par();
	for(int i=V-1;i>=0;i--){
		int u=closedFarm[i];
		isOpen[u]=1;
		rep.insert(find(u));
		for(auto& v:adj[u]){
			if(!isOpen[v])
				continue;
			
			rep.erase(find(v));
			rep.erase(find(u));
			unite(u,v);
			
			rep.insert(find(v));
			rep.insert(find(v));
		}
		res[i]=((int)rep.size()==1);
	}
	
	for(auto& x:res){
		if(x==1)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;	
}
