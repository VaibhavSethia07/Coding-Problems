
// Problem: C - A x B + C
// Contest: AtCoder - AtCoder Beginner Contest 179
// URL: https://atcoder.jp/contests/abc179/tasks/abc179_c
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
	int N;
	cin>>N;
	static vector<long> v(1000001);
	static bool was_executed=false;
	if(!was_executed){
		was_executed=true;
		long cnt=0;
		for(int i=1;i<1000001;i++){
			int M=N-i;
			for(int j=1;j*j<=M;j++){
				if(M%j==0){
					if(j==(M/j))
						cnt++;
					else
						cnt+=2;
				}
			}
		}
		v[N]=cnt;
		
	}
	cout<<v[N]<<"\n";
	return 0;	
}

// Editorial Solution
int main(){
	int N;
	cin>>N;
	long ans=0;
	for(int a=1;a<N;a++)
		ans+=(N-1)/a;
	cout<<ans<<"\n";
}
