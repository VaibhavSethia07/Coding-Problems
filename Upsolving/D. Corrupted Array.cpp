// Problem: D. Corrupted Array
// Contest: Codeforces - Codeforces Round #713 (Div. 3)
// URL: https://codeforces.com/contest/1512/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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

void input(vll& v,int N){
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
}

int bs(vll& v,int N,ll x){
	int start=0;
	int end=N-1;

	while(start<=end){
		int mid=start+(end-start)/2;
		if(v[mid]==x)
			return mid;
		if(v[mid]>x)
			end=mid-1;
		else
			start=mid+1;
	}
	
	return -1;
}

void solve(vll& v,int N){
	
	ll X=0;
	multiset<ll> cache;
	for(int i=0;i<N;i++){
		X+=v[i];
		cache.insert(v[i]);
	}
	bool ok=0;
	for(int i=0;i<N;i++){
		if((X-v[i])&1)
			continue;
		
		ll S=(X-v[i])/2;
		ll y=v[i];
		cache.erase(cache.find(v[i]));
		if(cache.count(S)){
			ok=1;
			cache.erase(cache.find(S));
			break;
		}else{
			cache.insert(v[i]);
		}
		
	}
	
	if(!ok){
		cout<<-1<<"\n";
		return;
	}

	for(auto& x:cache)
		cout<<x<<" ";
	cout<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
	
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		vll v(N+2);
		input(v,N+2);
		solve(v,N+2);
	}
	
	return 0;	
}
