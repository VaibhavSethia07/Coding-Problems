
// Problem: C - Many Requirements
// Contest: AtCoder - AtCoder Beginner Contest 165
// URL: https://atcoder.jp/contests/abc165/tasks/abc165_c
// Memory Limit: 1024 MB
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

void input(vector<array<int,4>>& v,int Q){
	for(int i=0;i<Q;i++){
		cin>>v[i][0]>>v[i][1]>>v[i][2]>>v[i][3];
	}
}

vector<int> sol;
long check(vector<array<int,4>>& v,int Q){
	int a,b,c,d;
	long sub_sum=0;
	for(int i=0;i<Q;i++){
		a=v[i][0];b=v[i][1];c=v[i][2];d=v[i][3];
		a--;b--;
		if((sol[b]-sol[a])==c){
			sub_sum+=d;
		}
	}
	return sub_sum;
}
long ans=0;
void solve(int i,int curr,vector<array<int,4>>& v,int N,int M,int Q){
	if(i>=N){
		ans=max(ans,check(v,Q));
		return;
	}
	
	for(int j=curr;j<=M;j++){
		sol.pb(j);
		solve(i+1,j,v,N,M,Q);
		sol.pop_back();
	}
}

int main(){
	
	int N,M,Q;
	cin>>N>>M>>Q;
	vector<array<int,4>> v(Q);
	input(v,Q);
	solve(0,1,v,N,M,Q);
	cout<<ans<<"\n";
	
	return 0;	
}
