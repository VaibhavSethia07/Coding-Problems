// Problem: E. Let's Go Rolling!
// Contest: Codeforces - School Personal Contest #1 (Winter Computer School 2010/11) - Codeforces Beta Round #38 (ACM-ICPC Rules)
// URL: https://codeforces.com/problemset/problem/38/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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
const int MAXN=3e3+5;
vector<pair<long,long>> points(MAXN);
long dp[MAXN][MAXN];
int n;
void input(){
	for(int i=0;i<n;i++){
		cin>>points[i].f>>points[i].s;
	}
	
	sort(points.begin(),points.begin()+n);

}

long solve(int i,int prev){
	if(i==n)
		return 0;
	if(dp[i][prev]!=-1)
		return dp[i][prev];	
	
	/* If I pin the current marble, then I pay c[i] and for the next marble this will be the last pinned marble*/
	long ans1=points[i].s+solve(i+1,i);
	/* If I do not pin the current marble, then it rolls towards the previously pinned marble and cost it the length of the path traversed */ 
	long ans2=points[i].f-points[prev].f+solve(i+1,prev);
	return dp[i][prev]=min(ans1,ans2);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
   	input();
   	
   	memset(dp,-1,sizeof(dp));
   	cout<<points[0].s+solve(1,0);
	
	return 0;	
}
