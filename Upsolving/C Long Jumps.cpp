
// Problem: C. Long Jumps
// Contest: Codeforces - Codeforces Round #693 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1472/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

void divisors(map<int,int>& d,ll N){
	for(int div : {2,3,5}){
		int cnt=1;
		if(N%2==0){
			while((N%2)==0){
				N/=2;
				cnt++;
			}
			d[div]=cnt;
		}
	}
	static array<int,8> increments = {4,2,4,2,4,6,2,6};
	int i=0;
	for(ll div=7;div*div<=N;div+=increments[i++]){
		if((N%div)==0){
			int cnt=1;
			while((N%i)==0){
				N/=i;
				cnt++;
			}
			d[i]=cnt;
		}
		if(i==8)
			i=0;
	}
	if(N>1)
		d[N]=2;
}

void input(vl& v,int N){
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
}

vl dp(N);
void solve(vl& v,int N){
	dp[N-1]=v[N-1];
	for(int i=N-1;i>=0;i--){
		dp[i]=v[i];
		if(i+v[i]<N)
			dp[i]+=dp[i+v[i]];
	}
	
	ll mx=0;
	for(auto& x:dp){
		mx=max(1ll*x,mx);
	}
	cout<<mx<<"\n";
}

int main(){
	
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
