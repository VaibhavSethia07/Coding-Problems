
// Problem: E - Through Path
// Contest: AtCoder - AtCoder Beginner Contest 187
// URL: https://atcoder.jp/contests/abc187/tasks/abc187_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

void divisors(map<int,int>& d,ll N){
	for(int div : {2,3,5}){
		int cnt=1;
		if(N%2==0){
			while((N%2)==0){
				N/=2;
				cnt++;
			}
			d[div]=cnt;
		}
	}
	static array<int,8> increments = {4,2,4,2,4,6,2,6};
	int i=0;
	for(ll div=7;div*div<=N;div+=increments[i++]){
		if((N%div)==0){
			int cnt=1;
			while((N%i)==0){
				N/=i;
				cnt++;
			}
			d[i]=cnt;
		}
		if(i==8)
			i=0;
	}
	if(N>1)
		d[N]=2;
}

void input(vl& v,int N){
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
}

void solve(vl& v,int N){
	
}

int main(){
	int N,a,b;
	cin>>N;
	vector<pair<ll,ll>> edges(N-1);
	vector<vector<ll>> g(N);
	vector<int> depth(N,-1);
	for(int i=0;i<N-1;i++){
		cin>>a>>b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
		edges[i]={a,b};
	}
	depth[0]=0;
	vector<ll> q={0};
	while(q.size()){
		ll curr=q.back();
		q.pop_back();
		for(auto c:g[curr]){
			if(depth[c]==-1){
				depth[c]=depth[curr]+1;
				q.push_back(c);
			}
		}
	}
	
	int Q,t,e,x;
	vector<ll> s(N);
	cin>>Q;
	for(int q=0;q<Q;q++){
		cin>>t>>e>>x;
		a=edges[e-1].f;
		b=edges[e-1].s;
		
		if(depth[a]>depth[b]){
			swap(a,b);
			t^=3;
		}
		if(t==1){
			s[0]+=x;
			s[b]-=x;
		}else
			s[b]+=x;
	}
	q.push_back(0);
	while(q.size()){
		ll curr=q.back();
		q.pop_back();
		for(auto c:g[curr]){
			if(depth[curr]<depth[c]){
				q.push_back(c);
				s[c]+=s[curr];
			}	
		}
	}
	
	for(auto& x:s)
		cout<<x<<"\n";
	
	return 0;	
}
