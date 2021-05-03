// Problem: C - MAD TEAM
// Contest: AtCoder - ZONe Energy Programming Contest
// URL: https://atcoder.jp/contests/zone2021/tasks/zone2021_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
using namespace std;

const int MAXN=3e3+3;
long mat[MAXN][5];
int n;
void input(int n){
	for(int i=0;i<n;i++)
		for(int j=0;j<5;j++)
			cin>>mat[i][j];
}
set<long> cache;
bool is_valid(long& mid){
	cache.clear();
	for(int i=0;i<n;i++){
		long mask=0;
		for(int j=0;j<5;j++){
			mask<<=1; // add the bit
			if(mat[i][j]>=mid){
				mask|=1; // make bit set
			}
		}
		cache.insert(mask);
	}
	
	for(long x:cache){
		for(long y:cache)
			for(long z:cache)
				if(((x|y)|z)==31l)
					return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin>>n;
	input(n);
	
	long start=1,end=INT_MAX;
	long ans=1;
	while(start<=end){
		long mid=start+(end-start)/2;
		// cout<<mid<<"\n";
		if(is_valid(mid)){
			ans=mid;
			start=mid+1;
		}else
			end=mid-1;
	}
	cout<<ans;
	return 0;	
}
