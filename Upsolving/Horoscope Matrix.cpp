/*
Bhavyesh is a love guru. He helps people out by telling them whether their current partner is their true soulmate based on their partner's Horoscope Matrix. Bhavyesh is busy with his own partner today, so he has asked you to fill in for him.

A Horoscope Matrix is said to be good if each of its diagonals directed from the top left to the bottom right contains only equal elements, i.e. the same value repeated one or more times. This value may be different for different diagonals.

You are given a Horoscope Matrix with N rows (numbered 1 through N) and M columns (numbered 1 through M). For each valid i and j, let's denote the element in the i-th row and j-th column by Ai,j.

You should process Q queries. In each query:

You are given three integers X, Y and V. Change the value of AX,Y to V.
Then, determine if the current Horoscope Matrix is good.
Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and M.
N lines follow. For each i (1≤i≤N), the i-th of these lines contains M space-separated integers Ai,1,Ai,2,…,Ai,M describing the initial matrix.
The next line contains a single integer Q.
Each of the next Q lines contains three space-separated integers X, Y and V describing a query.
Output
For each query, print a single line containing the string "Yes" if the matrix is good or "No" if it is not good (without quotes).

Constraints
1≤T≤100
1≤N,M≤500
|Ai,j|≤109 for each valid i,j
1≤Q≤2⋅105
1≤X≤N
1≤Y≤M
|V|≤109
the sum of N⋅M over all test cases does not exceed 5⋅105
the sum of Q over all test cases does not exceed 2⋅105
Subtasks
Subtask #1 (10 points):

T≤50
N,M≤100
Q=1
Subtask #2 (30 points):

T≤50
N,M,Q≤100
Subtask #3 (60 points): original constraints

Example Input
1
2 3
1 4 3
7 1 4
3
1 2 4
1 1 5
2 2 5
Example Output
Yes
No
Yes
Explanation
Example case 1: The first query does not change the Horoscope Matrix. After this query, the matrix is good because all diagonals contain only equal elements (in the order from the top right diagonal to the bottom left diagonal, they are 3, 4, 1 and 7).

###################################################################################Solution######################################################################################
*/

// Problem: Horoscope Matrix
// Contest: CodeChef - December Lunchtime 2020 Division 2
// URL: https://www.codechef.com/LTIME91B/problems/HRSCPMTR
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

bool precompute(map<int,vector<int>>& m,int ind){
	vector<int>& v=m[ind];
	for(int i=1;i<(int)v.size();i++){
		if(v[i]!=v[i-1]){
			// cout<<v[i-1]<<"\n";
			return false;
		}
	}
	return true;		
}

bool check(map<int,vector<int>>& m,map<int,bool>& table,int ind){
	for(auto p:table){
		if(!p.s){
			return false;
		}
	}
	return true;
		
}

int main(){
	int T;
	cin>>T;
	int N,M;
	while(T--){
		cin>>N>>M;
		map<int,vector<int>> m;
		map<int,bool> table;
		for(int i=1;i<=N;i++){
			for(int j=1;j<=M;j++){
				int ind=i-j;
				int x;
				cin>>x;
				m[ind].push_back(x);
			}
		}
		
		int Q,x,y,v;
		cin>>Q;
		for(auto p:m){
			table[p.f]=precompute(m,p.f);
			// cout<<table[p.f]<<"\n";
		}
		for(int i=0;i<Q;i++){
			cin>>x>>y>>v;
			m[x-y][min(x,y)-1]=v;
			table[x-y]=precompute(m,x-y);
			if(check(m,table,x-y))
				cout<<"Yes\n";
			else
				cout<<"No\n";
		}
	}
	
	return 0;	
}
