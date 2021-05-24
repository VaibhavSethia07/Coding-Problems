// Problem: Problem 3. Why Did the Cow Cross the Road III
// Contest: USACO - USACO 2017 February Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=716
// Memory Limit: 256 MB
// Time Limit: 4000 ms

#include <bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using l = long;
using ll = long long;
using ld = long double;
using db = double;
using str = string;

using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vl = vector<long>;
using vll = vector<ll>;

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
#define modinv(a,m) modEx(a,m-2,m)
#define moddiv(a,b,m) (a*modinv(b,m))%m
const ll mod=1e9+7;

set<vector<int>> roads;
const int MAXN=101;
int farm[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int N,K,R,xx1,yy1,xx2,yy2;

int ff(int x,int y){
	stack<pair<int,int>> st;
	st.push({x,y});
	int cow=0;
	while(!st.empty()){
		xx1=st.top().f;
		yy1=st.top().s;
		st.pop();
		if(xx1<=0 || xx1>N || yy1<=0 || yy1>N || vis[xx1][yy1])
			continue;
		
		// We meet a cow
		if(farm[xx1][yy1]==1){
			cow++;
		}
		vis[xx1][yy1]=1;
		
		for(int i=0;i<4;i++){
			xx2=xx1+dx[i],yy2=yy1+dy[i];
			if(xx1<=0 || xx1>N || yy1<=0 || yy1>N ||roads.count({xx1,yy1,xx2,yy2}) || roads.count({xx2,yy2,xx1,yy1})){
				continue;
			}
			st.push({xx2,yy2});
		}
	}
	return K-cow;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	freopen("countcross.in","r",stdin);
	freopen("countcross.out","w",stdout);
	
	cin>>N>>K>>R;
	for(int i=0;i<R;i++){
		cin>>xx1>>yy1>>xx2>>yy2;
		roads.insert({xx1,yy1,xx2,yy2});
	}
	
	vector<pair<int,int>> cows(K);
	int ans=0;
	for(int i=0;i<K;i++){
		cin>>xx1>>yy1;
		farm[xx1][yy1]=1;
		cows[i]={xx1,yy1};
	}
	
	for(int i=0;i<K;i++){
		memset(vis,0,sizeof(vis));
		ans+=ff(cows[i].f,cows[i].s);
	}
	cout<<ans/2;
	
	return 0;	
}
