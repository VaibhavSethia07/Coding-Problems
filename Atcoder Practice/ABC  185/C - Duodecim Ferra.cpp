/*
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
300
 points

Problem Statement
There is an iron bar of length 
L
 lying east-west. We will cut this bar at 
11
 positions to divide it into 
12
 bars. Here, each of the 
12
 resulting bars must have a positive integer length.
Find the number of ways to do this division. Two ways to do the division are considered different if and only if there is a position cut in only one of those ways.
Under the constraints of this problem, it can be proved that the answer is less than 
2
63
.

Constraints
12
≤
L
≤
200
L
 is an integer.
Input
Input is given from Standard Input in the following format:

L

Output
Print the number of ways to do the division.

Sample Input 1 
Copy
12
Sample Output 1 
Copy
1
There is only one way: to cut the bar into 
12
 bars of length 
1
 each.

Sample Input 2 
Copy
13
Sample Output 2 
Copy
12
Just one of the resulting bars will be of length 
2
. We have 
12
 options: one where the westmost bar is of length 
2
, one where the second bar from the west is of length 
2
, and so on.

Sample Input 3 
Copy
17
Sample Output 3 
Copy
4368

########################################################################################Solution#################################################################################
*/

// Problem: C - Duodecim Ferra
// Contest: AtCoder - AtCoder Beginner Contest 185
// URL: https://atcoder.jp/contests/abc185/tasks/abc185_c
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

long long int binoCoeff(int N,int R,long long int **dp){
	if(N==0)
		return 0;
	if(N==1 || R==0 || R==N)
		return 1;
	if(dp[N][R]!=-1)
		return dp[N][R];
	return dp[N][R]=binoCoeff(N-1,R-1,dp)+binoCoeff(N-1,R,dp);
}

int main(){
	int L;
	cin>>L;
	long long int* dp[201];
	for(int i=0;i<201;i++){
		dp[i] = new long long int[201];
		for(int j=0;j<201;j++)
			dp[i][j]=-1;
	}
	cout<<binoCoeff(L-1,L-12,dp)<<"\n";
	
	return 0;	
}
