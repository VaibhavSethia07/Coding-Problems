// Problem: Pen Pineapple Apple Pen
// Contest: CodeChef - ICPC Training Contest 1
// URL: https://www.codechef.com/ICPCTR01/problems/PENS
// Memory Limit: 256 MB
// Time Limit: 1000 ms

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

const int MAX=(1<<20)+1;
int have[MAX];

void print_N_times(int pen,int L){
	for(int i=1;i<=L;++i){
		cout<<pen<<" ";
	}
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int T,N,K;
	string S,word;
	cin>>T;
	
	while(T--){
		cin>>N>>K>>S;
		
		for(int i=1;i<=K;++i){
			int mask=0;
			cin>>word;
			for(int j=0;j<(int)word.length();++j)
				mask|=(1<<(word[j]-'a'));
			have[mask]=i;
		}
		
		// Making subsets of all the masks
		for(int mask=MAX-2;mask>=0;--mask){
			for(int j=0;j<20;++j){
				if((mask&(1<<j)) && have[mask^(1<<j)]==0)
					have[mask^(1<<j)]=have[mask];
			}
		}
		
		int mask=0,last=0;
		for(int i=0;i<N;++i){
			int x=S[i]-'a';
			if(have[mask|(1<<x)]){
				mask|=(1<<x);
				continue;
			}	
			print_N_times(have[mask],i-last);
			mask=(1<<x);
			last=i;
		}
		print_N_times(have[mask],N-last);
		cout<<"\n";
		
		memset(have,0,sizeof(have));
	}
	
	return 0;	
}
