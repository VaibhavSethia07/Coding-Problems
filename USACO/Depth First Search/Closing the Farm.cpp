/*
The farm consists of N barns connected with M bidirectional paths between some pairs of barns (1≤N,M≤3000). To shut the farm down, FJ plans to close one barn at a time. When a barn closes, all paths adjacent to that barn also close, and can no longer be used.

FJ is interested in knowing at each point in time (initially, and after each closing) whether his farm is "fully connected" -- meaning that it is possible to travel from any open barn to any other open barn along an appropriate series of paths. Since FJ's farm is initially in somewhat in a state of disrepair, it may not even start out fully connected.

INPUT FORMAT (file closing.in):
The first line of input contains N and M. The next M lines each describe a path in terms of the pair of barns it connects (barns are conveniently numbered 1…N). The final N lines give a permutation of 1…N describing the order in which the barns will be closed.
OUTPUT FORMAT (file closing.out):
The output consists of N lines, each containing "YES" or "NO". The first line indicates whether the initial farm is fully connected, and line i+1 indicates whether the farm is fully connected after the ith closing.
SAMPLE INPUT:
4 3
1 2
2 3
3 4
3
4
1
2
SAMPLE OUTPUT:
YES
NO
YES
YES

###################################################################################Solution########################################################################################
*/

// Problem: Problem 3. Closing the Farm
// Contest: USACO - USACO 2016 US Open Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=644
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

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
		int cnt=1;
		if(N%2==0){
			while((N%2)==0){
				N/=2;
				cnt++;
			}
			d[div]=cnt;
		}
	}
	static array<int,8> increments = {4,2,4,2,4,6,2,6};
	int i=0;
	for(ll div=7;div*div<=N;div+=increments[i++]){
		if((N%div)==0){
			int cnt=1;
			while((N%i)==0){
				N/=i;
				cnt++;
			}
			d[i]=cnt;
		}
		if(i==8)
			i=0;
	}
	if(N>1)
		d[N]=2;
}

vector<vector<int>> g;
int V,E,a,b;
int vis[3000];
void input(vl& v,int N){
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
}

void init(int u){
	vis[u]=0;
	for(auto& v:g[u]){
		if(vis[v]!=0)
			init(v);
	}
}

void dfs(int u){
	vis[u]=1;
	for(auto& v:g[u]){
		if(vis[v]==0)
			dfs(v);
	}
}

bool check(int x){
	for(int i=0;i<V;i++){
		if(vis[i]==x)
			return false;
	}
	return true;
}


int main(){
	freopen("closing.in","r",stdin);
	freopen("closing.out","w",stdout);
	cin>>V>>E;
	g.resize(V);
	for(int i=0;i<E;i++){
		cin>>a>>b;
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	for(int i=0;i<V;i++)
		vis[i]=-1;
	
	init(0);
	cout<<(check(-1)?"YES\n":"NO\n");
	
	for(int i=0;i<V-1;i++){
		cin>>a;
		a--;
		for(int j=0;j<V;j++){
			if(vis[j]==1)
				vis[j]=0;
		}
		vis[a]=-1;
		for(auto& v:g[a]){
			int ind;
			for(int j=0;j<(int)g[v].size();j++){
				if(g[v][j]==a){
					ind=j;
					break;
				}
			}
			g[v].erase(g[v].begin()+ind);
		}
		for(int j=0;j<V;j++){
			if(vis[j]!=-1){
				dfs(j);
				break;
			}
		}
		cout<<(check(0)?"YES\n":"NO\n");
	}
	return 0;	
}
