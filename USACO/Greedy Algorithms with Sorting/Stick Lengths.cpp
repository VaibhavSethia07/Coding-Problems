/*
There are n sticks with some lengths. Your task is to modify the sticks so that each stick has the same length.

You can either lengthen and shorten each stick. Both operations cost x where x is the difference between the new and original length.

What is the minimum total cost?

Input

The first input line contains an integer n: the number of sticks.

Then there are n integers: p1,p2,…,pn: the lengths of the sticks.

Output

Print one integer: the minimum total cost.

Constraints
1≤n≤2⋅105
1≤pi≤109
Example

Input:
5
2 3 1 5 2

Output:
5

#################################################################################Solution##########################################################################################
*/

// Problem: Stick Lengths
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1074
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
	int n;
	cin>>n;
	vector<long long> v(n);
	long long cost=0;
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v.begin(),v.end());

	long median=(n&1)?v[n/2]:(v[(n-1)/2]+v[(n+1)/2])/2;
	for(long l:v)
		cost+=abs(l-median);
	cout<<cost<<"\n";
	return 0;	
}
