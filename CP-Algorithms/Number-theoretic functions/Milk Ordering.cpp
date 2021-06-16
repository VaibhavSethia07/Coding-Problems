// Problem: Problem 2. Milking Order
// Contest: USACO - USACO 2018 US Open Contest, Gold
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=838
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

const int MAXN=1e5+5;
int V,E,M,curr;
int in_degree[MAXN];
vector<int> graph[MAXN];
vector<int> obs[50005];
vector<int> result;
vector<int> sub_result;

// struct compareCows{
	// bool operator()(int cow1,int cow2){
		// return cow1>cow2;
	// }
// };

void init(){
	for(int i=0;i<=V;i++){
		graph[i].clear();
		in_degree[i]=0;
	}
}

bool isPossible(int X){
	init();
	
	for(int i=0;i<X;i++){
		for(int j=1;j<(int)obs[i].size();j++){
			graph[obs[i][j-1]].push_back(obs[i][j]);
			in_degree[obs[i][j]]++;
			
		}
	}
	
	// priority_queue<int, vector<int>, compareCows> pq;
	priority_queue<int, vector<int>> pq;
	sub_result.clear();
	for(int i=1;i<=V;i++){
		if(in_degree[i]==0)
			pq.push(-i);
	}
	
	int cnt=V;
	
	while(!pq.empty()){
		int u=-pq.top();
		pq.pop();
		
		sub_result.push_back(u);
		cnt--;
		
		for(auto& v:graph[u]){
			in_degree[v]--;
			
			if(in_degree[v]==0)
				pq.push(-v);
		}
	}
	
	return cnt==0;
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("milkorder.in","r",stdin);
	freopen("milkorder.out","w",stdout);
    
    cin>>V>>E;
	for(int i=0;i<E;i++){
		cin>>M;
		for(int j=0;j<M;j++){
			cin>>curr;
			obs[i].push_back(curr);
		}
	}
	
	int start=1,end=E;
	
	while(start<=end){
		int mid=start+(end-start)/2;
		if(isPossible(mid)){
			result=sub_result;
			start=mid+1;
		}else
			end=mid-1;
	}
	
	for(int i=0;i<(int)result.size();i++){
		cout<<result[i];
		if(i<(int)result.size()-1)
			cout<<" ";
		
	}
	return 0;	
}
