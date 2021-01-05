
// Problem: D. Even-Odd Game
// Contest: Codeforces - Codeforces Round #693 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1472/D
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

void solve(vl& v,int N){
	ll global=0;
	sort(all(v),greater<int>());
	for(int i=0;i<N;i++){
		if((i%2==0) && (v[i]%2==0))
			global+=1ll*v[i];
		else if((i%2==1) && (v[i]%2==1))
			global-=1ll*v[i];
	}
	if(global>0)
		cout<<"Alice\n";
	else if(global<0)
		cout<<"Bob\n";
	else
		cout<<"Tie\n";
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
