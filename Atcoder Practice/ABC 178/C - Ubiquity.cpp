
// Problem: C - Ubiquity
// Contest: AtCoder - AtCoder Beginner Contest 178
// URL: https://atcoder.jp/contests/abc178/tasks/abc178_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using db = double;
using str = string;

using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vl = vector<ll>;

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

#define FOR(i,a,b) for (int i = (a); i<(b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for(int i = (b)-1; i>=(a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

long long binExpo(long long a,long long b,long long mod){
	if(b==0)
		return 1;
	if(b==1)
		return a%mod;
	if((b&1)==1)
		return ((a%mod)*(binExpo((a*a)%mod,b/2,mod)%mod))%mod;
	return binExpo((a*a)%mod,b/2,mod)%mod;
}

int main(){
	ll N;
	cin>>N;
	ll mod=1e9+7;
	ll res=(binExpo(10,N,mod)-2*binExpo(9,N,mod)+binExpo(8,N,mod))%mod;
	res=(res+mod)%mod;
	cout<<res<<"\n";
	return 0;	
}
