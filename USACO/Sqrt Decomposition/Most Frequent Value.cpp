// Problem: Most Frequent Value
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/FREQ2/
// Memory Limit: 1536 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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

const int MAXN=1e5+5;
int arr[MAXN];
int freq[MAXN];
int freq_of_freq[MAXN];
int ML,MR,block_sz;
int mx_freq;

struct Query{
	int L,R,idx;
};

bool compare(Query& q1,Query& q2){
	if(q1.L/block_sz==q2.L/block_sz){
		if((q1.L/block_sz)&1)
			return q1.R>q2.R;
		return q1.R<q2.R;
	}
	return q1.L/block_sz<q2.L/block_sz;
}



void add(int i){
	int pref=freq[arr[i]];
	freq[arr[i]]++;
	int currf=freq[arr[i]];
	
	freq_of_freq[pref]--;
	freq_of_freq[currf]++;
	
	if(currf>mx_freq){
		mx_freq=currf;
	}
	
}

void remove(int i){
	int pref=freq[arr[i]];
	freq[arr[i]]--;
	int currf=freq[arr[i]];
	
	freq_of_freq[pref]--;
	freq_of_freq[currf]++;
	
	while(freq_of_freq[mx_freq]==0)
		mx_freq--;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int N,Q,L,R;
	cin>>N>>Q;
	
	for(int i=0;i<N;i++)
		cin>>arr[i];
		
	vector<Query> queries(Q);
	for(int i=0;i<Q;i++){
		cin>>queries[i].L>>queries[i].R;
		queries[i].idx=i;
	}
	
	int ans[Q];
	ML=0,MR=-1,block_sz=(int)sqrt(MAXN);
	sort(all(queries),compare);
	
	
	for(int i=0;i<Q;i++){
		L=queries[i].L,R=queries[i].R;
		while(ML>L){
			ML--;
			add(ML);
		}
		while(MR<R){
			MR++;
			add(MR);
		}
		while(ML<L){
			remove(ML);
			ML++;
		}
		while(MR>R){
			remove(MR);
			MR--;
		}
		ans[queries[i].idx]=mx_freq;
	}
	
	for(int i=0;i<Q;i++)
		cout<<ans[i]<<"\n";
	
	
	return 0;	
}
