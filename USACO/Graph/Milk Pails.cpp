// Problem: Problem 3. Milk Pails
// Contest: USACO - USACO 2016 February Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=620
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

int X,Y,K,M;
const int MAXN=105;
const int INF=1e9;
int steps[MAXN][MAXN];
void bfs(int i,int j){
	stack<pair<int,int>> st;
	st.push({i,j});
	
	while(!st.empty()){
		i=st.top().f;
		j=st.top().s;
		st.pop();
		
		int pourX=min(i,Y-j);
		int pourY=min(j,X-i);
		
		int dx[6]={X,i,0,i,i-pourX,i+pourY};
		int dy[6]={j,Y,j,0,j+pourX,j-pourY};
		
		for(int a=0;a<6;a++){
			if(steps[i][j]>K || steps[dx[a]][dy[a]]!=INF)
				continue;
			if(dx[a]<=X && dy[a]<=Y){
				steps[dx[a]][dy[a]]=1+steps[i][j];
				st.push({dx[a],dy[a]});
			}
		}
		
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("pails.in","r",stdin);
	freopen("pails.out","w",stdout);
    
	cin>>X>>Y>>K>>M;
	
	for(int i=0;i<=X;i++){
		for(int j=0;j<=Y;j++){
			steps[i][j]=INF;
		}
	}
	
	steps[0][0]=0;
	bfs(0,0);
	int ans=INF;
	for(int i=0;i<=X;i++){
		for(int j=0;j<=Y;j++){
			if(steps[i][j]<=K)
				ans=min(ans,abs(i+j-M));
		}
	}
	cout<<ans<<"\n";
	return 0;	
}
