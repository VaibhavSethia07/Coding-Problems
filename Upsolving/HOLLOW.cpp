// Problem: Maximum Size Hollow Square
// Contest: CodeChef - CodeChef Div 3 Rated Contest 2021 Division 3
// URL: https://www.codechef.com/CCRC21C/problems/HOLLOW
// Memory Limit: 256 MB
// Time Limit: 500 ms

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

void input(vl& v,int N){
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
}

void solve(vl& v,int N){
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	
	int T,N,M,K;
	cin>>T;
	while(T--){
		cin>>N>>M>>K;
		int mat[N][M]={0};
		char ch;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				cin>>ch;
				mat[i][j]=ch-'0';
			}
		}
		
		long prefix[N+1][M+1];
		
		for(int i=0;i<=M;i++)
			prefix[0][i]=0;
		
		for(int i=0;i<=N;i++)
			prefix[i][0]=0;
		
		for(int i=1;i<=N;i++){
			for(int j=1;j<=M;j++)
				prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+mat[i-1][j-1];
		}
		int start=1,end=min(N,M),ans=0;
		while(start<=end){
			int mid=start+(end-start)/2;
			bool ok=0;
			for(int r1=1;r1+mid-1<=N;r1++){
				for(int c1=1;c1+mid-1<=M;c1++){
					int r2=r1+mid-1;
					int c2=c1+mid-1;
					long ones=prefix[r2][c2]-prefix[r1-1][c2]-prefix[r2][c1-1]+prefix[r1-1][c1-1];
					long zeros=(N*M-mid*mid)-(prefix[N][M]-ones);
						// cout<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<" "<<ones<<" "<<zeros<<" "<<mid<<"\n";
					if(ones<=K && ones<=zeros){
						ok=1;
					}
					if(ok)
						break;
				}
				if(ok)
					break;
			}
			
			if(ok){
				ans=mid;
				start=mid+1;
			}else
				end=mid-1;	
		}
		cout<<ans<<"\n";
	}
		
	return 0;	
}
