// Problem: D. Magic Numbers
// Contest: Codeforces - Educational Codeforces Round 8
// URL: https://codeforces.com/contest/628/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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

string num;
ll m,d;
ll dp[2005][2005][2][2];
void define_limit(string& x){
	memset(dp,-1,sizeof(dp));
	num="";
	num=x;
}

ll solve(int pos,ll x,bool flag,bool nonzero){
	if(pos==(int)num.length()){
		if(nonzero){
			return (x%m)==0;
		}
		return 0;
	}
	
	if(dp[pos][x][flag][nonzero]!=-1)
		return dp[pos][x%m][flag][nonzero];
	
	int limit=9;
	if(flag)
		limit=(num[pos]-'0');
	ll res=0;
	if((pos%2)==1){
		if(d<=limit)
			res+=solve(pos+1,(x*10+d)%m,flag&(d==limit),d||nonzero);
		res%=mod;
	}else{
		for(int dig=0;dig<=limit;dig++){
			if(dig==d)
				continue;
			res+=solve(pos+1,(x*10+dig)%m,flag&(dig==limit),dig||nonzero);
			res%=mod;
		}
	}	
	return dp[pos][x%m][flag][nonzero]=(res%mod);
	
}

int main(){
	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    
	string a,b;
	cin>>m>>d>>a>>b;
	
	define_limit(b);
	ll y=solve(0,0,1,0);
	
	ll x=0;
	
	int A=(int)a.length();
	if(a[A-1]!='0'){
		char ch=a[A-1];
		ch--;
		a[A-1]=ch;
	}else{
		int i=A-1;
		while(i>=0 && a[i]=='0'){
			i--;
		}
		char ch=a[i];
		ch--;
		a[i++]=ch;
		while(i<A)
			a[i++]='9';
	}
	
	
	define_limit(a);
	x=solve(0,0,1,0);
	
	y-=x;
	if(y<0){
		y+=mod;
		y%=mod;
	}
	cout<<y<<"\n";
	
	return 0;	
}
