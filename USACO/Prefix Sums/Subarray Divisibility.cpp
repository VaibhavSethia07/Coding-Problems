/*
Given an array of n integers, your task is to count the number of subarrays where the sum of values is divisible by n.

Input

The first input line has an integer n: the size of the array.

The next line has n integers a1,a2,…,an: the contents of the array.

Output

Print one integer: the required number of subarrays.

Constraints
1≤n≤2⋅105
−109≤ai≤109
Example

Input:
5
3 1 2 7 4

Output:
1

#############################################################################Solution##############################################################################################
*/

// Problem: Subarray Divisibility
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1662
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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
	ll res=0;
	cin>>N;
	vl v(N);
	map<ll,ll> mp;
	mp[0]=1;
	
	for(int i=0;i<N;i++)
		cin>>v[i];

	for(int i=0;i<N;i++){
		if(i>=1)
			v[i]=(v[i]+v[i-1])%N;
		while(v[i]<0)
			v[i]=v[i]+N;
		v[i]%=N;
	}
	
	for(int i=0;i<N;i++){
		res+=mp[v[i]];
		mp[v[i]]+=1;
	}
	cout<<res<<"\n";
	return 0;	
}
