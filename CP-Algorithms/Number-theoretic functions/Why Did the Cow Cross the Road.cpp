// Problem: Problem 1. Why Did the Cow Cross the Road
// Contest: USACO - USACO 2017 February Contest, Gold
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=717
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

ll N,T;
const int MAXN=105;
ll field[MAXN][MAXN];
ll D[MAXN*MAXN+MAXN];
vector<int> dr;
vector<int> dc;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	freopen("visitfj.in","r",stdin);
	freopen("visitfj.out","w",stdout);
	
	cin>>N>>T;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>field[i][j];
			D[i*N+j]=1e18;
		}
	}
	
	for(int i=-3;i<=3;i++){
		for(int j=-3;j<=3;j++){
			if(abs(i)+abs(j)==3 || abs(i)+abs(j)==1){
				dr.push_back(i);
				dc.push_back(j);
				// cout<<i<<" "<<j<<"\n";
			}
		}
	}
	
	ll result=LLONG_MAX;
	
	D[0]=0;
	priority_queue<pair<ll,ll>> pq;
	pq.push({0,0});
	while(!pq.empty()){
		ll dist=-pq.top().first;
		ll r=pq.top().second/N;
		ll c=pq.top().second%N;
		pq.pop();
		
		if(dist!=D[r*N+c])
			continue;
		
		int d=abs(N-1-r)+abs(N-1-c);
		if(d<=2){
			result=min(result,dist+d*T);
		}
		
		for(int i=0;i<(int)dr.size();i++){
			int rr=r+dr[i];
			int cc=c+dc[i];
			
			if(rr<0 || rr>=N || cc<0 || cc>=N)
				continue;
			if(D[rr*N+cc]>dist+field[rr][cc]+3*T){
				D[rr*N+cc]=dist+field[rr][cc]+3*T;
				pq.push({-D[rr*N+cc],rr*N+cc});
			}
		}
	}
	cout<<result<<"\n";
	return 0;	
}
