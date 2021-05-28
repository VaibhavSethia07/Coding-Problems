// Problem: Problem 3. Lasers and Mirrors
// Contest: USACO - USACO 2016 December Contest, Gold
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=671
// Memory Limit: 256 MB
// Time Limit: 4000 ms

#include <bits/stdc++.h>
#include <unordered_map>
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

int N,a,b;
const int MAXN=1e5+5;
pair<int,int> points[MAXN];
// lines[0] is vertical and lines[1] is horizontal
unordered_map<int,vector<int>> lines[2];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	freopen("lasers.in","r",stdin);
	freopen("lasers.out","w",stdout);
	
	cin>>N;
	for(int i=0;i<N+2;i++){
		cin>>points[i].f>>points[i].s;
		lines[0][points[i].f].push_back(i);
		lines[1][points[i].s].push_back(i);
	}
	
	// Each element of queue represents point number and its incoming direction
	// 0 Light was incident vertically
	// 1 Light was incident horizontally
	queue<pair<int,bool>> q;
	vector<long> dist(N+2,1e9);
	q.push({0,0});
	q.push({0,1});
	dist[0]=0;
	while(!q.empty()){
		int curr=q.front().f;
		bool beamdir=q.front().s;
		q.pop();
		bool dir=(beamdir)?0:1;
		int coord=(beamdir)?points[curr].f:points[curr].s;
		
		for(auto point:lines[dir][coord]){
			if(dist[point]==1e9){
				dist[point]=dist[curr]+1;
				q.push({point,dir});
			}
		}
	}
	
	if(dist[1]==1e9)
		cout<<-1;
	else
		cout<<dist[1]-1;
	return 0;	
}
