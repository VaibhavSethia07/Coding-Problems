/*
Given an array of n integers, your task is to find the maximum sum of values in a contiguous, nonempty subarray.

Input

The first input line has an integer n: the size of the array.

The second line has n integers x1,x2,…,xn: the array values.

Output

Print one integer: the maximum subarray sum.

Constraints
1≤n≤2⋅105
−109≤xi≤109
Example

Input:
8
-1 3 -2 5 3 -5 2 2

Output:
9

#######################################################################################Solution#####################################################################################
*/


// Problem: Maximum Subarray Sum
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1643
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
	cin>>N;
	vector<long long> v(N+1);
	vector<long long> mn(N+1);
	long long res=LONG_MIN;
	for(int i=1;i<=N;i++){
		cin>>v[i];
		res=max(res,v[i]);
	}
	
	for(int i=1;i<=N;i++){
		v[i]+=v[i-1];
		res=max(res,v[i]);
	}
	mn[0]=0;
	for(int i=1;i<=N;i++){
		mn[i]=min(v[i-1],mn[i-1]);
	}
	
	for(int i=1;i<=N;i++)
		res=max(res,v[i]-mn[i]);
		
	cout<<res<<"\n";
	return 0;	
}
