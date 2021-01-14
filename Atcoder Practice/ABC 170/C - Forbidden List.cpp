
// Problem: C - Forbidden List
// Contest: AtCoder - AtCoder Beginner Contest 170
// URL: https://atcoder.jp/contests/abc170/tasks/abc170_c
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

void input(unordered_set<int>& v,int N){
	int x;
	for(int i=0;i<N;i++){
		cin>>x;
		v.insert(x);
	}
}

int solve(unordered_set<int>& v,int X,int N){
	
	if(v.count(X)==0){
		return X;
	}
	
	for(int dist=1;dist<=100;dist++){
		if(!v.count(X-dist))
			return X-dist;
		else if(!v.count(X+dist))
			return X+dist;
	}
	
	return 0;
}

int main(){
	
	int X,N;
	cin>>X>>N;
	unordered_set<int> v;
	input(v,N);
	cout<<solve(v,X,N)<<"\n";
	
	return 0;	
}
