// Problem: CCC '20 S2 - Escape Room
// Contest: DMOJ
// URL: https://dmoj.ca/problem/ccc20s2
// Memory Limit: 512 MB
// Time Limit: 2000 ms

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

int n,m;
const int MAXN=1e3+5;
int grid[MAXN][MAXN];
bool vis[MAXN][MAXN];
vector<int> todo[1000005];
bool done[1000005];

bool go(){
	stack<pair<int,int>> st;
	st.push({1,1});
	
	while(!st.empty()){
		int x=st.top().f;
		int y=st.top().s;
		st.pop();
		
		if(x<1 || x>m || y<1 || y>n || vis[x][y])
			continue;
		if(x==m && y==n)
			return true;
		vis[x][y]=1;
		
		vector<int> dx;
		vector<int> dy;
		
		for(int i=1;i*i<=grid[x][y];i++){
			if((grid[x][y]%i)==0){
				dx.pb(i);
				dy.pb(grid[x][y]/i);
				if(i!=grid[x][y]/i){
					dy.pb(i);
					dx.pb(grid[x][y]/i);
				}
			}
		}
		for(int i=0;i<(int)dx.size();i++){
			x=dx[i],y=dy[i];
			if(x<1 || x>m || y<1 || y>n || vis[x][y])
				continue;
			st.push({dx[i],dy[i]});
		}
	}
	return false;
}

void dfs(int x){
	if(done[x])
		return;
	
	
	if(x==n*m){
		cout<<"yes\n";
		exit(0);
	}
	done[x]=1;
	for(auto& t:todo[x]){
		dfs(t);
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>m>>n;
    for(int i=1;i<=m;i++){
    	for(int j=1;j<=n;j++){
    		cin>>grid[i][j];
    	}
    }
    if(go())
    	cout<<"yes\n";
    else
    	cout<<"no\n";
    	
    /* Editorial Solution */
    cin>>m>>n;
    int x;
    for(int i=1;i<=m;i++){
    	for(int j=1;j<=n;j++){
    		cin>>x;
    		todo[i*j].pb(x);
    	}
    }
    dfs(1);
    cout<<"no\n";
	
	return 0;	
}
// Problem: CCC '20 S2 - Escape Room
// Contest: DMOJ
// URL: https://dmoj.ca/problem/ccc20s2
// Memory Limit: 512 MB
// Time Limit: 2000 ms

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

int n,m;
const int MAXN=1e3+5;
int grid[MAXN][MAXN];
bool vis[MAXN][MAXN];
vector<int> todo[1000005];
bool done[1000005];

bool go(){
	stack<pair<int,int>> st;
	st.push({1,1});
	
	while(!st.empty()){
		int x=st.top().f;
		int y=st.top().s;
		st.pop();
		
		if(x<1 || x>m || y<1 || y>n || vis[x][y])
			continue;
		if(x==m && y==n)
			return true;
		vis[x][y]=1;
		
		vector<int> dx;
		vector<int> dy;
		
		for(int i=1;i*i<=grid[x][y];i++){
			if((grid[x][y]%i)==0){
				dx.pb(i);
				dy.pb(grid[x][y]/i);
				if(i!=grid[x][y]/i){
					dy.pb(i);
					dx.pb(grid[x][y]/i);
				}
			}
		}
		for(int i=0;i<(int)dx.size();i++){
			x=dx[i],y=dy[i];
			if(x<1 || x>m || y<1 || y>n || vis[x][y])
				continue;
			st.push({dx[i],dy[i]});
		}
	}
	return false;
}

void dfs(int x){
	if(done[x])
		return;
	
	
	if(x==n*m){
		cout<<"yes\n";
		exit(0);
	}
	done[x]=1;
	for(auto& t:todo[x]){
		dfs(t);
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>m>>n;
    for(int i=1;i<=m;i++){
    	for(int j=1;j<=n;j++){
    		cin>>grid[i][j];
    	}
    }
    if(go())
    	cout<<"yes\n";
    else
    	cout<<"no\n";
    	
    /* Editorial Solution */
    cin>>m>>n;
    int x;
    for(int i=1;i<=m;i++){
    	for(int j=1;j<=n;j++){
    		cin>>x;
    		todo[i*j].pb(x);
    	}
    }
    dfs(1);
    cout<<"no\n";
	
	return 0;	
}
