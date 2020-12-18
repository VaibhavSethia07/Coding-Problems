/*
You are playing a new computer game in which you have to fight monsters. In a dungeon you are trying to clear, you met three monsters; the first of them has a health points, the second has b health points, and the third has c.

To kill the monsters, you can use a cannon that, when fired, deals 1 damage to the selected monster. Every 7-th (i. e. shots with numbers 7, 14, 21 etc.) cannon shot is enhanced and deals 1 damage to all monsters, not just one of them. If some monster's current amount of health points is 0, it can't be targeted by a regular shot and does not receive damage from an enhanced shot.

You want to pass the dungeon beautifully, i. e., kill all the monsters with the same enhanced shot (i. e. after some enhanced shot, the health points of each of the monsters should become equal to 0 for the first time). Each shot must hit a monster, i. e. each shot deals damage to at least one monster.

Input
The first line contains a single integer t (1≤t≤104) — the number of test cases.

Each test case consists of a single line that contains three integers a, b and c (1≤a,b,c≤108) — the number of health points each monster has.

Output
For each test case, print YES if you can kill all the monsters with the same enhanced shot. Otherwise, print NO. You may print each letter in any case (for example, YES, Yes, yes, yEs will all be recognized as positive answer).

Example
inputCopy
3
3 2 4
1 1 1
10 1 7
outputCopy
YES
NO
NO
Note
In the first test case, you can do as follows: 1-th shot to the first monster, 2-th shot to the second monster, 3-th shot to the third monster, 4-th shot to the first monster, 5-th shot to the third monster, 6-th shot to the third monster, and 7-th enhanced shot will kill all the monsters.

In the second test case, you can't kill monsters with the same enhanced shot, because the total number of health points of monsters is 3, and you will kill them in the first 3 shots.

########################################################################################Solution###################################################################################
*/


// Problem: A. Dungeon
// Contest: Codeforces - Educational Codeforces Round 100 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1463/problem/0
// Memory Limit: 256 MB
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
	int T;
	cin>>T;
	
	for(int i=0;i<T;i++){
		long a,b,c;
		cin>>a>>b>>c;
		long sum=a+b+c;
		long blocks = sum/9;
		
		if((sum%9==0) && (a>=blocks) && (b>=blocks) && (c>=blocks))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	
	return 0;	
}
