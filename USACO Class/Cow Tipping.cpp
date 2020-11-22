/*
Farmer John occasionally has trouble with bored teenagers who visit his farm at night and tip over his cows. One morning, he wakes up to find it has happened again -- his N2 cows began the night grazing in a perfect N×N square grid arrangement (1≤N≤10), but he finds that some of them are now tipped over.
Fortunately, Farmer John has used parts from his tractor and forklift to build a glorious machine, the Cow-Untipperator 3000, that can flip over large groups of cows all at once, helping him put all his cows back on their feet as quickly as possible. He can apply the machine to any "upper-left rectangle" in his grid of cows -- a rectangular sub-grid that contains the upper-left cow. When he does so, the machine flips over every cow in this rectangle, placing tipped cows back on their feet, but unfortunately also tipping over cows that were already on their feet! In other words, the machine "toggles" the state of each cow in the rectangle.

Farmer John figures that by applying his machine sufficiently many times to the appropriate collection of rectangles, he can eventually restore all the cows to their rightful, un-tipped states. Please help him determine the minimum number of applications of his machine needed to do this.

Note that applying the machine to the same rectangle twice would be pointless, since this would have no net impact on the cows in the rectangle. Therefore, you should only consider applying the machine to each upper-left rectangle possibly only once.

INPUT FORMAT (file cowtip.in):
The first line of the input is the integer N.
Each of the N subsequent lines contains a string of N characters, each either 0 (representing an up-tipped cow) or 1 (representing a tipped cow).

OUTPUT FORMAT (file cowtip.out):
Please output the minimum number of times Farmer John needs to apply the Cow-Untipperator 3000 to restore all his cows to their feet.
SAMPLE INPUT:
3
001
111
111
SAMPLE OUTPUT:
2
In this example, if FJ applies his machine to the entire herd of cows (which is a valid upper-left rectangle), he will toggle their state to the following:

110
000
000
All that remains is to apply the machine to the upper-left rectangle containing the two 1s, and he is finished. In total, this is just 2 applications.

Problem credits: Nathan Pinsker

###############################################################################Solution############################################################################################
*/

// Problem: Problem 3. Cow Tipping
// Contest: USACO - USACO 2017 January Contest, Bronze
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=689
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

void swap(int** mat,int a,int b){
	for(int i=0;i<=a;i++){
		for(int j=0;j<=b;j++){
			mat[i][j]=1^mat[i][j];
		}
	}
}

int tipping(int** mat,int i,int N){
	if(i<0)
		return 0;
	int count=0;
	for(int j=N-1;j>=0;j--){
		if(mat[i][j]==1){
			count++;
			swap(mat,i,j);
		}
	}
	return count+tipping(mat,i-1,N);
}

int main(){
	freopen("cowtip.in","r",stdin);
	freopen("cowtip.out","w",stdout);
	
	int N;
	cin>>N;
	int* mat[N];
	for(int i=0;i<N;i++){
		mat[i] = new int[N];
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			char x;
			cin>>x;
			mat[i][j] = x-'0';
		}
	}
	cout<<tipping(mat,N-1,N);
}
