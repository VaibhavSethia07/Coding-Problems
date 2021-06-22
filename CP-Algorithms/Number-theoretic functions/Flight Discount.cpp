// Problem: Flight Discount
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1195
// Memory Limit: 512 MB
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

// Method 1

const int MAXN=1e5+5;
int V,E,a,b,w;
vector<pair<ll,ll>> graph[2][MAXN];
ll dist[2][MAXN];

void dijkstra(int way){
	
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>> pq;
	
	if(way){
		dist[way][V]=0;
		pq.push({0,V});
	}
	else{
		dist[way][1]=0;
		pq.push({0,1});
	}
	
	while(!pq.empty()){
		ll u=pq.top().second;
		ll dist_u=-pq.top().first;
		pq.pop();
		
		if(dist_u==1e18 || dist_u!=dist[way][u])
			continue;
		
		for(auto p:graph[way][u]){
			ll v=p.first;
			ll w=p.second;
			
			if(dist[way][v]>=dist[way][u]+w){
				dist[way][v]=dist[way][u]+w;
				pq.push({-dist[way][v],v});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin>>V>>E;
	vector<vector<int>> edges(E);
	
	for(int i=1;i<=V;i++){
		dist[0][i]=1e18;
		dist[1][i]=1e18;
	}
	
	for(int i=0;i<E;i++){
		cin>>a>>b>>w;
		edges[i]={a,b,w};
		
		graph[0][a].push_back({b,w});
		graph[1][b].push_back({a,w});
	}
	
	dijkstra(0);
	dijkstra(1);
	
	ll cost=1e18;
	for(int i=0;i<E;i++){
		a=edges[i][0],b=edges[i][1],w=edges[i][2];
		if(dist[0][a]!=1e18 && dist[1][b]!=1e18)
			cost=min(cost,dist[0][a]+1ll*w/2+dist[1][b]);
	}
	
	cout<<cost<<"\n";

	return 0;	
}

// Method 2
const int MAXN=1e5+5;
int V,E,a,b,w;
vector<pair<ll,ll>> graph[MAXN];
ll dist[MAXN][2];

struct Item{
	int city;
	ll cost;
	bool discount;
	
	Item(int _city, ll _cost, bool _discount){
		city = _city;
		cost = _cost;
		discount = _discount;
	}
	
	inline const bool operator<(const Item& item2) const {
		// Without comments still works
		// if(discount == item2.discount)
			return cost>item2.cost;
		// return discount>item2.discount;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>V>>E;
    
    for(int i=0;i<E;i++){
    	cin>>a>>b>>w;
    	graph[a].push_back({b,w});
    }
    
    for(int i=1;i<=V;i++){
    	dist[i][0]=1e18;
    	dist[i][1]=1e18;
    }
    
    priority_queue<Item> pq;
    
    pq.push({1,0,false});
    
    while(!pq.empty()){
    	int u=pq.top().city;
    	ll dist_u=pq.top().cost;
    	bool discount_u=pq.top().discount;
    	pq.pop();
    	
    	// if(u==V && discount_u){
    		// cout<<dist_u<<"\n";
    		// return 0;
    	// }
    	
    	for(auto p:graph[u]){
    		ll v=p.first;
    		ll w=p.second;
    		
	    	// If I do not apply discount, then from whatever state I reached here is fine
	    	if(dist[v][discount_u]>dist_u+w){
	    		dist[v][discount_u]=dist_u+w;
	    		pq.push({v,dist[v][discount_u],discount_u});
	    	}
	    	
	    	// If I apply discount, at current flight,then  I must not have applied discount before
	    	if(!discount_u){
	    		if(dist[v][true]>dist_u+w/2){
		    		dist[v][true]=dist_u+w/2;
		    		pq.push({v,dist[v][true],true});
		    	}
	    	}
    	}
    }
    
    cout<<min(dist[V][0],dist[V][1]);
}

