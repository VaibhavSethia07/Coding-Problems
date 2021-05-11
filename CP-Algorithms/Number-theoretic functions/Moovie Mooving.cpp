// Problem: Problem 2. Moovie Mooving
// Contest: USACO - USACO 2015 January Contest, Gold
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=515
// Memory Limit: 256 MB
// Time Limit: 4000 ms

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

void solve(vl& v,int N){
	
}
vector<long> movies[21];
long dur[21];
long dp[(1<<20)+1];
int N,L,slots,slot;
int floor(int id,int last_time){
	int start=0,end=movies[id].size()-1,ans=-1;
	
	while(start<=end){
		int mid=start+(end-start)/2;
		if(movies[id][mid]<=last_time){
			ans=mid;
			start=mid+1;
		}else
			end=mid-1;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
 
	freopen("movie.in","r",stdin);
	freopen("movie.out","w",stdout);
	
	cin>>N>>L;
	for(int i=0;i<N;i++){
		cin>>dur[i];
		cin>>slots;
		for(int j=0;j<slots;j++){
			cin>>slot;
			movies[i].push_back(slot);
		}
	}
	
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	int ans=-1;
	for(int mask=0;mask<(1<<N);mask++){
		if(dp[mask]<0)
			continue;
		
		if(dp[mask]>=L){
			int cnt=__builtin_popcount(mask);
			if(ans==-1 || ans>cnt)
				ans=cnt;
		}
		
		for(int i=0;i<N;i++){
			if(mask&(1<<i))
				continue;
			int ind=floor(i,dp[mask]);
			if(ind==-1){
				continue;
			}
			dp[mask|(1<<i)]=max(dp[mask|(1<<i)],movies[i][ind]+dur[i]);
		}
	}

	cout<<ans;
	return 0;	
}
