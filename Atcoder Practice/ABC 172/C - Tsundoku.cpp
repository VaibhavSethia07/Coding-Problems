
// Problem: C - Tsundoku
// Contest: AtCoder - AtCoder Beginner Contest 172
// URL: https://atcoder.jp/contests/abc172/tasks/abc172_c
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

void input(vll& v1,vll& v2,ll N,ll M){
	for(int i=1;i<=N;i++){
		cin>>v1[i];
	}
	for(int i=1;i<=M;i++)
		cin>>v2[i];
}

int bs(vll& v2,int M,ll X){
	int start=0,end=M,ans=-1;
	while(start<=end){
		int mid=start+(end-start)/2;
		if(v2[mid]<=X){
			ans=mid;
			start=mid+1;
		}else{
			end=mid-1;
		}
	}
	return ans;
}

ll solve(vll& v1,vll& v2,int N,int M,ll K){
	for(int i=1;i<=N;i++)
		v1[i]+=v1[i-1];
		
	for(int i=1;i<=M;i++)
		v2[i]+=v2[i-1];
	int mx=-1;	
	for(int i=0;i<=N;i++){
		if((K-v1[i])>=0){
			int ind=bs(v2,M,K-v1[i]);
			if(ind!=-1){
				mx=max(mx,ind+i);
			}
		}
	}
	
	return mx;
}

int N,M;
ll K;
int main(){
		cin>>N>>M>>K;
		vll v1(N+1),v2(M+1);
		input(v1,v2,N,M);
		cout<<solve(v1,v2,N,M,K)<<"\n";
	
	return 0;	
}
