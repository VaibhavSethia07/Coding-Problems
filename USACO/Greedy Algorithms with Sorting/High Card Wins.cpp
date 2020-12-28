/*
Bessie the cow is a huge fan of card games, which is quite surprising, given her lack of opposable thumbs. Unfortunately, none of the other cows in the herd are good opponents. They are so bad, in fact, that they always play in a completely predictable fashion! Nonetheless, it can still be a challenge for Bessie to figure out how to win.
Bessie and her friend Elsie are currently playing a simple card game where they take a deck of 2N cards, conveniently numbered 1…2N, and divide them into N cards for Bessie and N cards for Elsie. The two then play N rounds, where in each round Bessie and Elsie both play a single card, and the player with the highest card earns a point.

Given that Bessie can predict the order in which Elsie will play her cards, please determine the maximum number of points Bessie can win.

INPUT FORMAT (file highcard.in):
The first line of input contains the value of N (1≤N≤50,000).
The next N lines contain the cards that Elsie will play in each of the successive rounds of the game. Note that it is easy to determine Bessie's cards from this information.

OUTPUT FORMAT (file highcard.out):
Output a single line giving the maximum number of points Bessie can score.
SAMPLE INPUT:
3
1
6
4
SAMPLE OUTPUT:
2
Here, Bessie must have cards 2, 3, and 5 in her hand, and she can use these to win at most 2 points by saving the 5 until the end to beat Elsie's 4.

Problem credits: Austin Bannister and Brian Dean

################################################################################Solution###########################################################################################
*/

// Problem: Problem 2. High Card Wins
// Contest: USACO - USACO 2015 December Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=571
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

int upper(vector<int> v,int x){
	int start=0,ans=-1;
	int end=(int)v.size();
	while(start<=end){
		int mid=start+(end-start)/2;
		if(v[mid]>=x){
			ans=mid;
			end=mid-1;
		}else
			start=mid+1;
	}
	return ans;
}

int main(){
	freopen("highcard.in","r",stdin);
	freopen("highcard.out","w",stdout);
	
	int N;
	cin>>N;
	bool cards[2*N+1];
	vector<int> elsie(N);
	vector<int> bessie(N);
	for(int i=0;i<N;i++){
		cin>>elsie[i];
		cards[elsie[i]]=1;
	}
	for(int i=1;i<=2*N;i++){
		if(!cards[i])
			bessie.push_back(i);
	}
	long long ans=0;
	for(int i=0;i<N;i++){
		int it=upper(bessie,elsie[i]);
		if(it!=-1){
			ans++;
			bessie.erase(bessie.begin()+it);
		}
	}
	cout<<ans<<"\n";
	
	return 0;	
}
