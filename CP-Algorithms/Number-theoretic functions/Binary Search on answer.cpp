// Problem: Problem C: Game of Distribution
// Contest: CodeDrills - Game of Codes
// URL: https://codedrills.io/contests/game-of-codes/problems/problem-c-game-of-distribution
// Memory Limit: 256 MB
// Time Limit: 1000 ms

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

void input(vl& v,int N){
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
}

bool solve(long mid,long n1,long n2,long x,long y){
	long c1=mid/x;
	long c2=mid/y;
	long common=mid/(x*y);
	
	// Alice should get
	long a=min(n1,c2-common);
	// Bob should get
	long b=min(n2,c1-common);
	// Rest of the numbers they both can take
	long remaining=mid-(c1+c2-common);
	long need=n1+n2-(a+b);
	return need<=remaining;
}

const long MAXN=1e18+1;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
	long T,x,y,n1,n2;
	cin>>T;
	while(T--){
		cin>>n1>>n2>>x>>y;
		
		long start=1,end=MAXN,ans=MAXN;
		while(start<=end){
			long mid=start+(end-start)/2;
			if(solve(mid,n1,n2,x,y)){
				ans=mid;
				end=mid-1;
			}else
				start=mid+1;
		}
		cout<<ans<<"\n";
	}
	
	return 0;	
}
