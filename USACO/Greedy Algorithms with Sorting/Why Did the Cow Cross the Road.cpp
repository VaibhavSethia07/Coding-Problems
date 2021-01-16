/*
Farmer John's cows are trying to learn to cross the road effectively. Remembering the old "why did the chicken cross the road?" joke, they figure the chickens must be experts on crossing the road, and go off in search of chickens to help them.
As it turns out, chickens are very busy creatures and have limited time to help the cows. There are C chickens on the farm (1≤C≤20,000), conveniently numbered 1…C, and each chicken i is only willing to help a cow at precisely time Ti. The cows, never in a hurry, have more flexibility in their schedules. There are N cows on the farm (1≤N≤20,000), conveniently numbered 1…N, where cow j is able to cross the road between time Aj and time Bj. Figuring the "buddy system" is the best way to proceed, each cow j would ideally like to find a chicken i to help her cross the road; in order for their schedules to be compatible, i and j must satisfy Aj≤Ti≤Bj.

If each cow can be paired with at most one chicken and each chicken with at most one cow, please help compute the maximum number of cow-chicken pairs that can be constructed.

INPUT FORMAT (file helpcross.in):
The first line of input contains C and N. The next C lines contain T1…TC, and the next N lines contain Aj and Bj (Aj≤Bj) for j=1…N. The A's, B's, and T's are all non-negative integers (not necessarily distinct) of size at most 1,000,000,000.
OUTPUT FORMAT (file helpcross.out):
Please compute the maximum possible number of cow-chicken pairs.
SAMPLE INPUT:
5 4
7
8
6
2
9
2 5
4 9
0 3
8 13
SAMPLE OUTPUT:
3
Problem credits: Brian Dean

#############################################################################################Solution##############################################################################
*/

// Problem: Problem 1. Why Did the Cow Cross the Road
// Contest: USACO - USACO 2017 February Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=714
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

bool cmp(const pair<int,int>& p1,const pair<int,int>& p2){
	if(p1.s==p2.s){
		return p1.f<p2.f;
	}
	return p1.s<p2.s;
}

int main(){
	freopen("helpcross.in","r",stdin);
	freopen("helpcross.out","w",stdout);
	
	int C,N;
	cin>>C>>N;
	multiset<int> chickens;
	vector<pair<int,int>> cows(N);
	int c;
	for(int i=0;i<C;i++){
		cin>>c;
		chickens.insert(c);
	}
	for(int i=0;i<N;i++){
		cin>>cows[i].s>>cows[i].f;
	}
	sort(all(cows));
	int ans=0;
	for(int i=0;i<N;i++){
		auto it=chickens.lower_bound(cows[i].s);
		if(it!=chickens.end() && *it<=cows[i].f){
			ans++;
			chickens.erase(it);
		}
	}
	cout<<ans<<"\n";
	return 0;	
}
