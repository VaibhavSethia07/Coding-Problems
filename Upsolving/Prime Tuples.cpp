
// Problem: Prime Tuples
// Contest: CodeChef - January Cook-Off 2021 Division 3
// URL: https://www.codechef.com/COOK126C/problems/PTUPLES
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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


void solve(){

}
const int MAXN=1000005;
int main(){
	vector<bool> seive(MAXN,1);
	vector<ll> res;
	vector<ll> ans(MAXN,0);
	set<ll> cache;
	
	seive[0]=0;
	seive[1]=0;
	for(int i=2;i<MAXN;i++){
		if(seive[i]){
			res.pb(i);
			cache.insert(i);
			for(int j=2*i;j<MAXN;j+=i){
				seive[j]=0;
			}
		}
	}		
	
	for(int i=0;i<(int)res.size();i++){
		if(cache.find(res[i]+2)!=cache.end()){
			ans[res[i]+2]++;
		}
	}

	for(int i=1;i<MAXN;i++){
		ans[i]+=ans[i-1];
	}
	
	int T;
	ll N;
	cin>>T;
	solve();
	

	while(T--){
		cin>>N;
		cout<<ans[N]<<"\n";
	}
	return 0;	
}
