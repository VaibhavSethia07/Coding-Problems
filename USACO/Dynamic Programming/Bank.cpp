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

long salary[21];
int notes[21];
vector<int> have[(1<<20)+1];
int dp[21][(1<<20)+1];
bool go(int N,int mask){
	if(N==0)
		return true;
	if(dp[N][mask]!=-1)
		return dp[N][mask];
	int sal=salary[N-1];
	for(auto pay: have[sal]){
		if((pay&mask)==pay)
			if(go(N-1,mask^pay))
				return (dp[N][mask]=true);
	}
	
	return (dp[N][mask]=false);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int N,M;
	cin>>N>>M;
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<N;i++)
		cin>>salary[i];
	for(int i=0;i<M;i++)
		cin>>notes[i];
		
	for(int x=1;x<(1<<M);x++){
		int sum=0;
		for(int j=0;j<M;j++){
			if(x&(1<<j)){
				sum+=notes[j];
			}
		}
		have[sum].push_back(x);
	}
	
	if(go(N,(1<<M)-1))
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;	
}
