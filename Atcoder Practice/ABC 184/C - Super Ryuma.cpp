/*
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
300
 points

Problem Statement
There is an infinite two-dimensional grid, and we have a piece called Super Ryuma at square 
(
r
1
,
c
1
)
. (Ryu means dragon and Ma means horse.) In one move, the piece can go to one of the squares shown below:



More formally, when Super Ryuma is at square 
(
a
,
b
)
, it can go to square 
(
c
,
d
)
 such that at least one of the following holds:

a
+
b
=
c
+
d
a
−
b
=
c
−
d
|
a
−
c
|
+
|
b
−
d
|
≤
3
Find the minimum number of moves needed for the piece to reach 
(
r
2
,
c
2
)
 from 
(
r
1
,
c
1
)
.

Constraints
All values in input are integers.
1
≤
r
1
,
c
1
,
r
2
,
c
2
≤
10
9
Input
Input is given from Standard Input in the following format:

r
1
 
c
1

r
2
 
c
2

Output
Print the minimum number of moves needed for Super Ryuma to reach 
(
r
2
,
c
2
)
 from 
(
r
1
,
c
1
)
.

Sample Input 1 
Copy
1 1
5 6
Sample Output 1 
Copy
2
We need two moves - for example, 
(
1
,
1
)
→
(
5
,
5
)
→
(
5
,
6
)
.

Sample Input 2 
Copy
1 1
1 200001
Sample Output 2 
Copy
2
We need two moves - for example, 
(
1
,
1
)
→
(
100001
,
100001
)
→
(
1
,
200001
)
.

Sample Input 3 
Copy
2 3
998244353 998244853
Sample Output 3 
Copy
3
We need three moves - for example, 
(
2
,
3
)
→
(
3
,
3
)
→
(
−
247
,
253
)
→
(
998244353
,
998244853
)
.

Sample Input 4 
Copy
1 1
1 1
Sample Output 4 
Copy
0

######################################################################################Solution###################################################################################
*/
// Problem: C - Super Ryuma
// Contest: AtCoder - AtCoder Beginner Contest 184
// URL: https://atcoder.jp/contests/abc184/tasks/abc184_c
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

bool condition(long x1,long y1,long x2,long y2){
	return (((x1+y1)==(x2+y2)) || ((x1-y1)==(x2-y2)) || (abs(x1-x2)+abs(y1-y2)<=3));
}

int main(){
	long x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2;
	
	if(x1==x2 && y1==y2){
		cout<<0<<"\n";
		return 0;
	}
	else if(condition(x1,y1,x2,y2)){
		cout<<1<<"\n";	
		return 0;
	}
	else if((x1+y1)%2==(x2+y2)%2){
		cout<<2<<"\n";
		return 0;
	}
	else{
		for(int i=-2;i<=2;i++){
			for(int j=-2;j<=2;j++){
				long p=x2+i;
				long q=y2+j;
				if(condition(x1,y1,p,q)){
					cout<<2<<"\n";
					return 0;
			    }
		    }
	    }
	}	
	
	if(condition(x1,y1,x2-3,y2) || condition(x1,y1,x2,y2-3) || condition(x1,y1,x2+3,y2) || condition(x1,y1,x2,y2+3))
	{
		cout<<2<<"\n";
		return 0;	
	}
	cout<<3<<"\n";
	return 0;	
}


// Problem: C - Super Ryuma
// Contest: AtCoder - AtCoder Beginner Contest 184
// URL: https://atcoder.jp/contests/abc184/tasks/abc184_c
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

bool condition(long x1,long y1,long x2,long y2){
	return (((x1+y1)==(x2+y2)) || ((x1-y1)==(x2-y2)) || (abs(x1-x2)+abs(y1-y2)<=3));
}

int main(){
	long x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2;
	
	if(x1==x2 && y1==y2){
		cout<<0<<"\n";
		return 0;
	}
	else if(condition(x1,y1,x2,y2)){
		cout<<1<<"\n";	
		return 0;
	}
	else if((x1+y1)%2==(x2+y2)%2){
		cout<<2<<"\n";
		return 0;
	}
	else{
		for(int i=-2;i<=2;i++){
			for(int j=-2;j<=2;j++){
				long p=x2+i;
				long q=y2+j;
				if(condition(x1,y1,p,q)){
					cout<<2<<"\n";
					return 0;
			    }
		    }
	    }
	}	
	
	if(condition(x1,y1,x2-3,y2) || condition(x1,y1,x2,y2-3) || condition(x1,y1,x2+3,y2) || condition(x1,y1,x2,y2+3))
	{
		cout<<2<<"\n";
		return 0;	
	}
	cout<<3<<"\n";
	return 0;	
}
