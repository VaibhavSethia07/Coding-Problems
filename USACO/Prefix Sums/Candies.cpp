/*
Problem
Carl has an array of N candies. The i-th element of the array (indexed starting from 1) is Ai representing sweetness value of the i-th candy. He would like to perform a series of Q operations. There are two types of operation:

Update the sweetness value of a candy in the array.
Query the sweetness score of a subarray.
The sweetness score of a subarray from index l to r is: Al × 1 - Al+1 × 2 + Al+2 × 3 - Al+3 × 4 + Al+4 × 5 ...

More formally, the sweetness score is the sum of (-1)i-lAi × (i - l + 1), for all i from l to r inclusive.

For example, the sweetness score of:

[3, 1, 6] is 3 × 1 - 1 × 2 + 6 × 3 = 19
[40, 30, 20, 10] is 40 × 1 - 30 × 2 + 20 × 3 - 10 × 4 = 0
[2, 100] is 2 × 1 - 100 × 2 = -198
Carl is interested in finding out the total sum of sweetness scores of all queries. If there is no query operation, the sum is considered to be 0. Can you help Carl find the sum?

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing N and Q. The second line contains N integers describing the array. The i-th integer is Ai. The j-th of the following Q lines describe the j-th operation. Each line begins with a single character describing the type of operation (U for update, Q for query).

For an update operation, two integers Xj and Vj follow, indicating that the Xj-th element of the array is changed to Vj.
For a query operation, two integers Lj and Rj follow, querying the sweetness score of the subarray from the Lj-th element to the Rj-th element (inclusive).
Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the total sum of sweetness scores of all the queries.

Limits
Time limit: 20 seconds per test set.
Memory limit: 1GB.
1 ≤ T ≤ 100.
1 ≤ Ai ≤ 100, for all i.
1 ≤ N ≤ 2 × 105 and 1 ≤ Q ≤ 105 for at most 6 test cases.
For the remaining cases, 1 ≤ N ≤ 300 and 1 ≤ Q ≤ 300.
If the j-th operation is an update operation, 1 ≤ Xj ≤ N and 1 ≤ Vj ≤ 100.
If the j-th operation is a query operation, 1 ≤ Lj ≤ Rj ≤ N.
Test set 1
There will be at most 5 update operations.

Test set 2
There are no special constraints.

Sample

Input
 	
Output
 
2
5 4
1 3 9 8 2
Q 2 4
Q 5 5
U 2 10
Q 1 2
3 3
4 5 5
U 1 2
U 1 7
Q 1 2

  
Case #1: -8
Case #2: -3

  
In sample case #1:

The first query asks for the sweetness score of [3, 9, 8] which is 3 × 1 - 9 × 2 + 8 × 3 = 9.
The second query asks for the sweetness score of [2] which is 2 × 1 = 2.
The third query asks for the sweetness score of [1, 10] which is 1 × 1 - 10 × 2 = -19.
Thus, the final output should be 9 + 2 - 19 = -8.
In sample case #2:

The first and only query asks for the sweetness score of [7, 5] which is 7 × 1 - 5 × 2 = -3.
Thus, the final output should be -3.

###############################################################################Solution##########################################################################################
*/


// Problem: Candies
// Contest: Google Coding Competitions - Round C 2020 - Kick Start 2020
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/0000000000337b4d
// Memory Limit: 1024 MB
// Time Limit: 20000 ms
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

void update(vector<long>& v,vector<long>& prefix,vector<long>& iprefix,int N){
	for(int i=1;i<=N;i++){
			prefix[i]=prefix[i-1];
			iprefix[i]=iprefix[i-1];
			if(((i+1)&1)==1){
				iprefix[i]-=i*v[i];
				prefix[i]-=v[i];
			}
			else{
				iprefix[i]+=i*v[i];
				prefix[i]+=v[i];
			}
		}
}

int main(){
	int T,N,Q;
	
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>N>>Q;
		long long total_sweetness=0;
		vector<long> v(N+1,0);
		vector<long> prefix(N+1,0);
		vector<long> iprefix(N+1,0);
		
		for(int i=1;i<=N;i++){
			cin>>v[i];
		}
		
		update(v,prefix,iprefix,N);
		
		for(int q=1;q<=Q;q++){
			char op;
			int l,r;
			cin>>op;
			if(op=='Q'){
				cin>>l>>r;
				long ips = iprefix[r]-iprefix[l-1];
				long ps = (l-1)*(prefix[r]-prefix[l-1]);
				ips-=ps;
				if(((l+1)&1)==1)
					ips*=-1;
					
				total_sweetness+=ips;
			}else if(op=='U'){
				cin>>l>>r;
				v[l]=r;
				update(v,prefix,iprefix,N);
			}
		}
		cout<<"Case #"<<t<<": "<<total_sweetness<<"\n";	
	}
	return 0;	
}
