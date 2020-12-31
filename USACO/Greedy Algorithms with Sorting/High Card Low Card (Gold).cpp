/*
Bessie the cow is a huge fan of card games, which is quite surprising, given her lack of opposable thumbs. Unfortunately, none of the other cows in the herd are good opponents. They are so bad, in fact, that they always play in a completely predictable fashion! Nonetheless, it can still be a challenge for Bessie to figure out how to win.
Bessie and her friend Elsie are currently playing a simple card game where they take a deck of 2N cards, conveniently numbered 1…2N, and divide them into N cards for Bessie and N cards for Elsie. The two then play N rounds, where in each round Bessie and Elsie both play a single card. In the first N/2 rounds, the player with the highest card earns a point, and in the last N/2 rounds, the rules switch and the player who plays the lowest card wins a point.

Given that Bessie can predict the order in which Elsie will play her cards, please determine the maximum number of points Bessie can win.

INPUT FORMAT (file cardgame.in):
The first line of input contains the value of N (2≤N≤50,000; N will be even).
The next N lines contain the cards that Elsie will play in each of the successive rounds of the game. Note that it is easy to determine Bessie's cards from this information.

OUTPUT FORMAT (file cardgame.out):
Output a single line giving the maximum number of points Bessie can score.
SAMPLE INPUT:
4
1
8
4
3

SAMPLE OUTPUT:
2
Here, Bessie must have cards 2, 5, and 6, and 7 in her hand, and she can use these to win at most 2 points, by saving her '2' card until one of the hands in the second half of the game.

Problem credits: Brian Dean

###############################################################################Solution############################################################################################
*/

// Problem: Problem 1. High Card Low Card (Gold)
// Contest: USACO - USACO 2015 December Contest, Gold
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=573
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

int ub(vi bessie1,int x){
	int start=0,end=(int)bessie1.size()-1,ans=-1;
	while(start<=end){
		int mid=start+(end-start)/2;
		if(bessie1[mid]>=x){
			ans=mid;
			end=mid-1;
		}else
			start=mid+1;
	}
	return ans;
}

int lb(vi bessie2,int x){
	int start=0,end=(int)bessie2.size()-1,ans=-1;
	while(start<=end){
		int mid=start+(end-start)/2;
		if(bessie2[mid]<=x){
			ans=mid;
			start=mid+1;
		}else
			end=mid-1;
	}
	return ans;
}

void solve(int N){
	vector<bool> cards(2*N);
	vector<int> bessie1,bessie2,elsie1,elsie2;
	for(int i=0;i<N;i++){
		int x;
		cin>>x;
		x--;
		if(i<N/2)
			elsie1.push_back(x);
		else
			elsie2.push_back(x);
		cards[x]=1;
	}
	sort(elsie1.begin(),elsie1.end());
	sort(elsie2.begin(),elsie2.end());
	for(int i=0;i<2*N;i++){
		if(!cards[i]){
			if((int)bessie2.size()<N/2)
				bessie2.push_back(i);
			else
				bessie1.push_back(i);
		}
	}
	long ans=0;
	for(auto& x:elsie1){
		int ind=ub(bessie1,x);
		if(ind!=-1){
			bessie1.erase(bessie1.begin()+ind);
			ans++;
		}else{
			bessie1.erase(bessie1.begin());
		}
	}

	for(auto& x:elsie2){
		int ind=lb(bessie2,x);
		if(ind!=-1){
			ans++;
			bessie2.erase(bessie2.begin()+ind);
		}else{
			int L=(int)bessie2.size()-1;
			bessie2.erase(bessie2.begin()+L);
		}
	}
	cout<<ans<<"\n";
}

int main(){
	freopen("cardgame.in","r",stdin);
	freopen("cardgame.out","w",stdout);
	
	int N;
	cin>>N;
	solve(N);
	
	return 0;	
}
