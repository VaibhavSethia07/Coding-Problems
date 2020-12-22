/*
There are N cars (numbered 1 through N) on a circular track with length N. For each i (2≤i≤N), the i-th of them is at a distance i−1 clockwise from car 1, i.e. car 1 needs to travel a distance i−1 clockwise to reach car i. Also, for each valid i, the i-th car has fi litres of gasoline in it initially.

You are driving car 1 in the clockwise direction. To move one unit of distance in this direction, you need to spend 1 litre of gasoline. When you pass another car (even if you'd run out of gasoline exactly at that point), you steal all its gasoline. Once you do not have any gasoline left, you stop.

What is the total clockwise distance travelled by your car?

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers f1,f2,…,fN.
Output
For each test case, print a single line containing one integer ― the total clockwise distance travelled.

Constraints
1≤T≤100
1≤N≤100
0≤fi≤100 for each valid i
Subtasks
Subtask #1 (100 points): original constraints

Example Input
3
5
3 0 0 0 0
5
1 1 1 1 1
5
5 4 3 2 1
Example Output
3
5
15

###################################################################################Solution######################################################################################
*/


// Problem: Gasoline Introduction
// Contest: CodeChef - November Lunchtime 2020 Division 2
// URL: https://www.codechef.com/LTIME90B/problems/BEGGASOL
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	
	while(T--){
		int N;
		cin>>N;
		vector<long> v(N);
		for(int i=0;i<N;i++)
			cin>>v[i];
		long g=v[0];
		if(g==0){
			cout<<0<<"\n";
			continue;
		}
		long dist=0;
		int i=0;
		do{
			i++;
			if(i%N==0){
				cout<<dist+g<<"\n";
				break;
			}
			g+=v[i]-1;
			dist++;
			if(g==0){
				cout<<dist<<"\n";
				break;
			}
		}while((i%N)!=0);
	}
	
	return 0;	
}
