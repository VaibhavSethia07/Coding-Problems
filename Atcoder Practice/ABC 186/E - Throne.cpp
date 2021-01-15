/*
We have 
N
 chairs arranged in a circle, one of which is a throne.

Takahashi is initially sitting on the chair that is 
S
 chairs away from the throne in the clockwise direction. Now, he will repeat the move below.

Move: Go to the chair that is 
K
 chairs away from the chair he is currently sitting on in the clockwise direction.

After how many moves will he be sitting on the throne for the first time? If he is never going to sit on it, report -1 instead.

You are asked to solve 
T
 test cases.

Constraints
1
≤
T
≤
100
2
≤
N
≤
10
9
1
≤
S
<
N
1
≤
K
≤
10
9
Input
Input is given from Standard Input in the following format. The first line is in the format below:

T

Then, the following 
T
 lines represent 
T
 test cases. Each of these lines is in the format below:

N
 
S
 
K

Output
For each test case, print the answer in its own line.

Sample Input 1 
Copy
4
10 4 3
1000 11 2
998244353 897581057 595591169
10000 6 14
Sample Output 1 
Copy
2
-1
249561088
3571
In the first test case, we have 
10
 chairs, and Takahashi is initially sitting on the chair that is 
4
 chairs away from the throne in the clockwise direction. He will be sitting on the throne after 
2
 moves of moving 
3
 chairs in the clockwise direction.

In the second test case, he will never sit on the throne, so we should print -1.

##################################################################################Solution#######################################################################################
*/

// Problem: E - Throne
// Contest: AtCoder - Panasonic Programming Contest (AtCoder Beginner Contest 186)
// URL: https://atcoder.jp/contests/abc186/tasks/abc186_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using db = double;
using str = string;

using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vl = vector<ll>;

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

int main(){
	int T;
	ll N,S,K;
	cin>>T;
	while(T--){
		cin>>N>>S>>K;
		cout<<linearCong(K,N-S,N)<<"\n";
	}
	
	return 0;	
}
