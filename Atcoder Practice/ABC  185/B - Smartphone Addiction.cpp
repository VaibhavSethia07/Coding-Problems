/*
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
200
 points

Problem Statement
The battery of Takahashi's smartphone has 
N
 mAh capacity. At time 
0.5
, 
1.5
, 
2.5
, and so on (that is, at time 
n
+
0.5
 for every integer 
n
), the battery charge decreases by 
1
 mAh.
Takahashi will leave his house with his phone fully charged at time 
0
, visit a cafe 
M
 times, and return home at time 
T
.
He will stay at the 
i
-th cafe from time 
A
i
 to time 
B
i
. During this stay, he charges his phone, so the battery charge does not decrease. Instead, at time 
n
+
0.5
 for every integer 
n
, it increases by 
1
. However, if it is already equal to the battery capacity, it does not increase nor decrease.
Determine whether he can return home without the battery charge dropping to 
0
 on the way.

Constraints
1
≤
N
≤
10
9
1
≤
M
≤
1000
1
≤
T
≤
10
9
0
<
A
1
<
B
1
<
A
2
<
B
2
<
A
3
<
B
3
<
⋯
<
A
M
<
B
M
<
T
All values in input are integers.
Input
Input is given from Standard Input in the following format:

N
 
M
 
T

A
1
 
B
1

A
2
 
B
2

A
3
 
B
3

⋮

A
M
 
B
M

Output
If Takahashi can return home without the battery charge dropping to 
0
 on the way, print Yes; otherwise, print No.

Sample Input 1 
Copy
10 2 20
9 11
13 17
Sample Output 1 
Copy
Yes
The battery charge changes as follows:

Time 
0
 (leaving home): 
10
 mAh
Time 
9
 (the beginning of the stay at the first cafe): 
1
 mAh
Time 
11
 (the end of the stay at the first cafe): 
3
 mAh (He charges his phone in a cafe.)
Time 
13
 (the beginning of the stay at the second cafe): 
1
 mAh
Time 
17
 (the end of the stay at the second cafe): 
5
 mAh
Time 
20
 (getting home): 
2
 mAh
During this process, the battery charge never drops to 
0
, so we print Yes.

Sample Input 2 
Copy
10 2 20
9 11
13 16
Sample Output 2 
Copy
No
This case is the same as Sample Input/Output 1 until he starts his stay at the second cafe with 
1
 mAh charge.
When he ends his stay there at time 
16
, the battery charge is 
4
 mAh.
Then at time 
19.5
, it drops to 
0
, so we print No.

Sample Input 3 
Copy
15 3 30
5 8
15 17
24 27
Sample Output 3 
Copy
Yes
The battery charge drops to 
1
 mAh when he gets home, but it never drops to 
0
 on the way.

Sample Input 4 
Copy
20 1 30
20 29
Sample Output 4 
Copy
No
The battery charge drops to 
0
 at time 
19.5
.

Sample Input 5 
Copy
20 1 30
1 10
Sample Output 5 
Copy
No

##################################################################################Solution#######################################################################################
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
