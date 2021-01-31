
// Problem: Maximise Islands
// Contest: CodeChef - January Cook-Off 2021 Division 3
// URL: https://www.codechef.com/COOK126C/problems/MINIL
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

void divisors(map<int,int>& d,ll N){
	for(int div : {2,3,5}){
		int cnt=1;
		if(N%2==0){
			while((N%2)==0){
				N/=2;
				cnt++;
			}
			d[div]=cnt;
		}
	}
	static array<int,8> increments = {4,2,4,2,4,6,2,6};
	int i=0;
	for(ll div=7;div*div<=N;div+=increments[i++]){
		if((N%div)==0){
			int cnt=1;
			while((N%i)==0){
				N/=i;
				cnt++;
			}
			d[i]=cnt;
		}
		if(i==8)
			i=0;
	}
	if(N>1)
		d[N]=2;
}

void input(vl& v,int N){
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
}

void solve(int N,int M){
	
	
	char sea[N][M];
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>sea[i][j];
		}
	}
	
	
	char land[N][M]={'\n'};
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if((i+j)%2==0)
				land[i][j]='*';
			else
				land[i][j]='.';
		}
	}
	
	
	int ans1=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(sea[i][j]!=land[i][j])
				ans1++;
		}
	}
	
	if((N*M)&1){
		cout<<ans1<<"\n";
		return;
	}
	

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if((i+j)%2==1)
				land[i][j]='*';
			else
				land[i][j]='.';
		}
	}
	int ans2=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(sea[i][j]!=land[i][j])
				ans2++;
		}
	}
	cout<<min(ans1,ans2)<<"\n";
}

int main(){
	
	int T,N,K;
	cin>>T;
	while(T--){
		cin>>N>>K;
		solve(N,K);
	}
	
	return 0;	
}

