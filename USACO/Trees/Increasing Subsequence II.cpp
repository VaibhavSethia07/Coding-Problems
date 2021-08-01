// Problem: Increasing Subsequence II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1748
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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
#define modinv(a,m) modEx(a,m-2,m)
#define moddiv(a,b,m) (a*modinv(b,m))%m
const int mod=1e9+7;

const int MAXN=2e5+5;
int fen[MAXN];

void update(int i,int x){
	while(i<MAXN){
		fen[i]+=x;
		fen[i]%=mod;
		i=i+(i&(-i));
	}
}

int query(int i){
	int sum=0;
	while(i>0){
		sum+=fen[i];
		sum%=mod;
		i=i-(i&(-i));
	}
	return sum;
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int N;
	cin>>N;
	vector<int> arr(N+1);
	vector<int> dummy;
	
	for(int i=1;i<=N;i++)
		cin>>arr[i];
	
	dummy=arr;
	sort(all(dummy));
		
	map<int,int> compress;
	for(int i=1;i<=N;i++)
		compress[dummy[i]]=i;
		
	for(int i=1;i<=N;i++)
		arr[i]=compress[arr[i]];
	
	
	int result=0;
	for(int i=1;i<=N;i++){
		int sub=1+query(arr[i]-1);
		result+=sub%mod;
		result%=mod;
		update(arr[i],sub);
	}
	
	cout<<result<<"\n";
	
	
	return 0;	
}
