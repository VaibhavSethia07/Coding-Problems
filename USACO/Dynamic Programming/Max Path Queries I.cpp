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

void input(vector<vector<int>>& grid,int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cin>>grid[i][j];
	}
}
/* Minimum cost to reach cell (N,M) from the cell (1,1). Also print the path*/
// dp[i][j] = minimum cost to reach cell (N,M) from cell (i,j)
void solve(vector<vector<int>>& grid,int n,int m){
	vector<vector<int>> dp(n+1,vector<int>(m+1));
	for(int i=0;i<=m;i++)
		dp[n][i]=1e9;
		
	for(int i=0;i<=n;i++)
		dp[i][m]=1e9;
		
	dp[n][m-1]=0;
	dp[n-1][m]=0;
	
	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=0;j--){
			dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<dp[i][j]<<" ";
		cout<<"\n";
	}
	
	cout<<"Path: \n";
	int i=0,j=0;
	while(i<n && j<m){
		cout<<i+1<<" "<<j+1<<"\n";
		if(i<n && j<m && dp[i+1][j]<dp[i][j+1]){
			i=i+1;
		}else
			j=j+1;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int n,m;
	cin>>n>>m;
	vector<vector<int>> grid(n,vector<int>(m));
	input(grid,n,m);
	solve(grid,n,m);
	return 0;	
}
