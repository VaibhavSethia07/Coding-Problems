// Problem: C. Bear and Prime Numbers
// Contest: Codeforces - Codeforces Round #226 (Div. 2)
// URL: https://codeforces.com/problemset/problem/385/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms

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

void input(vi& v,int N){
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
}

const int MAXN=10000007;
int primes[MAXN];
bool notprimes[MAXN];
void solve(vi& v,int N,int M){
	int ind=0;
	int S=MAXN-7;
		
	for(int i=2;i<=S;i++){
		if(notprimes[i]==0)
			primes[ind++]=i;
		
		for(int j=0;j<ind;j++){
			if(i*primes[j]>S)
				break;
			notprimes[i*primes[j]]=1;
			if((i%primes[j])==0)
				break;
		}
		
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int N,M;
	cin>>N;
	vi v(N);
	input(v,N);
	cin>>M;
	solve(v,N,M);
	
	
	return 0;	
}
