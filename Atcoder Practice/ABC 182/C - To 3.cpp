
// Problem: C - To 3
// Contest: AtCoder - AtCoder Beginner Contest 182
// URL: https://atcoder.jp/contests/abc182/tasks/abc182_c
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

int multiple3(string str,long sum,int N){
	if(sum==0)
		return -1;
	if(sum%3==0)
		return 0;
	if(N==0)
		return -1;
		
	int keep = multiple3(str,sum,N-1);
	int not_keep = multiple3(str,sum-(str[N-1]-'0'),N-1);
	
	if(keep==-1 && not_keep==-1)
		return -1;
	int mn=INT_MAX;	
	if(keep!=-1)
		mn = min(keep,mn);
	if(not_keep!=-1)
		mn = min(1+not_keep,mn);
	return mn;
}

int main(){
	string str;
	cin>>str;
	int N = (int)str.length();
	long sum=0;
	for(int i=0;i<N;i++){
		sum+=(str[i]-'0');
	}
	
	cout<<multiple3(str,sum,N)<<"\n";
	return 0;	
}
