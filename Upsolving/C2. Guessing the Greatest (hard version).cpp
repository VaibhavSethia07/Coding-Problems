// Problem: C2. Guessing the Greatest (hard version)
// Contest: Codeforces - Codeforces Round #703 (Div. 2)
// URL: https://codeforces.com/contest/1486/problem/C2
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

int query(int start,int end){
	int ind;
	cout<<"? "<<start<<" "<<end<<"\n";
	cout.flush();
	cin>>ind;
	
	return ind;
}

void input(vl& v,int N){
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
}

int solve(int start,int end,int smax){
	int ind;
	while(start<end){
		
		if(end<smax){
			int mid=(start+end+1)/2;
			ind=query(mid,smax);
			if(ind==smax)
				start=mid;
			else
				end=mid-1;
		}else{
			int mid=(start+end)/2;
			ind=query(smax,mid);
			if(ind==smax)
				end=mid;
			else
				start=mid+1;
		}
	}
	return start;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int N;
	cin>>N;
	
	int start=1,end=N,smax,ind;
	smax = query(start,end);
	
	bool maxOnLeft=1;
	
	if(smax==1)
		maxOnLeft=0;
	else{
		ind=query(start,smax);
		if(ind!=smax)
			maxOnLeft=0;
	}
	
	
	if(maxOnLeft)
		ind=solve(start,smax-1,smax);
	else
		ind=solve(smax+1,end,smax);
	cout<<"! "<<ind<<"\n";
	cout.flush();
	
	return 0;	
}
