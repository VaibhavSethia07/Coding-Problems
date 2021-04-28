// Problem: Problem 1. Snakes
// Contest: USACO - USACO 2019 US Open Contest, Gold
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=945
// Memory Limit: 256 MB
// Time Limit: 4000 ms

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

int n,k;
const int MAXN=405;
const long MAX=1e9+5;
long snakes[MAXN];
long dp[MAXN][MAXN];
void input(int n){
	for(int i=0;i<n;i++){
		cin>>snakes[i];
	}
}

long go(int end,int grps){
	if(end>=n)
		return 0;
	if(grps==0)
		return MAX;
	if(dp[end][grps]!=-1)
		return dp[end][grps];
	long mx=snakes[end];
	long sum=0;
	long ans=MAX;
	for(int i=end;i<n;i++){
		mx=max(mx,snakes[i]);
		sum+=snakes[i];
		long sub_ans=go(i+1,grps-1);
		if(sub_ans!=MAX){
			sub_ans+=mx*(i-end+1)-sum;
			ans=min(ans,sub_ans);
		}
	}
	return dp[end][grps]=ans;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	
	cin>>n>>k;
	
	input(n);
	memset(dp,-1,sizeof(dp));
	cout<<go(0,k+1);
	return 0;	
}
