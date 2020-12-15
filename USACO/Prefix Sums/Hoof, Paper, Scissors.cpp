/*
You have probably heard of the game "Rock, Paper, Scissors". The cows like to play a similar game they call "Hoof, Paper, Scissors".
The rules of "Hoof, Paper, Scissors" are simple. Two cows play against each-other. They both count to three and then each simultaneously makes a gesture that represents either a hoof, a piece of paper, or a pair of scissors. Hoof beats scissors (since a hoof can smash a pair of scissors), scissors beats paper (since scissors can cut paper), and paper beats hoof (since the hoof can get a papercut). For example, if the first cow makes a "hoof" gesture and the second a "paper" gesture, then the second cow wins. Of course, it is also possible to tie, if both cows make the same gesture.

Farmer John wants to play against his prize cow, Bessie, at N games of "Hoof, Paper, Scissors" (1≤N≤100,000). Bessie, being an expert at the game, can predict each of FJ's gestures before he makes it. Unfortunately, Bessie, being a cow, is also very lazy. As a result, she tends to play the same gesture multiple times in a row. In fact, she is only willing to switch gestures at most once over the entire set of games. For example, she might play "hoof" for the first x games, then switch to "paper" for the remaining N−x games.

Given the sequence of gestures FJ will be playing, please determine the maximum number of games that Bessie can win.

INPUT FORMAT (file hps.in):
The first line of the input file contains N.
The remaining N lines contains FJ's gestures, each either H, P, or S.

OUTPUT FORMAT (file hps.out):
Print the maximum number of games Bessie can win, given that she can only change gestures at most once.
SAMPLE INPUT:
5
P
P
H
P
S
SAMPLE OUTPUT:
4
Problem credits: Mark Chen and Brian Dean

##########################################################################################Solution#################################################################################
*/


// Problem: Problem 2. Hoof, Paper, Scissors
// Contest: USACO - USACO 2017 January Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=691
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
	freopen("hps.in","r",stdin);
	freopen("hps.out","w",stdout);
	
	int N;
	cin>>N;
	vector<char> matches(N);
	for(int i=0;i<N;i++)
		cin>>matches[i];
	
	vector<vector<long>> prefix(3);
	vector<vector<long>> suffix(3);
	
	for(int i=0;i<3;i++){
		prefix[i] = vector<long>(N+1,0);
		suffix[i] = vector<long>(N+1,0);
	}
// 	SPH order
// fj->P bs->S
// fj->H bs->P
// fj->S bs->H
	for(int i=1;i<=N;i++){
		char fj = matches[i-1];
		for(int j=0;j<3;j++){
			prefix[j][i]=prefix[j][i-1];
			if(fj=='P' && j==0)
				prefix[j][i]+=1;
			else if(fj=='H' && j==1)
				prefix[j][i]+=1;
			else if(fj=='S' && j==2)
				prefix[j][i]+=1;
		}
	}
	
// 	SPH order
	for(int i=N-1;i>=0;i--){
		char fj = matches[i];
		for(int j=0;j<3;j++){
			suffix[j][i]=suffix[j][i+1];
			if(fj=='P' && j==0)
				suffix[j][i]+=1;
			else if(fj=='H' && j==1)
				suffix[j][i]+=1;
			else if(fj=='S' && j==2)
				suffix[j][i]+=1;
		}
	}
	long mx=0;
	for(int i=1;i<=N;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				mx=max(mx,prefix[j][i]+suffix[k][i]);
			}
		}
	}
	
	cout<<mx<<"\n";
	
	return 0;	
}
