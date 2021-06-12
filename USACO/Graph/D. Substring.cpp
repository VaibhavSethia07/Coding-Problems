// Problem: D. Substring
// Contest: Codeforces - Codeforces Round #460 (Div. 2)
// URL: https://codeforces.com/contest/919/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms

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

const int MAXN=3e5+5;
vector<int> graph[MAXN];
int in_degree[MAXN];
char nodes[MAXN];
long dp[MAXN][26];
int V,E,a,b;

void input(vl& v,int N){
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
}

void solve(vl& v,int N){
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin>>V>>E;
	for(int i=1;i<=V;i++){
		cin>>nodes[i];
	}
	
	for(int i=1;i<=E;i++){
		cin>>a>>b;
		graph[a].push_back(b);
		in_degree[b]++;
	}
	
	queue<int> Q;
	for(int i=1;i<=V;i++){
		if(in_degree[i]==0){
			dp[i][nodes[i]-'a']=1;
			Q.push(i);
		}
	}
	int cnt=0;
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		cnt++;
		for(auto& v:graph[u]){
			in_degree[v]--;
			if(in_degree[v]==0)
				Q.push(v);
			for(int i=0;i<26;i++)
				dp[v][i]=max(dp[v][i],dp[u][i]+1l*((nodes[v]-'a')==i));
		}
	}
	
	if(cnt!=V)
		cout<<-1;
	else{
		long ans=0;
		for(int i=1;i<=V;i++){
			for(int j=0;j<26;j++)
				ans=max(ans,dp[i][j]);
		}
		cout<<ans<<"\n";
	}
		
	return 0;	
}
