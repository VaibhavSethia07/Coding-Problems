/*
Bessie and her little sister Elsie are picking berries in Farmer John's berry patch. Farmer John's patch has exactly N berry trees (1≤N≤1000); tree i contains exactly Bi berries (1≤Bi≤1000). Bessie has exactly K baskets (1≤K≤1000, K even). Each basket can hold as many berries from a single tree as Bessie wants, but cannot contain berries from two different trees as their flavors will clash with each other. Baskets may remain empty.
Bessie wants to maximize the number of berries she collects. However, Farmer John wants Bessie to share with her little sister, and so Bessie will have to give Elsie the K/2 baskets with the largest number of berries. This means that Elsie may even end up with more berries than Bessie, which is very unfair, but unfortunately, sibling dynamics are not always fair.

Help Bessie figure out the maximum number of berries she can collect.

SCORING:
Test cases 1-4 satisfy K≤10.
Test cases 5-11 satisfy no additional constraints.
INPUT FORMAT (file berries.in):
The first line of input contains space-separated integers N and K.
The second line contains N space-separated integers B1,B2,…,BN.

OUTPUT FORMAT (file berries.out):
A single line with the answer.
SAMPLE INPUT:
5 4
3 6 8 4 2
SAMPLE OUTPUT:
8
If Bessie fills

one basket with 6 berries from tree 2
two baskets, each with 4 berries from tree 3
one basket with 4 berries from tree 4
then she receives two baskets each with 4 berries, giving her 8 berries in total.

Problem credits: Nathan Pinsker

##########################################################################################Solution#################################################################################
*/

// Problem: Problem 1. Berry Picking
// Contest: USACO - USACO 2020 January Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=990
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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

long solve(vector<long>& trees,long T,long B,long mx){
	vl buckets;
	for(int i=0;i<T;i++){
		if(mx>=trees[i]){
			buckets.pb(trees[i]);
		}else{
			long b=trees[i]/mx;
			for(int j=0;j<b;j++){
				buckets.pb(mx);
			}
			long rem=trees[i]-b*mx;
			if(rem>0)
				buckets.pb(rem);
		}
	}
	sort(all(buckets));
	reverse(all(buckets));
	long sub_ans=0;
	for(int i=B/2;i<min(B,(long)buckets.size());i++){
		sub_ans+=buckets[i];
	}
	return sub_ans;
}

int main(){
	freopen("berries.in","r",stdin);
	freopen("berries.out","w",stdout);
	long T,B;
	cin>>T>>B;
	vector<long> trees(T);
	long mx=0;
	for(int i=0;i<T;i++){
		cin>>trees[i];
		mx=max(mx,trees[i]);
	}
	long ans=0;
	for(int i=1;i<=mx;i++){
		ans=max(solve(trees,T,B,i),ans);
	}
	cout<<ans<<"\n";
	
	return 0;	
}
