// Problem: Total Overlap
// Contest: CodeChef - CodeChef Div 3 Rated Contest 2021 Division 3
// URL: https://www.codechef.com/CCRC21C/problems/TOVERLP
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

/* Corodinate Compression Technique */
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	
	int T,N,M;
	cin>>T;
	while(T--){
		cin>>N>>M;
		
		vector<vector<int>> A(N,vector<int>(2,0));
		vector<vector<int>> B(M,vector<int>(2,0));
		
		set<int> events;
		
		for(int i=0;i<N;i++){
			cin>>A[i][0]>>A[i][1];
			events.insert(A[i][0]);
			events.insert(A[i][1]);
		}
		
		for(int i=0;i<M;i++){
			cin>>B[i][0]>>B[i][1];
			events.insert(B[i][0]);
			events.insert(B[i][1]);
		}
		
		/* Indexing of events and storing them with index as well as separately*/
		int ind=0;
		int P=(int)events.size();
		map<int,int> evToInd;
		vector<int> points(P);
		for(auto& e:events){
			evToInd[e]=ind;
			points[ind++]=e;
		}
		
		vector<int> cntA(P+1);
		vector<int> cntB(P+1);
		
		/* Plotting of points and corresponding line segments */
		for(int i=0;i<N;i++){
			cntA[evToInd[A[i][0]]+1]++;
			cntA[evToInd[A[i][1]]+1]--;
		}
		
		for(int i=0;i<M;i++){
			cntB[evToInd[B[i][0]]+1]++;
			cntB[evToInd[B[i][1]]+1]--;
		}
		
		/* Doing prefix sum */
		long ans=0;
		long sumA=0;
		long sumB=0;
		for(int i=1;i<=P;i++){
			sumA+=cntA[i];
			sumB+=cntB[i];
			ans+=sumA*sumB*(points[i]-points[i-1]);
		}
		
		cout<<ans<<"\n";
	}
	
	return 0;	
}
