/*
Snuke Inc. offers various kinds of services.
A payment plan called Snuke Prime is available.
In this plan, by paying 
C
 yen (the currency of Japan) per day, you can use all services offered by the company without additional fees.
You can start your subscription to this plan at the beginning of any day and cancel your subscription at the end of any day.

Takahashi is going to use 
N
 of the services offered by the company.
He will use the 
i
-th of those services from the beginning of the 
a
i
-th day until the end of the 
b
i
-th day, where today is the first day.
Without a subscription to Snuke Prime, he has to pay 
c
i
 yen per day to use the 
i
-th service.

Find the minimum total amount of money Takahashi has to pay to use the services.

Constraints
1
≤
N
≤
2
×
10
5
1
≤
C
≤
10
9
1
≤
a
i
≤
b
i
≤
10
9
1
≤
c
i
≤
10
9
All values in input are integers.
Input
Input is given from Standard Input in the following format:

N
 
C

a
1
 
b
1
 
c
1

⋮

a
N
 
b
N
 
c
N

Output
Print the minimum total amount of money Takahashi has to pay.

Sample Input 1 
Copy
2 6
1 2 4
2 2 4
Sample Output 1 
Copy
10
He will use the 
1
-st service on the 
1
-st and 
2
-nd days, and the 
2
-nd service on the 
2
-nd day.
If he subscribes to Snuke Prime only on the 
2
-nd day, he will pay 
4
 yen on the 
1
-st day and 
6
 yen on the 
2
-nd day, for a total of 
10
 yen.
It is impossible to make the total payment less than 
10
 yen, so we should print 
10
.

Sample Input 2 
Copy
5 1000000000
583563238 820642330 44577
136809000 653199778 90962
54601291 785892285 50554
5797762 453599267 65697
468677897 916692569 87409
Sample Output 2 
Copy
163089627821228
It is optimal to do without Snuke Prime.

Sample Input 3 
Copy
5 100000
583563238 820642330 44577
136809000 653199778 90962
54601291 785892285 50554
5797762 453599267 65697
468677897 916692569 87409
Sample Output 3 
Copy
88206004785464

#######################################################################################Solution##################################################################################
*/

// Problem: D - Snuke Prime
// Contest: AtCoder - AtCoder Beginner Contest 188
// URL: https://atcoder.jp/contests/abc188/tasks/abc188_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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

/* These template codes has been taken from cp-algorithms */
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

void solve(vl& v,int N){
	
}

int main(){
	
	int N;
	ll C;
	cin>>N>>C;
	map<ll,ll> days;
	ll a,b,c;
	for(int i=0;i<N;i++){
		cin>>a>>b>>c;
		days[a]+=1ll*c;
		days[b+1]-=1ll*c;
	}
	
	vector<ll> v;
	for(auto& d:days){
		v.pb(d.f);
	}
	ll cost=0;
	long ind=0;
	ll period=0;
	ll ans=0;
	for(auto& d:days){
		if(ind==((long)days.size()-1))
			break;
		cost+=d.s;
		period=v[ind+1]-v[ind];
		ind++;
		ans+=(1ll*period)*min(cost,C);
	}
	cout<<ans<<"\n";
	return 0;	
}

