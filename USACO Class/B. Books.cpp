/*
When Valera has got some free time, he goes to the library to read some books. Today he's got t free minutes to read. That's why Valera took n books in the library and for each book he estimated the time he is going to need to read it. Let's number the books by integers from 1 to n. Valera needs ai minutes to read the i-th book.

Valera decided to choose an arbitrary book with number i and read the books one by one, starting from this book. In other words, he will first read book number i, then book number i + 1, then book number i + 2 and so on. He continues the process until he either runs out of the free time or finishes reading the n-th book. Valera reads each book up to the end, that is, he doesn't start reading the book if he doesn't have enough free time to finish reading it.

Print the maximum number of books Valera can read.

Input
The first line contains two integers n and t (1 ≤ n ≤ 105; 1 ≤ t ≤ 109) — the number of books and the number of free minutes Valera's got. The second line contains a sequence of n integers a1, a2, ..., an (1 ≤ ai ≤ 104), where number ai shows the number of minutes that the boy needs to read the i-th book.

Output
Print a single integer — the maximum number of books Valera can read.

Examples
inputCopy
4 5
3 1 2 1
outputCopy
3
inputCopy
3 3
2 2 3
outputCopy
1

#############################################################################Solution##############################################################################################
*/


// Problem: B. Books
// Contest: Codeforces - Codeforces Round #171 (Div. 2)
// URL: http://codeforces.com/problemset/problem/279/B
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
	int N, T;
	cin>>N>>T;
	
	long arr[N+1]={0};
	for(int i=1;i<=N;i++)
		cin>>arr[i];
		
	for(int i=1;i<=N;i++)
		arr[i]+=arr[i-1];
	int cnt=0;
	for(int i=1;i<=N;i++){
		int start=0;
		int end=i-1;
		while(start<=end){
			int mid = start+(end-start)/2;
			if(arr[i]-arr[mid]<=T){
				cnt = max(cnt,i-mid);
				end = mid-1;
			}else
				start = mid+1;
		}
	}
	cout<<cnt<<"\n";
	
	return 0;	
}
