// Problem: Problem 2. Hoof, Paper, Scissors
// Contest: USACO - USACO 2017 January Contest, Gold
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=694
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
const int MAXN=1e5+5;
int fj_cards[MAXN];
char cards[3]={'H','P','S'};
int match[3][3]={{0,1,0},{0,0,1},{1,0,0}};
int n,k;

int dp[MAXN][3][21];
void input(int n){
	char x;
	for(int i=0;i<n;i++){
		cin>>x;
		if(x=='H')
			fj_cards[i]=0;
		else if(x=='P')
			fj_cards[i]=1;
		else
			fj_cards[i]=2;
	}
}

int solve(int move,int prev,int k){
	if(move==n)
		return 0;
	if(prev!=-1 && dp[move][prev][k]!=-1)
		return dp[move][prev][k];
	
	int mx=0;
	for(int i=0;i<3;i++){
		if(prev==-1 || cards[i]==cards[prev])
			mx=max(mx,match[fj_cards[move]][i]+solve(move+1,i,k));
		else if(cards[i]!=cards[prev] && k>0)
			mx=max(mx,match[fj_cards[move]][i]+solve(move+1,i,k-1));
	}
	return dp[move][prev][k]=mx;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	// for getting input from input.txt
	freopen("hps.in", "r", stdin);
	// for getting output from output.txt
	freopen("hps.out", "w", stdout);
	
	cin>>n>>k;
	
	input(n);
	memset(dp,-1,sizeof(dp));
	cout<<solve(0,-1,k);
	
	return 0;	
}
