
// Problem: B - Distance
// Contest: AtCoder - AtCoder Beginner Contest 174
// URL: https://atcoder.jp/contests/abc174/tasks/abc174_b
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

int main(){
	long long n,d,x,y;
	cin>>n>>d;
	long ans=0;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		x*=x;
		y*=y;
		x+=y;
		double s=sqrt(x);
		if(s<=d)
			ans++;
	}
	cout<<ans<<"\n";
	
	return 0;	
}
