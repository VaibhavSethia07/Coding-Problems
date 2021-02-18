// Problem: F. Equalize the Array
// Contest: Codeforces - Codeforces Round #702 (Div. 3)
// URL: https://codeforces.com/contest/1490/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

void input(vl& v,int N){
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
}

void solve(vl& v,int N){
	map<long,long> cache;
	
	for(int i=0;i<N;i++){
		cache[v[i]]++;
	}
	
	vector<long> res;
	for(auto& p:cache){
		res.pb(p.s);
		
	}
		
	sort(all(res));
	
	long ans=0;
	int M=(int)res.size();
	
	long med=res[M/2];
	
	for(int i=0;i<M;i++){
		if(res[i]<med)
			ans+=res[i];
		else
			ans+=res[i]-med;
	}
	
	long mn=0;
	for(int i=0;i<M;i++)
		mn+=res[i]-res[0];
	ans=min(mn,ans);
	mn=0;
	for(int i=0;i<M;i++){
		if(res[i]!=res[M-1])
			mn+=res[i];
	}
	
	cout<<min(ans,mn)<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		vl v(N);
		input(v,N);
		solve(v,N);
	}
	
	return 0;	
}
