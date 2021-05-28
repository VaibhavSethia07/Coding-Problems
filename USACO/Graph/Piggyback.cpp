// Problem: Problem 1. Piggyback
// Contest: USACO - USACO 2014 December Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=491
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

long B,E,P,N,M,a,b;
const int MAXN=40005;
vector<int> adj[MAXN];
bool vis[MAXN];
long bessie_to_com[MAXN];
long elsie_to_com[MAXN];
long com[MAXN];

void common_bfs(int u,int cow){
	queue<int> q;
	memset(vis,0,sizeof(vis));
	
	q.push(u);
	vis[u]=1;
	if(!cow)
		bessie_to_com[u]=0;
	else
		elsie_to_com[u]=0;
	while(!q.empty()){
		u=q.front();
		q.pop();
		
		for(auto& v:adj[u]){
			if(!vis[v]){
				vis[v]=1;
				if(!cow)
					bessie_to_com[v]=bessie_to_com[u]+B;
				else
					elsie_to_com[v]=elsie_to_com[u]+E;
				q.push(v);
			}
		}
	}

}

void bfs(int u,long C){
	queue<int> q;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=N;i++){
		com[i]=1e9;
	}
	q.push(u);
	vis[u]=1;
	com[u]=0;
	
	while(!q.empty()){
		int u=q.front();
		q.pop();
		
		for(auto& v:adj[u]){
			if(!vis[v]){
				vis[v]=1;
				com[v]=com[u]+C;
				q.push(v);
			}
		}
	}
}

long D0[MAXN];
long D1[MAXN];
long D2[MAXN];
vector<long> travel(int u){
	queue<int> q;
	vector<long> dist(N+1,1e9);
	dist[u]=0;
	q.push(u);
	while(!q.empty()){
		u=q.front();
		q.pop();
		
		for(auto& v:adj[u]){
			if(dist[v]==1e9){
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
	}
	return dist;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	freopen("piggyback.in","r",stdin);
	freopen("piggyback.out","w",stdout);
	
	cin>>B>>E>>P>>N>>M;
	
	for(int i=0;i<M;i++){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	long cost=LONG_MAX;
	if(E+B>P){
		for(int i=1;i<=N;i++){
			bessie_to_com[i]=1e9;
			elsie_to_com[i]=1e9;
		}
		
		common_bfs(1,0);
		common_bfs(2,1);
		bfs(N,P); 
		long sub_cost=LONG_MAX;
		int mn=1;
		for(int i=1;i<=N;i++){
			long bessie=bessie_to_com[i],elsie=elsie_to_com[i];
			long sub_cost=bessie+elsie+com[i];
			cost=min(cost,sub_cost);
		}
		
	}else{
		bfs(1,B);
		long bessie=com[N];
		bfs(2,E);
		long elsie=com[N];
		cost=min(cost,bessie+elsie);
	}
	cout<<cost;
	
	/* Editorial Solution */
	cin>>E>>B>>P>>N>>M;
	
	for(int i=0;i<M;i++){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	vector<long> d0=travel(1);
	vector<long> d1=travel(2);
	vector<long> d2=travel(N);
	
	long ans=LONG_MAX;
	for(int i=1;i<=N;i++){
		ans=min(ans,d0[i]*E+d1[i]*B+d2[i]*P);
	}
	cout<<ans;
	return 0;	
}
