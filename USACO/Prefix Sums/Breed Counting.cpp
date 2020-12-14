/*
Farmer John's N cows, conveniently numbered 1…N, are all standing in a row (they seem to do so often that it now takes very little prompting from Farmer John to line them up). Each cow has a breed ID: 1 for Holsteins, 2 for Guernseys, and 3 for Jerseys. Farmer John would like your help counting the number of cows of each breed that lie within certain intervals of the ordering.
INPUT FORMAT (file bcount.in):
The first line of input contains N and Q (1≤N≤100,000, 1≤Q≤100,000).
The next N lines contain an integer that is either 1, 2, or 3, giving the breed ID of a single cow in the ordering.

The next Q lines describe a query in the form of two integers a,b (a≤b).

OUTPUT FORMAT (file bcount.out):
For each of the Q queries (a,b), print a line containing three numbers: the number of cows numbered a…b that are Holsteins (breed 1), Guernseys (breed 2), and Jerseys (breed 3).
SAMPLE INPUT:
6 3
2
1
1
3
2
1
1 6
3 3
2 4
SAMPLE OUTPUT:
3 2 1
1 0 0
2 0 1
Problem credits: Nick Wu

###################################################################################Solution########################################################################################
*/


// Problem: Problem 3. Breed Counting
// Contest: USACO - USACO 2015 December Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=572
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
	freopen("bcount.in","r",stdin);
	freopen("bcount.out","w",stdout);
	int N,Q;
	cin>>N>>Q;
	vector<long> holsteins(N+1,0);
	vector<long> guernseys(N+1,0);
	vector<long> jerseys(N+1,0);
	int cow,l,r;
	
	for(int i=1;i<=N;i++){
		cin>>cow;
		if(cow==1)
			holsteins[i]=1;
		else if(cow==2)
			guernseys[i]=1;
		else if(cow==3)
			jerseys[i]=1;
	}
	
	for(int i=1;i<=N;i++){
		holsteins[i]+=holsteins[i-1];
		guernseys[i]+=guernseys[i-1];
		jerseys[i]+=jerseys[i-1];
	}
	
	for(int i=1;i<=Q;i++){
		cin>>l>>r;
		cout<<(holsteins[r]-holsteins[l-1])<<" "<<(guernseys[r]-guernseys[l-1])<<" "<<(jerseys[r]-jerseys[l-1])<<"\n";
	}
	
	return 0;	
}
