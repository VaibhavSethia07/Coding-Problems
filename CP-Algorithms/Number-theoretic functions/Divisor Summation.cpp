/*
Given a natural number n (1 <= n <= 500000), please output the summation of all its proper divisors.

Definition: A proper divisor of a natural number is the divisor that is strictly less than the number.

e.g. number 20 has 5 proper divisors: 1, 2, 4, 5, 10, and the divisor summation is: 1 + 2 + 4 + 5 + 10 = 22.

 

Input
An integer stating the number of test cases (equal to about 200000), and that many lines follow, each containing one integer between 1 and 500000 inclusive.

Output
One integer each line: the divisor summation of the integer given respectively.

Example
Sample Input:
3
2
10
20

Sample Output:
1
8
22

############################################################################################Solution###############################################################################
*/

// Problem: Divisor Summation
// Contest: SPOJ - Tutorial
// URL: https://www.spoj.com/problems/DIVSUM/
// Memory Limit: 1536 MB
// Time Limit: 3000 ms
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

#define FOR(i,a,b) for (int i = (a); i<(b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for(int i = (b)-1; i>=(a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

void prime_fact(map<int,int>& d,ll N){
	for(int i=2;i*i<=N;i++){
		if((N%i)==0){
			int cnt=1;
			while((N%i)==0){
				N/=i;
				cnt++;
			}
			d[i]=cnt;
		}
	}
	if(N>1){
		d[N]=2;
	}
}

int main(){
	int T;
	cin>>T;
	ll N;
	while(T--){
		cin>>N;
		map<int,int> d;
		prime_fact(d,N);
		ll ans=1;
		for(auto& p:d){
			ll sub_ans=(ll)(pow(p.f,p.s)+0.5)-1;
			sub_ans/=(p.f-1);
			ans*=(1ll*sub_ans);
		}
		ans-=N;
		printf("%I64d\n",(ll)ans);
	}
	
	return 0;	
}
