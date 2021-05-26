// Problem: Heavy Traffic
// Contest: CodeDrills - Amrita ICPC Practice Session #7
// URL: https://codedrills.io/contests/amrita-icpc-practice-session-7/problems/heavy-traffic
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

int ceil(vector<ll>& poles,ll X){
	int ans=-1,start=0,end=(int)poles.size()-1;
	
	while(start<=end){
		int mid=start+(end-start)/2;
		if(poles[mid]>=X){
			ans=mid;
			end=mid-1;
		}else
			start=mid+1;
	}
	
	return ans;
}

int floor(vector<ll>& poles,ll X){
	int ans=-1,start=0,end=(int)poles.size()-1;
	
	while(start<=end){
		int mid=start+(end-start)/2;
		if(poles[mid]<=X){
			ans=mid;
			start=mid+1;
		}else
			end=mid-1;
	}
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int T,P,C;
	cin>>T;
	while(T--){
		cin>>P>>C;
		vector<ll> poles(P);
		vector<pair<ll,ll>> cars(C);
		
		for(int i=0;i<P;i++)
			cin>>poles[i];
		
		for(int i=0;i<C;i++)
			cin>>cars[i].f;
		
		for(int i=0;i<C;i++)
			cin>>cars[i].s;
			
		if(C==1){
			cout<<"YES\n";
			continue;
		}
			
		sort(all(poles));
		sort(all(cars));
		
		
		// cout<<"\n";
		// for(int i=0;i<P;i++){
			// cout<<poles[i]<<" ";
		// }
		// cout<<"\n";
// 		
		// for(int i=0;i<C;i++){
			// cout<<cars[i].f<<" ";
		// }
		// cout<<"\n";
// 		
		// for(int i=0;i<C;i++){
			// cout<<cars[i].s<<" ";
		// }
		// cout<<"\n";
		
		
		bool ok=1;
		for(int i=1;i<C;i++){
			// Case 1 
			if(cars[i-1].s<0 && cars[i].s>0)
				continue;
			// Case 2
			if(cars[i-1].s<0 && cars[i].s<0){
				int down=floor(poles,cars[i].f);
				if(poles[down]<=cars[i].f && poles[down]>=cars[i-1].f)
					continue;
				ll d1=abs(poles[0]-cars[i-1].f),d2=abs(poles[0]-cars[i].f);
				ll s1=cars[i-1].s,s2=cars[i].s;
				if(d1*s2>d2*s1){
					ok=0;
					// cout<<2<<" "<<i<<" "<<poles[0]<<"\n";	
					break;
				}
			}
			// Case 3
			if(cars[i-1].s>0 && cars[i].s>0){
				int up=ceil(poles,cars[i-1].f);
				if(poles[up]<=cars[i].f && poles[up]>=cars[i-1].f)
					continue;
				ll d1=abs(poles[P-1]-cars[i-1].f),d2=abs(poles[P-1]-cars[i].f);
				ll s1=cars[i-1].s,s2=cars[i].s;
				if(d1*s2<d2*s1){
					ok=0;
					// cout<<3<<" "<<i<<"\n";	
					break;
				}
					
			}
			// Case 4
			if(cars[i-1].s>0 && cars[i].s<0){
				int up=ceil(poles,cars[i-1].f);
				int down=floor(poles,cars[i].f);

				if(up>down){
					ok=0;
					// cout<<4<<" "<<i<<"\n";	
					break;
				}
			}
		}
		
		if(ok)
			cout<<"YES\n";
		else
			cout<<"NO\n";
		
		
	}
	
	return 0;	
}
