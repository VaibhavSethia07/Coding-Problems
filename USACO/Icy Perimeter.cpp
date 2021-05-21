// Problem: Problem 2. Icy Perimeter
// Contest: USACO - USACO 2019 January Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=895
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
char mat[1005][1005];
bool vis[1005][1005];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
pair<int,int> flood_fill(int x,int y){
	int area=0,perimeter=0;
	
	stack<pair<int,int>> frontier;
	frontier.push({x,y});
	
	while(!frontier.empty()){
		x=frontier.top().f;
		y=frontier.top().s;
		frontier.pop();
		
		if(x<=0 || x>N || y<=0 || y>N || vis[x][y] || mat[x][y]=='.')
			continue;
			
		vis[x][y]=1;
		area++;
		for(int i=0;i<4;i++){
			int xx=x+dx[i],yy=y+dy[i];
			if(mat[xx][yy]=='.')
				perimeter++;
		}
		for(int i=0;i<4;i++)
			frontier.push({x+dx[i],y+dy[i]});
	}
	return {area,perimeter};
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	freopen("perimeter.in","r",stdin);
	freopen("perimeter.out","w",stdout);
	
	cin>>N;
	for(int i=0;i<=N+1;i++)
		for(int j=0;j<=N+1;j++)
			mat[i][j]='.';
			
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			cin>>mat[i][j];
	
	int max_area=0,max_perimeter=0;		
	for(int x=1;x<=N;x++){
		for(int y=1;y<=N;y++){
			if(!vis[x][y] && mat[x][y]=='#'){
				pair<int,int> sub_ans=flood_fill(x,y);
				if(sub_ans.f>max_area){
					max_area=sub_ans.f;
					max_perimeter=sub_ans.s;
				}
				if(sub_ans.f==max_area){
					max_perimeter=min(sub_ans.s,max_perimeter);
				}
			}
				
		}
	}
	cout<<max_area<<" "<<max_perimeter<<"\n";
	return 0;	
}
