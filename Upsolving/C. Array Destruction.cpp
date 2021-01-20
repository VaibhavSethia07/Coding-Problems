
// Problem: C. Array Destruction
// Contest: Codeforces - Codeforces Round #696 (Div. 2)
// URL: https://codeforces.com/contest/1474/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

bool trial(vl v,long X){
	sort(all(v));
	
	int start=0,end=(int)v.size()-1;
	int Y=X;
	vector<pair<long,long>> sol;
	while(start<end){
		if(v[start]+v[end]==X){
			sol.pb({v[start],v[end]});
			X=v[end];
			v.erase(v.begin()+end);
			v.erase(v.begin()+start);
			start=0;
			end=v.size()-1;
		}else if(v[start]+v[end]>X){
			end--;
		}else
			start++;
	}
	if(v.size()==0){
		cout<<"YES\n"<<Y<<"\n";
		for(auto& p:sol)
			cout<<p.f<<" "<<p.s<<"\n";
		return true;
	}
	return false;
}

void solve(vl& v,int N){
	sort(all(v));
	vector<long> sum(N-1);
	for(int i=0;i<N-1;i++){
		sum[i]=v[i]+v[N-1];
	}
	
	
	for(int i=N-2;i>=0;i--){
		if(trial(v,sum[i]))
			return;
	}
	cout<<"NO\n";
}

int main(){
	
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		N*=2;
		vl v(N);
		input(v,N);
		solve(v,N);
	}
	
	return 0;	
}
