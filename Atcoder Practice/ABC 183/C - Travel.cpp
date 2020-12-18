/*
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
300
 points

Problem Statement
There are 
N
 cities. The time it takes to travel from City 
i
 to City 
j
 is 
T
i
,
j
.

Among those paths that start at City 
1
, visit all other cities exactly once, and then go back to City 
1
, how many paths take the total time of exactly 
K
 to travel along?

Constraints
2
≤
N
≤
8
If 
i
≠
j
, 
1
≤
T
i
,
j
≤
10
8
.
T
i
,
i
=
0
T
i
,
j
=
T
j
,
i
1
≤
K
≤
10
9
All values in input are integers.
Input
Input is given from Standard Input in the following format:

N
 
K

T
1
,
1
 
…
 
T
1
,
N

⋮

T
N
,
1
 
…
 
T
N
,
N

Output
Print the answer as an integer.

Sample Input 1 
Copy
4 330
0 1 10 100
1 0 20 200
10 20 0 300
100 200 300 0
Sample Output 1 
Copy
2
There are six paths that start at City 
1
, visit all other cities exactly once, and then go back to City 
1
:

1
→
2
→
3
→
4
→
1
1
→
2
→
4
→
3
→
1
1
→
3
→
2
→
4
→
1
1
→
3
→
4
→
2
→
1
1
→
4
→
2
→
3
→
1
1
→
4
→
3
→
2
→
1
The times it takes to travel along these paths are 
421
, 
511
, 
330
, 
511
, 
330
, and 
421
, respectively, among which two are exactly 
330
.

Sample Input 2 
Copy
5 5
0 1 1 1 1
1 0 1 1 1
1 1 0 1 1
1 1 1 0 1
1 1 1 1 0
Sample Output 2 
Copy
24
In whatever order we visit the cities, it will take the total time of 
5
 to travel.

######################################################################################Solution###################################################################################
*/

// Problem: B - Billiards
// Contest: AtCoder - AtCoder Beginner Contest 183
// URL: https://atcoder.jp/contests/abc183/tasks/abc183_b
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

int main(){
	double sx,sy,gx,gy;
	cin>>sx>>sy>>gx>>gy;
	double res=((sx*gy+gx*sy)/(double)(sy+gy));
	printf("%.10f\n",res);
	
	return 0;	
}
