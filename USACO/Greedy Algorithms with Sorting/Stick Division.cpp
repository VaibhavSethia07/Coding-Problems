
// Problem: Stick Divisions
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1161
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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
	int X,N,a,b;
	cin>>X>>N;
	priority_queue<int> pq;
	for(int i=0;i<N;i++){
		cin>>a;
		a*=-1;
		pq.push(a);	
	}
	long ans=0;
	while(pq.size()!=1){
		a=pq.top();
		pq.pop();
		b=pq.top();
		pq.pop();
		ans+=-(a+b);
		pq.push(a+b);
	}
	cout<<ans<<"\n";
	return 0;	
}
