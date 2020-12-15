/*
Given an array of n integers, your task is to count the number of subarrays having sum x.

Input

The first input line has two integers n and x: the size of the array and the target sum x.

The next line has n integers a1,a2,…,an: the contents of the array.

Output

Print one integer: the required number of subarrays.

Constraints
1≤n≤2⋅105
−109≤x,ai≤109
Example

Input:
5 7
2 -1 3 5 -2

Output:
2

####################################################################################Solution#######################################################################################
*/


// Problem: Subarray Sums II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1661
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
	int N,T;
	cin>>N>>T;
	vector<long> v(N);
	map<long,long> mp;
	mp[0]=1;
	long res=0;
	for(int i=0;i<N;i++)
		cin>>v[i];
		
	for(int i=1;i<N;i++)
		v[i]+=v[i-1];
		
	for(int i=0;i<N;i++){
		if(mp.count(v[i]-T))
			res+=mp[v[i]-T];
		mp[v[i]]+=1;
	}
	
	cout<<res<<"\n";
	return 0;	
}
