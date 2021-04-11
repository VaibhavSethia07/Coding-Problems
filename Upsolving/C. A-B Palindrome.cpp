// Problem: C. A-B Palindrome
// Contest: Codeforces - Codeforces Round #713 (Div. 3)
// URL: https://codeforces.com/contest/1512/problem/C
// Memory Limit: 256 MB
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

void solve(vl& v,int N){
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

	int T,a,b,N;
	string S;
	cin>>T;
	while(T--){
		cin>>a>>b>>S;
		N=(int)S.length();
		bool ok=1;
		if(N&1){
			if((a&1)==0 && (b&1)==0){
				cout<<-1<<"\n";
				continue;
			}
		}else{
			if((a&1)==1 || (b&1)==1){
				cout<<-1<<"\n";
				continue;
			}
		}
		
		if(a+b!=N){
			cout<<-1<<"\n";
			continue;
		}
		
		for(int i=0;i<N;i++){
			if(S[i]=='0'){
				if(a<=0){
					ok=0;
					break;
				}
				a--;
			}
			if(S[i]=='1'){
				if(b<=0){
					ok=0;
					break;
				}
				b--;
			}
		}
		
		if(!ok){
			cout<<-1<<"\n";
			continue;
		}	
		for(int i=0;i<N/2;i++){
			if(S[i]=='0' && S[N-i-1]=='0')
				continue;
			
			if(S[i]=='1' && S[N-i-1]=='1')
				continue;
			 // cout<<a<<" "<<b<<"\n"<<S<<"\n";	
			if(S[i]=='?' &&  S[N-i-1]=='?')
				continue;
			
			if(S[i]=='0' &&  S[N-i-1]=='?'){
				if(a<=0){
					ok=0;
					break;
				}
				 S[N-i-1]='0';
				a--;
			}else if(S[i]=='?' &&  S[N-i-1]=='0'){
				if(a<=0){
					ok=0;
					break;
				}
				S[i]='0';
				a--;
			}else if(S[i]=='1' &&  S[N-i-1]=='?'){
				if(b<=0){
					ok=0;
					break;
				}
				S[N-i-1]='1';
				b--;
			}else if(S[i]=='?' &&  S[N-i-1]=='1'){
				if(b<=0){
					ok=0;
					break;
				}
				S[i]='1';
				b--;
			}
			
		}
		
		if(!ok){
			cout<<-1<<"\n";
			continue;
		}
		
		for(int i=0;i<N/2;i++){
			if(S[i]=='?' && S[N-i-1]=='?'){
				if(a>=b){
					if(a<=1){
						ok=0;
						break;
					}
					a-=2;
					S[i]='0';
					S[N-i-1]='0';
				}else{
					if(b<=1){
						ok=0;
						break;
					}
					b-=2;
					S[i]='1';
					S[N-i-1]='1';
				}
			}
		}
		
		if(!ok){
			cout<<-1<<"\n";
			continue;
		}
		
		if(N&1){
			if(S[N/2]=='?'){
				if(a>b){
					if(a<=0){
						ok=0;
						break;
					}
					S[N/2]='0';
					a--;
				}else{
					if(b<=0){
						ok=0;
						break;
					}
					S[N/2]='1';
					b--;
				}
			}
		}
		
		for(int i=0;i<N;i++){
			if(S[i]=='?'){
				ok=0;
				break;
			}
		}
		if(!ok){
			cout<<-1<<"\n";
			continue;
		}
		
		for(int i=0;i<N/2;i++){
			if(S[i]!=S[N-i-1]){
				ok=0;
				break;
			}
		}
		if(!ok){
			cout<<-1<<"\n";
			continue;
		}
		cout<<S<<"\n";
	}
	
	return 0;	
}
