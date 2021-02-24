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

struct Edge{
	int a,b,w;
};

bool comp(const Edge& o1,const Edge& o2){
	return o1.w<o2.w;
}

vector<Edge> edges;
vector<int> link;
vector<int> store;
void input(int N,int M){
	edges.resize(M);
	link.resize(N);
	store.resize(N);
	for(int i=1;i<=N;i++){
		link[i]=i;
		store[i]=1;
	}
	
	for(int i=0;i<M;i++)
		cin>>edges[i].a>>edges[i].b>>edges[i].w;
		
	sort(begin(edges),end(edges),comp);
}

int find(int x){
	while(link[x]!=x) x=link[x];
	return x;
}

bool same(int a,int b){
	return find(a)==find(b);
}

void unite(int a,int b){
	a=find(a);
	b=find(b);
	
	if(store[a]>store[b])
		swap(a,b);
	
	link[a]=b;
	store[b]+=store[a];
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int N,M;
	cin>>N>>M;
	
	input(N,M);
	long ans=0;
	for(int i=0;i<M;i++){
		if(!same(edges[i].a,edges[i].b)){
			unite(edges[i].a,edges[i].b);
			ans+=edges[i].w;
		}
	}
	cout<<ans;
	
	return 0;	
}
