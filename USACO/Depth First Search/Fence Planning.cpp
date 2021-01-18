/*
Farmer John's N cows, conveniently numbered 1…N (2≤N≤105), have a complex social structure revolving around "moo networks" --- smaller groups of cows that communicate within their group but not with other groups.
Each cow is situated at a distinct (x,y) location on the 2D map of the farm, and we know that M pairs of cows (1≤M<105) moo at each-other. Two cows that moo at each-other belong to the same moo network.

In an effort to update his farm, Farmer John wants to build a rectangular fence, with its edges parallel to the x and y axes. Farmer John wants to make sure that at least one moo network is completely enclosed by the fence (cows on the boundary of the rectangle count as being enclosed). Please help Farmer John determine the smallest possible perimeter of a fence that satisfies this requirement. It is possible for this fence to have zero width or zero height.

INPUT FORMAT (file fenceplan.in):
The first line of input contains N and M. The next N lines each contain the x and y coordinates of a cow (nonnegative integers of size at most 108). The next M lines each contain two integers a and b describing a moo connection between cows a and b. Every cow has at least one moo connection, and no connection is repeated in the input.
OUTPUT FORMAT (file fenceplan.out):
Please print the smallest perimeter of a fence satisfying Farmer John's requirements.
SAMPLE INPUT:
7 5
0 5
10 5
5 0
5 10
6 7
8 6
8 4
1 2
2 3
3 4
5 6
7 6
SAMPLE OUTPUT:
10
Problem credits: Brian Dean

################################################################################Solution###########################################################################################
*/

// Problem: Problem 3. Fence Planning
// Contest: USACO - USACO 2019 US Open Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=944
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
vector<bool> vis;
const int MAXN=100005;
int V,E,a,b;
int x[MAXN],y[MAXN];
void input(){
	for(int i=0;i<V;i++){
		cin>>x[i]>>y[i];
	}
	
	for(int i=0;i<E;i++){
		cin>>a>>b;
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
}

void dfs(int u,int& xmax,int& xmin,int& ymax,int& ymin){
	vis[u]=true;
	xmax=max(xmax,x[u]);
	xmin=min(xmin,x[u]);
	ymax=max(ymax,y[u]);
	ymin=min(ymin,y[u]);
	for(auto& v:g[u]){
		if(!vis[v])
			dfs(v,xmax,xmin,ymax,ymin);
	}
}

int main(){
	freopen("fenceplan.in","r",stdin);
	freopen("fenceplan.out","w",stdout);
	cin>>V>>E;
	g.resize(V);
	vis.resize(V);
	
	input();
	long ans=LONG_MAX;
	int xmax,xmin,ymax,ymin,xx,yy;
	for(int i=0;i<V;i++){
		xmax=0;
		xmin=INT_MAX;
		ymax=0;
		ymin=INT_MAX;
		if(!vis[i]){
			dfs(i,xmax,xmin,ymax,ymin);
			xx=xmax-xmin;
			yy=ymax-ymin;
			if(xx==0)
				ans=min(ans,1l*yy);
			else if(yy==0)
				ans=min(ans,1l*xx);
			else
				ans=min(ans,2l*(xx+yy));
		}
	}
	cout<<ans<<"\n";
	
	return 0;	
}
