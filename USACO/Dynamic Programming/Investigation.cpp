// Problem: Investigation
// Contest: LightOJ
// URL: https://lightoj.com/problem/investigation
// Memory Limit: 64 MB
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
vector<int> num;
int dp[10][90][90][2];
int T,a,b,k;
int go(int pos,int sum,int sq,bool flag){
	if(pos==(int)num.size()){
		return (sq%k)==0 && (sum%k)==0;
	}
	
	if(dp[pos][sum][sq%k][flag]!=-1)
		return dp[pos][sum][sq%k][flag];
	
	int limit=9;
	if(flag)
		limit=num[pos];
	int res=0;	
	for(int i=0;i<=limit;i++){
		if(i==limit && flag)
			res+=go(pos+1,sum+i,(sq*10+i)%k,true);
		else
			res+=go(pos+1,sum+i,(sq*10+i)%k,false);
	}
	return dp[pos][sum][sq%k][flag]=res;
}

void define_limit(int x){
	num.clear();
	while(x>0){
		num.push_back(x%10);
		x/=10;
	}
	reverse(num.begin(),num.end());
}

int main(){
	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>a>>b>>k;
		if(k>90){
			cout<<"Case "<<t<<": "<<0<<"\n";
			continue;
		}
		memset(dp,-1,sizeof(dp));
		define_limit(b);
		int x=go(0,0,0,true);
		
		memset(dp,-1,sizeof(dp));
		define_limit(a-1);
		int y=go(0,0,0,true);
		cout<<"Case "<<t<<": "<<x-y<<"\n";
		
	}
	
	return 0;	
}
