// Problem: Problem 2. Telephone
// Contest: USACO - USACO 2021 January Contest, Gold
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=1090
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

int N,K;
char ch;
const int MAXN=5e5+5;
int cowBreed[MAXN];
vector<int> cowBreedList[MAXN];
int isReachable[51][51];
bool vis[MAXN];
ll distanceFromOne[MAXN];
priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;

void insert(ll v,ll u){
	if(!vis[v]){
		ll d=distanceFromOne[u]+abs(v-u);
		if(distanceFromOne[v]>d){
			distanceFromOne[v]=d;
			pq.push({distanceFromOne[v],v});
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin>>N>>K;
		
	for(int i=1;i<=N;i++){
		cin>>cowBreed[i];
		cowBreedList[cowBreed[i]].push_back(i);
		distanceFromOne[i]=LLONG_MAX;
	}
	
	for(int i=1;i<=K;i++){
		for(int j=1;j<=K;j++){
			cin>>ch;
			isReachable[i][j]=(ch=='1');
		}
	}
	
	pq.push({0,1});
	distanceFromOne[1]=0;
	vis[1]=1;
	ll ans=LLONG_MAX;
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		
		
		if(u==N)
			ans=min(ans,distanceFromOne[u]);
			
		// Special Case
		if(isReachable[cowBreed[u]][cowBreed[N]]){
			ans=min(ans,distanceFromOne[u]+N-u);
		}
		
		vis[u]=1;
		for(int kk=1;kk<=K;kk++){
			if(!isReachable[cowBreed[u]][kk])
				continue;
			
			auto it=upper_bound(all(cowBreedList[kk]),u);
			if(it!=cowBreedList[kk].end())
				insert(*it,u);
			int left=0;
			if(cowBreed[u]==kk){
				if(it-cowBreedList[kk].begin()>=2)
					left=*(it-2);
			}else{
				if(it!=cowBreedList[kk].begin())
					left=*(it-1);
			}
			
			if(left!=0)
				insert(left,u);
		}
	}
	
	if(ans==LLONG_MAX)
		cout<<-1;
	else
		cout<<ans;
	
	return 0;	
}
