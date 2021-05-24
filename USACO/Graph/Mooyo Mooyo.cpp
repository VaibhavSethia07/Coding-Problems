// Problem: Problem 3. Mooyo Mooyo
// Contest: USACO - USACO 2018 December Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=860
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
const int MAXN=105;
char farm[MAXN][10];
bool vis[MAXN][10];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int N,K;

void update1(){
	// We need to erase the visited region
	for(int i=0;i<N;i++){
		for(int j=0;j<10;j++){
			if(vis[i][j])
				farm[i][j]='0';
		}
	}
}

void update2(){
	for(int j=0;j<10;j++){
		int k=N-1;
		for(int i=N-1;i>=0;i--){
			if(farm[i][j]!='0'){
				farm[k--][j]=farm[i][j];
			}
		}
		while(k>=0){
			farm[k--][j]='0';
		}
	}
}

int ff(int x,int y,int color){
	memset(vis,0,sizeof(vis));
	stack<pair<int,int>> st;
	st.push({x,y});
	
	int count=0;
	while(!st.empty()){
		x=st.top().f;
		y=st.top().s;
		st.pop();
		if(x<0 || x>=N || y<0 || y>=10 || vis[x][y] || color!=farm[x][y])
			continue;
			
		vis[x][y]=1;
		count++;
		for(int i=0;i<4;i++){
			st.push({x+dx[i],y+dy[i]});
		}
	}
	
	return count;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	freopen("mooyomooyo.in","r",stdin);
	freopen("mooyomooyo.out","w",stdout);
	
	cin>>N>>K;
	for(int i=0;i<N;i++){
		for(int j=0;j<10;j++)
			cin>>farm[i][j];
	}
	
	while(true){
		bool ok=0;
		for(int i=N-1;i>=0;i--){
			for(int j=0;j<10;j++){
				if(farm[i][j]!='0'){
					int comp=ff(i,j,farm[i][j]);
					if(comp>=K){
						ok=1;
						update1();
					}
				}
					
			}
		}
		if(ok)
			update2();
		else
			break;
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<10;j++)
			cout<<farm[i][j];
		cout<<"\n";
	}
	
	return 0;	
}
