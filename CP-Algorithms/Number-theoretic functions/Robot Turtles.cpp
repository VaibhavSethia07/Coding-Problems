// Problem: Robot Turtles
// Contest: Kattis
// URL: https://open.kattis.com/problems/robotturtles
// Memory Limit: 1024 MB
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

struct State{
	int dist,i,j,dir;
	string program;
	
	bool operator>(const State& a) const{
		return dist>a.dist;
	} 
};

// 0->right, 1->down, 2->left 3->up
int di[4]={0,1,0,-1};
int dj[4]={1,0,-1,0};

bool inGrid(int a,int b){
	if(a>=0 && a<8 && b>=0 && b<8)
		return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	string grid[8];
	for(int i=0;i<8;i++)
		cin>>grid[i];
		
	int D[8][8][4];
	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			for(int k=0;k<4;k++){
				D[i][j][k]=1e9;
			}
		}
	}
		
	priority_queue<State, vector<State>, greater<State>> pq;
	
	D[7][0][0]=0;
	pq.push({0,7,0,0,""});
	
	while(!pq.empty()){
		State curr=pq.top();
		pq.pop();
		
		if(grid[curr.i][curr.j]=='D'){
			cout<<curr.program;
			return 0;
		}
		
		// Move forward;
		int newi=curr.i+di[curr.dir];
		int newj=curr.j+dj[curr.dir];
		
		if(inGrid(newi,newj) && (grid[newi][newj]=='D' || grid[newi][newj]=='.') && D[newi][newj][curr.dir]>D[curr.i][curr.j][curr.dir]+1){
			D[newi][newj][curr.dir]=D[curr.i][curr.j][curr.dir]+1;
			pq.push({D[newi][newj][curr.dir],newi,newj,curr.dir,curr.program+"F"});
		}
		
		// melt the ice and move forward
		if(inGrid(newi,newj) && grid[newi][newj]=='I' && D[newi][newj][curr.dir]>D[curr.i][curr.j][curr.dir]+2){
			D[newi][newj][curr.dir]=D[curr.i][curr.j][curr.dir]+2;
			pq.push({D[newi][newj][curr.dir],newi,newj,curr.dir,curr.program+"XF"});
		}
		
		// Turn left or right
		for(int turn:{-1,1}){
			int newdir=(curr.dir+turn+4)%4;
			string newmove=((turn==-1)?"L":"R");
			
			if(D[curr.i][curr.j][newdir]>D[curr.i][curr.j][curr.dir]+1){
				D[curr.i][curr.j][newdir]=D[curr.i][curr.j][curr.dir]+1;
				pq.push({D[curr.i][curr.j][newdir],curr.i,curr.j,newdir,curr.program+newmove});
			}
		}
	}
	
	cout<<"no solution";
	return 0;	
}
