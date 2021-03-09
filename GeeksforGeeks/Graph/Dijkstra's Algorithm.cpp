#include <bits/stdc++.h>
using namespace std;

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
const int MAXN=1e5+5;
int V,E,a,b,w;
vector<pair<int,int>> adj[MAXN];
void input(){
	cin>>V>>E;
	for(int i=0;i<E;i++){
		cin>>a>>b>>w;
		adj[a].push_back({b,w});
	}
}

void solve(){
	vector<int> dist(V+1,1e9);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	
	dist[1]=0;
	pq.push({0,1});
	
	while(!pq.empty()){
		int u=pq.top().second;
		int d=pq.top().first;
		pq.pop();
		for(pair<int,int>& edge:adj[u]){
			if(d+edge.second<dist[edge.first]){
				dist[edge.first]=d+edge.second;
				pq.push({dist[edge.first],edge.first});
			}
		}
	}
	
	for(int i=2;i<=V;i++)
		cout<<dist[i]<<" ";
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
	input();
	solve();
	return 0;	
}
