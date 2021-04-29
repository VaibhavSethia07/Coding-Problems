// Problem: Array Description
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1746
// Memory Limit: 512 MB
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
const int mod=1e9+7;

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

const int MAXN=1e5+5;
int num[MAXN];
int dp[MAXN][105];
int n,m;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>m;
    for(int i=0;i<n;i++)
    	cin>>num[i];
    if(num[0]==0){
    	for(int i=0;i<=m;i++)
    		dp[0][i]=1;
    }else
    	dp[0][num[0]]=1;
    	
    for(int i=1;i<n;i++){
    	if(num[i]==0){
	    	for(int j=1;j<=m;j++){
	    		for(auto& k:{j-1,j,j+1}){
	    			if(k>=1 && k<=m){
		    			dp[i][j]+=dp[i-1][k];
		    			dp[i][j]%=mod;
	    			}
	    		}	
	    	}
    	}else{
    		for(auto& k:{num[i]-1,num[i],num[i]+1}){
    			if(k>=1 && k<=m){
    				dp[i][num[i]]+=dp[i-1][k];
    				dp[i][num[i]]%=mod;
    			}
    		}
    	}
    }
    
    int ans=0;
    for(int i=1;i<=m;i++){
    	(ans+=dp[n-1][i])%=mod;
    }
	cout<<ans;
	return 0;	
}
