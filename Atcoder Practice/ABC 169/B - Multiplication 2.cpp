
// Problem: B - Multiplication 2
// Contest: AtCoder - AtCoder Beginner Contest 169
// URL: https://atcoder.jp/contests/abc169/tasks/abc169_b
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

void input(vll& v,int N){
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
}

void solve(vll& v,int N){
	for(int i=0;i<N;i++)
		if(v[i]==0){
			cout<<"0\n";
			return;	
		}
	ll ans=1;		
	for(int i=0;i<N;i++){
		if(v[i]>(1000000000000000000/ans)){
			cout<<"-1\n";
			return ;	
		}
		ans=ans*(1ll*v[i]);
	}
	cout<<ans<<"\n";
	return;
}

int main(){
	int N;
	cin>>N;
	vll v(N);
	input(v,N);
	solve(v,N);
	
	return 0;	
}
