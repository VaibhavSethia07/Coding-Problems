
// Problem: C - Collinearity
// Contest: AtCoder - AtCoder Beginner Contest 181
// URL: https://atcoder.jp/contests/abc181/tasks/abc181_c
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
	int N,x1,y1,x2,y2,x3,y3;
	cin>>N;
	vector<pair<int,int>> v(N);
	map<double,int> slopes;
	for(int i=0;i<N;i++){
		int x,y;
		cin>>x>>y;
		v[i]={x,y};
	}
	
	for(int i=0;i<N-1;i++){
		x1=v[i].f;
		y1=v[i].s;
		for(int j=i+1;j<N;j++){
			x2=v[j].f;
			y2=v[j].s;
			for(int k=j+1;k<N;k++){
				x3=v[k].f;
				y3=v[k].s;
				
				int lhs = (y2-y1)*(x3-x2);
				int rhs = (y3-y2)*(x2-x1);
				if(lhs==rhs){
					cout<<"Yes\n";
					return 0;
				}
			}
		}
	}
	cout<<"No\n";
	
	return 0;	
}
