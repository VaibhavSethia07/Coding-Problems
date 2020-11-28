
// Problem: Forest Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1652
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
	int N,Q;
	cin>>N>>Q;
	
	long long forest[N+1][N+1];
	for(int i=0;i<=N;i++){
		forest[0][i]=0;
		forest[i][0]=0;
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			char land;
			cin>>land;
			forest[i][j]=(land=='*')?1:0;
		}
	}
	
	for(int i=1;i<=N;i++)
		forest[1][i]+=forest[1][i-1];
	
	for(int i=1;i<=N;i++)
		forest[i][1]+=forest[i-1][1];
		
		
	for(int i=2;i<=N;i++){
		for(int j=2;j<=N;j++){
			forest[i][j]+=forest[i-1][j]+forest[i][j-1]-forest[i-1][j-1];
		}
	}
	
	for(int q=0;q<Q;q++){
		int y1,x1,y2,x2;
		cin>>y1>>x1>>y2>>x2;
		cout<<forest[y2][x2]-forest[y2][x1-1]-forest[y1-1][x2]+forest[y1-1][x1-1]<<"\n";
	}
	
	return 0;	
}
