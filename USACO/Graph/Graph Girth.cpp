// Problem: Graph Girth
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1707
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

int V,E,a,b;
const int MAXN=2505;
vector<int> adj[MAXN];
int parent[MAXN];
int dist[MAXN];
bool vis[MAXN];

int bfs(int src){
	memset(vis,0,sizeof(vis));
	memset(parent,0,sizeof(parent));
	memset(dist,0,sizeof(dist));
	queue<int> q;
	q.push(src);
	vis[src]=1;
	int result=INT_MAX;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto& v:adj[u]){
			if(!vis[v]){
				vis[v]=1;
				q.push(v);
				dist[v]=dist[u]+1;
				parent[v]=u;
			}else if(v!=parent[u]){
				// Presence of cycle. We need to find the common ancestor
				// cout<<"Original: "<<u<<" "<<v<<"\n";
				// int x=u,y=v;
				// if(dist[x]<dist[y])
					// swap(x,y);
				// while(dist[x]!=dist[y]){
					// x=parent[x];
				// }
				// while(x!=y){
					// x=parent[x],y=parent[y];
				// }
				// cout<<x<<" "<<y<<"\n";
				result=min(result,dist[u]+dist[v]+1-2*dist[src]);
			}
		}
	}
	
	return result;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin>>V>>E;
	for(int i=0;i<E;i++){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	int result=INT_MAX;
	for(int i=1;i<=V;i++){
		result=min(result,bfs(i));

	}
	
	if(result!=INT_MAX)
		cout<<result<<"\n";	
	else
		cout<<-1<<"\n";
	return 0;	
}
