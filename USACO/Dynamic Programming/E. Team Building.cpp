// Problem: E. Team Building
// Contest: Codeforces - CodeCraft-20 (Div. 2)
// URL: https://codeforces.com/contest/1316/problem/E
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

void input(vl& v,int N){
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
}
const int MAXN=1e5+5;

ll dp[MAXN][(1<<7)+1];
int a[MAXN];
int ind[MAXN];
int skill[MAXN][7];
int n,p,k;

bool cmp(ll p,ll q){
	return a[p]>a[q];
}

ll solve(vector<vector<ll>>& play_strength,int mask,int last){
	if(mask==0 && k==0)
		return 0;
	if(dp[mask][last]!=-1)
		return dp[mask][last];
			
	ll sub_ans1=0,sub_ans2=0,ans=0;
	for(int i=last;i<n;i++){
		for(int j=0;j<=p && mask>0;j++){
			int players=p-__builtin_popcount(mask);
			if(j==0 && last-players<k){
				sub_ans2=play_strength[i][0]+solve(play_strength,mask,i+1);
			}
			else if(j>=1 && (mask&(1<<(j-1)))){
				sub_ans1=play_strength[i][j]+solve(play_strength,mask^(1<<(j-1)),i+1);
			}
		}
		ans=max({ans,sub_ans1,sub_ans2});
	}
	return dp[mask][last]=ans;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    /* This solution gives TLE */
	cin>>n>>p>>k;
	vector<vector<ll>> play_strength(n,vector<ll>(9));
	for(int i=0;i<n;i++){		
		cin>>play_strength[i][0];
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=p;j++){
			cin>>play_strength[i][j];
		}
	}
	sort(all(play_strength),greater<vector<ll>>());
	memset(dp,-1,sizeof(dp));
	cout<<solve(play_strength,(1<<p)-1,0);
	
	/* Editorial Solution */
	cin>>n>>p>>k;
	
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<p;j++)
			cin>>skill[i][j];
	}
	
	for(int i=1;i<=n;i++)
		ind[i]=i;
		
	sort(ind+1,ind+n+1,cmp);
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	for(ll i=1;i<=n;i++){
		ll x=ind[i];
		for(ll mask=0;mask<(1<<p);mask++){
			int set_bits=__builtin_popcount(mask);
			if(i-1-set_bits<k){
				if(dp[i-1][mask]!=-1)
					dp[i][mask]=dp[i-1][mask]+a[x];
			}else{
				if(dp[i-1][mask]!=-1)
					dp[i][mask]=dp[i-1][mask];
			}
			
			for(int j=0;j<p;j++){
				if(mask&(1<<j) && dp[i-1][mask^(1<<j)]!=-1){
					ll sub_ans=skill[x][j]+dp[i-1][mask^(1<<j)];
					if(sub_ans>dp[i][mask])
						dp[i][mask]=sub_ans;
				}	
			}	
		}
	}
	cout<<dp[n][(1<<p)-1];
	return 0;	
}
