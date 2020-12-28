/*
It's a hot summer day out on the farm, and Farmer John is serving lemonade to his N cows! All N cows (conveniently numbered 1…N) like lemonade, but some of them like it more than others. In particular, cow i is willing to wait in a line behind at most wi cows to get her lemonade. Right now all N cows are in the fields, but as soon as Farmer John rings his cowbell, the cows will immediately descend upon FJ's lemonade stand. They will all arrive before he starts serving lemonade, but no two cows will arrive at the same time. Furthermore, when cow i arrives, she will join the line if and only if there are at most wi cows already in line.
Farmer John wants to prepare some amount of lemonade in advance, but he does not want to be wasteful. The number of cows who join the line might depend on the order in which they arrive. Help him find the minimum possible number of cows who join the line.

INPUT FORMAT (file lemonade.in):
The first line contains N, and the second line contains the N space-separated integers w1,w2,…,wN. It is guaranteed that 1≤N≤105, and that 0≤wi≤109 for each cow i.
OUTPUT FORMAT (file lemonade.out):
Print the minimum possible number of cows who might join the line, among all possible orders in which the cows might arrive.
SAMPLE INPUT:
5
7 1 400 2 2
SAMPLE OUTPUT:
3
In this setting, only three cows might end up in line (and this is the smallest possible). Suppose the cows with w=7 and w=400 arrive first and wait in line. Then the cow with w=1 arrives and turns away, since 2 cows are already in line. The cows with w=2 then arrive, one staying and one turning away.

Problem credits: Dhruv Rohatgi

##################################################################################Solution##########################################################################################
*/

// Problem: Problem 2. Lemonade Line
// Contest: USACO - USACO 2018 US Open Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=835
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
	freopen("lemonade.in","r",stdin);
	freopen("lemonade.out","w",stdout);
	long N;
	cin>>N;
	vector<long> cows(N);
	for(int i=0;i<N;i++){
		cin>>cows[i];
	}
	sort(cows.begin(),cows.end(),greater<long>());
	long long cnt=0;
	for(int i=0;i<N;i++){
		if(cows[i]>=cnt)
			cnt++;
	}
	cout<<cnt<<"\n";
	
	return 0;	
}
