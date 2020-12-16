/*
Given an array of n integers, your task is to process q queries of the form: what is the xor sum of values in range [a,b]?

Input

The first input line has two integers n and q: the number of values and queries.

The second line has n integers x1,x2,…,xn: the array values.

Finally, there are q lines describing the queries. Each line has two integers a and b: what is the xor sum of values in range [a,b]?

Output

Print the result of each query.

Constraints
1≤n,q≤2⋅105
1≤xi≤109
1≤a≤b≤n
Example

Input:
8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3

Output:
3
0
6
4

##################################################################################Solution#######################################################################################
*/


// Problem: Range Xor Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1650
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
	int N,Q;
	cin>>N>>Q;
	
	vector<long> xorSum(N+1);
	xorSum[0]=0;
	for(int i=1;i<=N;i++)
		cin>>xorSum[i];
		
	for(int i=1;i<=N;i++)
		xorSum[i]^=xorSum[i-1];
		
	for(int i=1;i<=Q;i++){
		int a,b;
		cin>>a>>b;
		cout<<(xorSum[b]^xorSum[a-1])<<"\n";
	}
	return 0;	
}
