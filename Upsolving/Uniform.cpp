// Problem: Uniform
// Contest: CodeChef - March Lunchtime 2021 Division 2
// URL: https://www.codechef.com/LTIME94B/problems/UNICOLOR
// Memory Limit: 256 MB
// Time Limit: 1000 ms

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
const int MAXN=100005;
const ll mod=998244353;
vector<int> parent;
vector<int> sz;

void make_parent(int C){
	parent.resize(C);
	sz.resize(C);
	for(int i=0;i<C;i++){
		parent[i]=i;
		sz[i]=1;
	}
}

int find(int a){
	vector<int> v;
	while(a!=parent[a]){
		v.pb(a);
		a=parent[a];
	}
	
	for(int i=0;i<(int)v.size();i++)
		parent[v[i]]=a;
	
	return a;
}

void unite(int a,int b){
	a=find(a);
	b=find(b);
	
	if(a==b)
		return;
	
	if(sz[a]<sz[b])
		swap(a,b);
		
	parent[b]=a;
	sz[a]+=sz[b];
}

ll binExp(ll a,ll b){
	a%=mod;
	ll res=1;
	
	while(b>0){
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	
	return res;
}

void input(vl& v,int N){
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
}

void solve(){
	int C,N,M,X,a,b;
	cin>>C>>N>>M;
	
	make_parent(C);
	vector<vector<int>> segs;
	for(int i=0;i<C;i++){
		cin>>X;
		for(int j=0;j<X;j++){
			cin>>a>>b;
			segs.pb({a,b,i});
		}
	}
	
	sort(all(segs));
	
	int prev_start=0;
	int prev_end=0;
	int prev_club=0;
	
	ll rest=0;
	for(int i=0;i<(int)segs.size();i++){
		int start=segs[i][0];
		int end=segs[i][1];
		int club=segs[i][2];
		
		if(prev_end>=start){
			unite(prev_club,club);
			
			prev_end=max(prev_end,end);
		}else{
			rest+=start-prev_end-1;
			
			prev_start=start;
			prev_end=end;
			prev_club=club;
		}
	}
	rest+=N-prev_end;
	set<int> representative;
	
	for(int i=0;i<C;i++)
		representative.insert(parent[i]);
		
	ll ans=(int)representative.size();
	
	ans=binExp(M,ans+rest);
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int T;
	cin>>T;
	while(T--){
		
		solve();
	}
	
	return 0;	
}
