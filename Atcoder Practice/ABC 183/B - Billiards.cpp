/*
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
200
 points

Problem Statement
Takahashi is playing billiards on a two-dimensional plane. The 
x
-axis functions as a wall; when a ball hits the axis, it will bounce off the axis so that the angle of incidence equals the angle of reflection.

Takahashi's ball is now at 
(
S
x
,
S
y
)
. When he strikes the ball aiming for some point, it will roll in a straight line towards that point.

To make the ball hit the 
x
-axis exactly once and then pass 
(
G
x
,
G
y
)
, where along the 
x
-axis should he aim for?

Constraints
−
10
6
≤
S
x
,
G
x
≤
10
6
0
<
S
y
,
G
y
≤
10
6
S
x
≠
G
x
All values in input are integers.
Input
Input is given from Standard Input in the following format:

S
x
 
S
y
 
G
x
 
G
y

Output
Let 
(
x
,
0
)
 be the point Takahashi should aim for. Print 
x
.

Your output will be considered correct when its absolute or relative error from our answer is at most 
10
−
6
.

Sample Input 1 
Copy
1 1 7 2
Sample Output 1 
Copy
3.0000000000
As shown below, we can make the ball pass 
(
7
,
2
)
 by striking it aiming for 
(
3
,
0
)
.

Figure

Sample Input 2 
Copy
1 1 3 2
Sample Output 2 
Copy
1.6666666667
Figure

Sample Input 3 
Copy
-9 99 -999 9999
Sample Output 3 
Copy
-18.7058823529
The output will be considered correct when its absolute or relative error from our answer is at most 
10
−
6

##############################################################################Solution###########################################################################################
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
