
// Problem: D - Floor Function
// Contest: AtCoder - AtCoder Beginner Contest 165
// URL: https://atcoder.jp/contests/abc165/tasks/abc165_d
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

void input(vl& v,int N){
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
}

ll solve(ll A,ll B,ll N){
	ll start=1,end=N;
	ll ans=INT_MIN;
	while(start<=end){
		ll mid=start+(end-start)/2;
		ll sub_ans=((A*mid)/B-A*(mid/B));
		if(sub_ans>=ans){
			ans=sub_ans;
			start=mid+1;
		}else
			end=mid-1;
	}
	return ans;
}

int main(){
	
	ll A,B,N;
	cin>>A>>B>>N;
	
	cout<<solve(A,B,N)<<"\n";
	
	return 0;	
}
