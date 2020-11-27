// Problem: Static Range Sum
// Contest: Library Checker
// URL: https://judge.yosupo.jp/problem/static_range_sum
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
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
	int N,Q;
	cin>>N>>Q;
	long long int arr[N];
	for(int a=0;a<N;a++)
		cin>>arr[a];
		
	for(int a=1;a<N;a++)
		arr[a]=arr[a-1]+arr[a];
	for(int a=0;a<Q;a++){
		int l,r;
		cin>>l>>r;
		if(l==0)
			cout<<arr[r-1]<<"\n";
		else
			cout<<arr[r-1]-arr[l-1]<<"\n";
	}
	return 0;
	
}
