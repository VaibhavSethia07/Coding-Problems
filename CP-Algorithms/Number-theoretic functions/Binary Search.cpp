// Problem: C. Binary Search
// Contest: Codeforces - Codeforces Round #678 (Div. 2)
// URL: https://codeforces.com/contest/1436/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms

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

ll cntBig=0,cntSmall=0;
void solve(ll N,ll P){
	ll start=0,end=N;
	
	while(start<end){
		ll mid=(end+start)/2;
		if(mid<=P){
			if(mid!=P)
				cntSmall++;
			start=mid+1;
		}else{
			cntBig++;
			end=mid;	
		}
	}
	
}
const int MAXN=1001;
ll fact[MAXN];
void factorial(){
	fact[0]=1;
	fact[1]=1;
	
	for(int i=2;i<MAXN;i++){
		fact[i]=(i*fact[i-1])%mod;;
		fact[i]%=mod;
		
	}
}

ll modExp(ll a,ll b){
	ll result=1;
	
	while(b>0){
		if(b&1)
			result=(result*a)%mod;
		b>>=1;
		a=(a*a)%mod;
	}
	return result;
}

ll nck(ll N,ll K){
	if(N<K)
		return 0; 
	// N!/(N-K)!*(K!);
	ll num=fact[N];
	ll denom=fact[N-K]*fact[K];
	denom%=mod;
	ll denom_inv=modExp(denom,mod-2);
	
	num*=denom_inv;
	num%=mod;
	return num;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	factorial();
	ll N,X,P;
	cin>>N>>X>>P;
	
	if(N==1){
		cout<<1<<"\n";
		return 0;
	}

	solve(N,P);
	cerr<<cntSmall<<" "<<cntBig<<"\n";
	ll hasSmall=X-1;
	ll hasBig=N-X;
	
	ll small=nck(hasSmall,cntSmall)*fact[cntSmall];
	small%=mod;
	ll big=nck(hasBig,cntBig)*fact[cntBig];
	big%=mod;
	
	ll ans=small*big;
	ans%=mod;
	
	ans*=fact[N-cntSmall-cntBig-1];
	ans%=mod;
	cout<<ans;
	
	return 0;	
}
