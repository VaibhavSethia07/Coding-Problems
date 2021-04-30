// Problem: Problem 2. Radio Contact
// Contest: USACO - USACO 2016 January Contest, Gold
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=598
// Memory Limit: 256 MB
// Time Limit: 4000 ms

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

int n,m;
string F,B;
int fx,fy,bx,by;
long dp[1005][1005];
void input(vl& v,int N){
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
}

long dist(int x1,int y1,int x2,int y2){
	return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}

long go(int i,int j,int fx,int fy,int bx,int by){
	if(i>n && j>m)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	// cout<<fx<<" "<<fy<<" "<<bx<<" "<<by<<"\n";
	long sub_ans1=LONG_MAX;
	long sub_ans2=LONG_MAX;	
	long sub_ans3=LONG_MAX;	
	if(i<=n){
		int x=0,y=0;
		switch(F[i-1]){
			case 'N': y=1;
				break;
			case 'S': y=-1;
				break;
			case 'E': x=1;
				break;
			case 'W': x=-1;
				break;
		}
		sub_ans1=go(i+1,j,fx+x,fy+y,bx,by);
		if(sub_ans1!=LONG_MAX)
			sub_ans1+=dist(bx,by,fx+x,fy+y);
	}
	if(j<=m){
		int x=0,y=0;
		switch(B[j-1]){
			case 'N': y=1;
				break;
			case 'S': y=-1;
				break;
			case 'E': x=1;
				break;
			case 'W': x=-1;
				break;
		}
		sub_ans2=go(i,j+1,fx,fy,bx+x,by+y);
		if(sub_ans2!=LONG_MAX)
			sub_ans2+=dist(fx,fy,bx+x,by+y);
	}
	
	if(i<=n && j<=m){
		int x1=0,y1=0,x2=0,y2=0;
		switch(F[i-1]){
			case 'N': y1=1;
				break;
			case 'S': y1=-1;
				break;
			case 'E': x1=1;
				break;
			case 'W': x1=-1;
				break;
		}
		switch(B[j-1]){
			case 'N': y2=1;
				break;
			case 'S': y2=-1;
				break;
			case 'E': x2=1;
				break;
			case 'W': x2=-1;
				break;
		}
		sub_ans3=go(i+1,j+1,fx+x1,fy+y1,bx+x2,by+y2);
		if(sub_ans3!=LONG_MAX)
			sub_ans3+=dist(bx+x2,by+y2,fx+x1,fy+y1);
	}
	// cout<<sub_ans1<<" "<<sub_ans2<<"  "<<sub_ans3<<"\n";
	return dp[i][j]=min(sub_ans1,min(sub_ans2,sub_ans3));
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	freopen("radio.in","r",stdin);
	freopen("radio.out","w",stdout);
	
	cin>>n>>m>>fx>>fy>>bx>>by>>F>>B;
	memset(dp,-1,sizeof(dp));
	cout<<go(1,1,fx,fy,bx,by);
	
	return 0;	
}
