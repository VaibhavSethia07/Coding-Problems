// Problem: Problem 3. Build Gates
// Contest: USACO - USACO 2016 January Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=596
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

/* These template codes have been taken from cp-algorithms */
ll extEuclid(ll a,ll b,ll& x,ll& y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	
	ll x1,y1;
	ll d=extEuclid(b,a%b,x1,y1);
	x=y1;
	y=x1-(a/b)*y1;
	return d;
}

ll modInverse(ll a,ll n){
	ll x,y;
	extEuclid(a,n,x,y);
	return x;
}

ll linearCong(ll a,ll b,ll n){
	ll d=__gcd(a,n);
	
	if(b%d)
		return -1;
	a/=d;b/=d;n/=d;
	ll a_inv=modInverse(a,n);
	ll ans=(b*a_inv)%n;
	if(ans<0)
		ans+=n;
	return ans;
}

void divisors(map<int,int>& d,ll N){
	for(int div : {2,3,5}){
		int cnt=0;
		if(N%div==0){
			while((N%div)==0){
				N/=div;
				cnt++;
			}
			d[div]=cnt;
		}
	}
	static array<int,8> increments = {4,2,4,2,4,6,2,6};
	int i=0;
	for(ll div=7;div*div<=N;div+=increments[i++]){
		if((N%div)==0){
			int cnt=0;
			while((N%div)==0){
				N/=div;
				cnt++;
			}
			d[div]=cnt;
		}
		if(i==8)
			i=0;
	}
	if(N>1)
		d[N]=1;
}

/* Print the string of digits without leading zero */
void norm(string& str){
	bool zero=true;
	
	for(auto& c:str){
		if(c!='0')
			zero=false;
		if(c!='0' || !zero)
			cout<<c;
	}
}

void input(vl& v,int N){
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
}

int N;
string S;
const int MAX=4e3+5;
int adj[MAX][MAX];
int vis[MAX][MAX];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int minX=2001,maxX=2001,minY=2001,maxY=2001;

void update(int i,int& x,int& y){
	int dirX=0,dirY=0;
	if(S[i]=='N')
		dirX=-1;
	else if(S[i]=='S')
		dirX=1;
	else if(S[i]=='E')
		dirY=1;
	else
		dirY=-1;
		
	for(int a=0;a<2;a++){
		x+=dirX;
		y+=dirY;
		adj[x][y]=1;
	}
}

void build_fence(){
	int x=2001,y=2001;
	adj[x][y]=1;
	for(int i=0;i<N;i++){
		update(i,x,y);
		
		minX=min(minX,x);
		maxX=max(maxX,x);
		
		minY=min(minY,y);
		maxY=max(maxY,y);
	}
}

void flood_fill(int x,int y){
	stack<pair<int,int>> st;
	st.push({x,y});
	
	while(!st.empty()){
		x=st.top().f;
		y=st.top().s;
		st.pop();
		
		if(x<minX || x>maxX || y<minY || y>maxY || vis[x][y] || adj[x][y])
			continue;
		
		vis[x][y]=1;
		for(int i=0;i<4;i++)
			st.push({x+dx[i],y+dy[i]});
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("gates.in","r",stdin);
	freopen("gates.out","w",stdout);
    
	cin>>N>>S;
	build_fence();
	
	int ans=-1;
	minX--;maxX++,minY--,maxY++;
	for(int i=minX;i<=maxX;i++){
		for(int j=minY;j<=maxY;j++){
			if(!vis[i][j] && adj[i][j]==0){
				ans++;
				flood_fill(i,j);
			}
		}
	}

	cout<<ans;
	return 0;	
}
