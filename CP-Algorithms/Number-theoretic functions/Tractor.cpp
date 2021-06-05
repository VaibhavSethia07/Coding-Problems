// Problem: Problem 2. Tractor
// Contest: USACO - USACO 2013 February Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=245
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

int mat[505][505];
bool vis[505][505];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int N;

int ff(int x,int y,int minCost){
	
	vis[x][y]=1;
	int cnt=1;
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>=0 && xx<N && yy>=0 && yy<N && abs(mat[x][y]-mat[xx][yy])<=minCost && !vis[xx][yy])
			cnt+=ff(xx,yy,minCost);
	}
	return cnt;
}

bool isValid(int minCost){
	memset(vis,0,sizeof(vis));
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(!vis[i][j]){
				int count=ff(i,j,minCost);
				if(count*2>=N*N)
					return true;
			}
		}
	}
	return false;
}
const int MAXN=5e5+5;
int par[MAXN];
int sz[MAXN];

void make_par(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			par[i*N+j]=i*N+j;
			sz[i*N+j]=1;
		}
	}
}

int find(int x){
	vector<int> anc;
	
	while(x!=par[x]){
		anc.pb(x);
		x=par[x];
	}
	
	for(int i=0;i<(int)anc.size();i++)
		par[anc[i]]=x;
	return x;
}

void unite(int a,int b){
	if(find(a)==find(b))
		return;
		
	a=find(a),b=find(b);
	if(sz[b]>sz[a])
		swap(a,b);
	par[b]=a;
	sz[a]+=sz[b];
}

bool cmp(vector<int>& v1,vector<int>& v2){
	return v1[2]<v2[2];
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	freopen("tractor.in","r",stdin);
	freopen("tractor.out","w",stdout);
	
	// Binary Search on answer and DFS
	cin>>N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin>>mat[i][j];
			
	
	int start=0,end=1e9,ans=0;
	while(start<=end){
		int minCost=start+(end-start)/2;
		if(isValid(minCost)){
			ans=minCost;
			end=minCost-1;
		}else
			start=minCost+1;
	}
	cout<<ans;
	
	// Hashing + DSU
	cin>>N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin>>mat[i][j];
			
	make_par();
	vector<vector<int>> edges;
	for(int r=0;r<N;r++){
		for(int c=0;c<N;c++){
			for(int i=0;i<4;i++){
				int rr=r+dx[i];
				int cc=c+dy[i];
				if(rr<0 || rr>=N || cc<0 || cc>=N)
					continue;
				edges.pb({r*N+c,rr*N+cc,abs(mat[rr][cc]-mat[r][c])});
			}
		}
	}
	
	sort(all(edges),cmp);
	int ans=0;
	for(int i=0;i<(int)edges.size();i++){
		vector<int> e=edges[i];
		ans=max(ans,e[2]);
		unite(e[0],e[1]);
		
		if(sz[find(e[0])]*2>=N*N)
			break;
		
	}
	cout<<ans;
	return 0;	
}
