// Problem: Owl Fight
// Contest: HackerEarth - Data Structures - Disjoint Data Structures - Basics of Disjoint Data Structures
// URL: https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/owl-fight/
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

vector<int> parent;

void make_parent(int N){
	parent.clear();
	parent.resize(N);
	
	for(int i=0;i<N;i++)
		parent[i]=i;
}

int find(int a){
	if(a==parent[a])
		return a;
	return parent[a]=find(parent[a]);
}

void unite(int a,int b){
	a=find(a);
	b=find(b);
	
	if(a<b)
		swap(a,b);
	parent[b]=a;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N,M,Q,a,b,pa,pb;
	cin>>N>>M;
	make_parent(N);
	
	for(int i=0;i<M;i++){
		cin>>a>>b;
		a--;b--;
		unite(a,b);
	}
	cin>>Q;
	for(int i=0;i<Q;i++){
		cin>>a>>b;
		a--;b--;
		pa=find(a);
		pb=find(b);
		if(pa==pb)
			cout<<"TIE\n";
		else if(pa>pb)
			cout<<a+1<<"\n";
		else
			cout<<b+1<<"\n";
	}
	return 0;	
}
