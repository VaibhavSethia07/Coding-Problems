/*
Farmer John's N cows (1≤N≤200) want to organize an emergency "moo-cast" system for broadcasting important messages among themselves.
Instead of mooing at each-other over long distances, the cows decide to equip themselves with walkie-talkies, one for each cow. These walkie-talkies each have a limited transmission radius -- a walkie-talkie of power P can only transmit to other cows up to a distance of P away (note that cow A might be able to transmit to cow B even if cow B cannot transmit back, due to cow A's power being larger than that of cow B). Fortunately, cows can relay messages to one-another along a path consisting of several hops, so it is not necessary for every cow to be able to transmit directly to every other cow.

Due to the asymmetrical nature of the walkie-talkie transmission, broadcasts from some cows may be more effective than from other cows in their ability to reach large numbers of recipients (taking relaying into account). Please help the cows determine the maximum number of cows that can be reached by a broadcast originating from a single cow.

INPUT FORMAT (file moocast.in):
The first line of input contains N.
The next N lines each contain the x and y coordinates of a single cow ( integers in the range 0…25,000) followed by p, the power of the walkie-talkie held by this cow.

OUTPUT FORMAT (file moocast.out):
Write a single line of output containing the maximum number of cows a broadcast from a single cow can reach. The originating cow is included in this number.
SAMPLE INPUT:
4
1 3 5
5 4 3
7 2 1
6 1 1
SAMPLE OUTPUT:
3
In the example above, a broadcast from cow 1 can reach 3 total cows, including cow 1.

Problem credits: Brian Dean

####################################################################################Solution#######################################################################################
*/

// Problem: Problem 3. Moocast
// Contest: USACO - USACO 2016 December Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=668
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
int x[200],y[200],p[200];
int g[200][200];
vector<bool> vis;
int N;
int dfs(int u){
	vis[u]=true;
	int sub_ans=0;
	for(int v=0;v<N;v++){
		if(!vis[v] && g[u][v]){
			sub_ans+=1+dfs(v);
		}
	}
	return sub_ans;
}

int main(){
	freopen("moocast.in","r",stdin);
	freopen("moocast.out","w",stdout);
	
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>x[i]>>y[i]>>p[i];
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			long dis=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			if(dis<=(long)p[i]*p[i])
				g[i][j]=1;
		}
	}
	int ans=0;
	for(int i=0;i<N;i++){
		vis.clear();
		vis.resize(N);
		ans=max(ans,dfs(i)+1);
	}
	cout<<ans<<"\n";
	return 0;	
}
