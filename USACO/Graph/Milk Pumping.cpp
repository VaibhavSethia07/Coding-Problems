// Problem: Problem 1. Milk Pumping
// Contest: USACO - USACO 2019 December Contest, Gold
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=969
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

void input(vl& v,int N){
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
}

const int MAXN=1e3+5;
const ll MAX=1e18;
vector<vector<ll>> adj[MAXN];
ll V,E,a,b,c,fl;
ll dist[MAXN];

bool isPossible(int minF){
	
	for(int i=1;i<=V;i++)
		dist[i]=MAX;
	
	dist[1]=0;
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>>  pq;
	pq.push({0,1});
	
	while(!pq.empty()){
		int u=pq.top().second;
		int dist_u=-pq.top().first;
		pq.pop();
		
		if(dist[u]!=dist_u)
			continue;
			
		for(auto p:adj[u]){
			int v=p[0];
			c=p[1];
			fl=p[2];
			if(fl>=minF){
				if(dist[v]>dist[u]+c){
					dist[v]=dist[u]+c;
					pq.push({-dist[v],v});
				}
			}
		}
	}
	
	return dist[V]!=MAX;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	freopen("pump.in","r",stdin);
	freopen("pump.out","w",stdout);
	
	cin>>V>>E;
	for(int i=0;i<E;i++){
		cin>>a>>b>>c>>fl;
		adj[a].push_back({b,c,fl});
		adj[b].push_back({a,c,fl});
	}
	
	ll ans=0;
	for(int minF=1;minF<=1000;minF++){
		if(isPossible(minF)){
			// cout<<minF<<" "<<(long)(minF*1e6l)/dist[V]<<"\n";
			ans=max(ans,(ll)(minF*1e6l)/dist[V]);
		}
	}
	
	cout<<ans;
	return 0;	
}
