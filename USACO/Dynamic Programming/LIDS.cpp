// Problem: LIDS
// Contest: Toph
// URL: https://toph.co/p/lids
// Memory Limit: 512 MB
// Time Limit: 1000 ms

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
vector<int> num;
int dp[12][12][2][2][12];
ll go(int pos,int prev,bool flag,bool nonzero,int need){
	if(pos==(int)num.size()){
		return need==0;
	}
	
	if(dp[pos][prev+1][flag][nonzero][need]!=-1)
		return dp[pos][prev+1][flag][nonzero][need];
	
	int limit=9;
	if(flag)
		limit=num[pos];
		
	ll res=0;
	for(int i=0;i<=limit;i++){
		res+=go(pos+1,prev,(i==limit)&&flag,nonzero || i,need);
		
		if(prev<i && need>0 && (nonzero || i))
			res+=go(pos+1,i,(i==limit)&&flag,1,need-1);
	}
	
	return dp[pos][prev+1][flag][nonzero][need]=res;
}

void define_limit(int x){
	num.clear();
	while(x>0){
		num.push_back(x%10);
		x/=10;
	}
	reverse(all(num));
	memset(dp,-1,sizeof(dp));
}

int main(){
	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    
	int T,a,b;
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>a>>b;
		ll arr[10]={0};
		define_limit(b);
		
		for(int i=1;i<10;i++){
			arr[i]+=go(0,-1,1,0,i);
		}
		
		define_limit(a-1);
		for(int i=1;i<10;i++){
			arr[i]-=go(0,-1,1,0,i);
		}
		
		bool ok=0;
		for(int i=9;i>=1;i--){
			if(arr[i]){
				cout<<"Case "<<t<<": "<<i<<" "<<arr[i]<<"\n";
				ok=1;
				break;
			}
		}
		if(!ok){
			cout<<"Case "<<t<<": "<<0<<" "<<1<<"\n";
		}
	}
	
	return 0;	
}
