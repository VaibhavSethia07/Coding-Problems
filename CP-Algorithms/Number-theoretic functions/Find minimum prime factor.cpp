// Problem: Problem D: Game of Counting
// Contest: CodeDrills - Game of Codes
// URL: https://codedrills.io/contests/game-of-codes/problems/problem-d-game-of-counting
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
const long MAXN=1e6+6;
vector<long> minPrimeFact(MAXN);
long dp[MAXN];

bool isPrime(int i){
	return minPrimeFact[i]==i;
}
void getMinPrimeFact(){
	vector<long> primes;
	// Finding minimum prime factor of numbers
	for(long i=2;i<MAXN;i++){
		if(minPrimeFact[i]==0){
			minPrimeFact[i]=i;
			primes.push_back(i);
		}
		
		for(int j=0;j<(int)primes.size() && i*primes[j]<MAXN;j++){
			minPrimeFact[i*primes[j]]=primes[j];
		}
	}
	
	// Finding numbers which are cube of some other number or they are the product of 2 prime numbers
	for(int i=2;i<MAXN;i++){
		long f1=minPrimeFact[i];
		long f2=i/f1;
		if(f1!=f2 && (isPrime(f2)|| f1*f1==f2))
			dp[i]=1;
		dp[i]+=dp[i-1];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	getMinPrimeFact();
	int T,L,R;
	cin>>T;
	while(T--){
		cin>>L>>R;
		cout<<dp[R]-dp[L-1]<<"\n";
	}
	
	
	return 0;	
}
