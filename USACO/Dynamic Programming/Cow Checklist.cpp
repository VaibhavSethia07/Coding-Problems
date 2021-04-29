// Problem: Problem 2. Cow Checklist
// Contest: USACO - USACO 2016 December Contest, Gold
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=670
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

int H,G;
const ll INF=LLONG_MAX;
const int MAXN=1e3+3;
ll h[MAXN][2];
ll g[MAXN][2];
ll dp[MAXN][MAXN][2];
ll dist(int a,int i,int b,int j){
	ll x1=0,x2=0,y1=0,y2=0;
	if(a==0){
		x1=h[i][0];
		y1=h[i][1];
	}
	if(a==1){
		x1=g[i][0];
		y1=g[i][1];
	}
	
	if(b==0){
		x2=h[j][0];
		y2=h[j][1];
	}
	if(b==1){
		x2=g[j][0];
		y2=g[j][1];
	}
	return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}
ll solve(int i,int j,int type){
	if(i==H){
		if(type==1)
			return INF;
		if(j==G)
			return 0;
		return INF;
	}
	
	if(dp[i][j][type]!=-1)
		return dp[i][j][type];
	
	ll sub_ans1=INF,sub_ans2=INF;
	if(type==0){
		if(i<H){
			sub_ans1=solve(i+1,j,0);
			if(sub_ans1!=INF)
				sub_ans1+=dist(0,i,0,i+1);
		}
		if(j<G){
			sub_ans2=solve(i,j+1,1);
			if(sub_ans2!=INF)
				sub_ans2+=dist(0,i,1,j+1);
		}
		
	}else{
		if(i<H){
			sub_ans1=solve(i+1,j,0);
			if(sub_ans1!=INF)
				sub_ans1+=dist(1,j,0,i+1);
		}
		if(j<G){
			sub_ans2=solve(i,j+1,1);
			if(sub_ans2!=INF)
				sub_ans2+=dist(1,j,1,j+1);
		}
	}
	// cout<<sub_ans1<<" "<<sub_ans2<<"\n";
	return dp[i][j][type]=min(sub_ans1,sub_ans2);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	freopen("checklist.in","r",stdin);
	freopen("checklist.out","w",stdout);
	
	cin>>H>>G;
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=H;i++)
		cin>>h[i][0]>>h[i][1];
	
	for(int i=1;i<=G;i++)
		cin>>g[i][0]>>g[i][1];
		
	cout<<solve(1,0,0);
	return 0;	
}
