/*
You are given n cubes in a certain order, and your task is to build towers using them. Whenever two cubes are one on top of the other, the upper cube must be smaller than the lower cube.

You must process the cubes in the given order. You can always either place the cube on top of an existing tower, or begin a new tower. What is the minimum possible number of towers?

Input

The first input line contains an integer n: the number of cubes.

The next line contains n integers k1,k2,…,kn: the sizes of the cubes.

Output

Print one integer: the minimum number of towers.

Constraints
1≤n≤2⋅105
1≤ki≤109
Example

Input:
5
3 8 2 1 5

Output:
2

##############################################################################Solution#############################################################################################
*/

// Problem: Towers
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1073
// Memory Limit: 512 MB
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

int ceiling(vector<int>& towers,int x){
	if(towers.empty())
		return -1;
	int start=0,end=(int)towers.size()-1,ans=-1;
	while(start<=end){
		int mid=start+(end-start)/2;
		if(towers[mid]>x){
			ans=mid;
			end=mid-1;
		}else
			start=mid+1;
	}
	return ans;
}

int main(){
	vector<int> towers;
	int n;
	cin>>n;
	long ans=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		int ind=ceiling(towers,x);
		if(ind==-1){
			towers.push_back(x);
			ans++;
		}
		else
			towers[ind]=x;
		
	}
	cout<<ans<<"\n";
	
	return 0;	
}
