/*
You are given n points on the straight line — the positions (x-coordinates) of the cities and m points on the same line — the positions (x-coordinates) of the cellular towers. All towers work in the same way — they provide cellular network for all cities, which are located at the distance which is no more than r from this tower.

Your task is to find minimal r that each city has been provided by cellular network, i.e. for each city there is at least one cellular tower at the distance which is no more than r.

If r = 0 then a tower provides cellular network only for the point where it is located. One tower can provide cellular network for any number of cities, but all these cities must be at the distance which is no more than r from this tower.

Input
The first line contains two positive integers n and m (1 ≤ n, m ≤ 105) — the number of cities and the number of cellular towers.

The second line contains a sequence of n integers a1, a2, ..., an ( - 109 ≤ ai ≤ 109) — the coordinates of cities. It is allowed that there are any number of cities in the same point. All coordinates ai are given in non-decreasing order.

The third line contains a sequence of m integers b1, b2, ..., bm ( - 109 ≤ bj ≤ 109) — the coordinates of cellular towers. It is allowed that there are any number of towers in the same point. All coordinates bj are given in non-decreasing order.

Output
Print minimal r so that each city will be covered by cellular network.

Examples
inputCopy
3 2
-2 2 4
-3 0
outputCopy
4
inputCopy
5 3
1 5 10 14 17
4 11 15
outputCopy
3

###############################################################################Solution############################################################################################
*/


// Problem: C. Cellular Network
// Contest: Codeforces - Educational Codeforces Round 15
// URL: https://codeforces.com/problemset/problem/702/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

int upper(vector<int> &towers,int M,int X){
	int start=0;
	int end=M-1;
	int res=M;
	while(start<=end){
		int mid=start+(end-start)/2;
		if(towers[mid]>=X){
			res = mid;
			end = mid-1;
		}else
			start = mid+1;
	}
	return res;
}

int lower(vector<int> &towers,int M,int X){
	int start=0;
	int end=M-1;
	int res=-1;
	while(start<=end){
		int mid=start+(end-start)/2;
		if(towers[mid]<=X){
			res = mid;
			start = mid+1;
		}else
			end = mid-1;
	}
	return res;
}

int main(){
	int N,M;
	cin>>N>>M;
	
	vector<int> cities;
	vector<int> towers;
	for(int i=0;i<N;i++){
		int x;
		cin>>x;
		cities.push_back(x);
	}
	
	for(int i=0;i<M;i++){
		int x;
		cin>>x;
		towers.push_back(x);
	}
	int global_r=0;
	for(int i=0;i<N;i++){
		int curr_r=INT_MAX;
		int ceil = upper(towers,M,cities[i]);
		int floor = lower(towers,M,cities[i]);
		if(ceil!=M)
			curr_r = min(curr_r,towers[ceil]-cities[i]);
		if(floor!=-1)
			curr_r = min(curr_r,cities[i]-towers[floor]);
		global_r = max(global_r,curr_r);
	}
	cout<<global_r<<"\n";
	
	return 0;	
}
