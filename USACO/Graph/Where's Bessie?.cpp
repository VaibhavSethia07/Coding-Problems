// Problem: Problem 3. Where's Bessie?
// Contest: USACO - USACO 2017 US Open Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=740
// Memory Limit: 256 MB
// Time Limit: 4000 ms

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

int N;
char mat[21][21];
bool vis[21][21];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
vector<vector<int>> pcls;
void go(int x,int y,int x1,int y1,int x2,int y2,char color){
	stack<pair<int,int>> st;
	st.push({x,y});
	
	while(!st.empty()){
		x=st.top().f;
		y=st.top().s;
		st.pop();
		if(x<x1 || x>x2 || y<y1 || y>y2 || vis[x][y] || mat[x][y]!=color)
			continue;
		
		vis[x][y]=1;
		for(int i=0;i<4;i++)
			st.push({x+dx[i],y+dy[i]});
	}
	
}

bool is_PCL(int x1,int y1,int x2,int y2){
	memset(vis,0,sizeof(vis));
	int freq[26]={0};
	int num=0;
	for(int i=x1;i<=x2;i++){
		for(int j=y1;j<=y2;j++){
			if(!vis[i][j]){
				if(freq[mat[i][j]-'A']==0)
					num++;
				freq[mat[i][j]-'A']++;
				go(i,j,x1,y1,x2,y2,mat[i][j]);
			}
		}
	}
		
	if(num!=2)
		return 0;
	
	bool found_one=false,found_many=false;
	for(int i=0;i<26;i++){
		if(freq[i]==1)
			found_one=1;
		if(freq[i]>1)
			found_many=1;
	}
	
	return found_one && found_many;
}

bool is_PCL_in_PCL(int y){
	for(int x=0;x<(int)pcls.size();x++){
		if(x==y)
			continue;
		if(pcls[y][0]>=pcls[x][0] && pcls[y][1]>=pcls[x][1] && pcls[y][2]<=pcls[x][2] && pcls[y][3]<=pcls[x][3])
			return false;
	}
	
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	freopen("where.in","r",stdin);
	freopen("where.out","w",stdout);
	
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			cin>>mat[i][j];
	}
	
	long ans=0;
	
	for(int x1=0;x1<N;x1++){
		for(int y1=0;y1<N;y1++){
			for(int x2=x1;x2<N;x2++){
				for(int y2=y1;y2<N;y2++){
					// cout<<x1<<" "<<y1<<" "<<x1+ht<<" "<<y1+wt<<"\n";
					if(is_PCL(x1,y1,x2,y2))
						pcls.pb({x1,y1,x2,y2});
				}
			}
		}
	}
	
	for(int i=0;i<(int)pcls.size();i++){
		if(is_PCL_in_PCL(i))
			ans++;
	}
	cout<<ans;
	return 0;	
}
