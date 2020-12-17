/*
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
200
 points

Problem Statement
Takahashi will answer 
N
 quiz questions.
Initially, he has 
X
 points. Each time he answers a question, he gains 
1
 point if his answer is correct and loses 
1
 point if it is incorrect.
However, there is an exception: when he has 
0
 points, he loses nothing for answering a question incorrectly.

You will be given a string 
S
 representing whether Takahashi's answers are correct.
If the 
i
-th character of 
S
 from the left is o, it means his answer for the 
i
-th question is correct; if that character is x, it means his answer for the 
i
-th question is incorrect.
How many points will he have in the end?

Constraints
1
≤
N
≤
2
×
10
5
0
≤
X
≤
2
×
10
5
S
 is a string of length 
N
 consisting of o and x.
Input
Input is given from Standard Input in the following format:

N
 
X

S

Output
Print the number of points Takahashi will have in the end.

Sample Input 1 
Copy
3 0
xox
Sample Output 1 
Copy
0
Initially, he has 
0
 points.
He answers the first question incorrectly but loses nothing because he has no point.
Then, he answers the second question correctly, gains 
1
 point, and now has 
1
 point.
Finally, he answers the third question incorrectly, loses 
1
 point, and now has 
0
 points.
Thus, he has 
0
 points in the end. We should print 
0
.

Sample Input 2 
Copy
20 199999
oooooooooxoooooooooo
Sample Output 2 
Copy
200017
Sample Input 3 
Copy
20 10
xxxxxxxxxxxxxxxxxxxx
Sample Output 3 
Copy
0

########################################################################################Solution#################################################################################
*/

// Problem: B - Quizzes
// Contest: AtCoder - AtCoder Beginner Contest 184
// URL: https://atcoder.jp/contests/abc184/tasks/abc184_b
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
	long long int N,X;
	cin>>N>>X;
	string ans;
	cin>>ans;
	
	for(int i=0;i<N;i++){
		if(ans[i]=='x'){
			if(X!=0)
				X--;
		}else
			X++;
	}
	cout<<X<<"\n";
	return 0;	
}
