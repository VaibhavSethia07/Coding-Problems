// Problem: Book Shop
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1158
// Memory Limit: 512 MB
// Time Limit: 1000 ms
 
#include <bits/stdc++.h>
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int X,N;
    cin>>N>>X;
    
    vector<int> price(N);
    vector<int> pages(N);
    vector<vector<int>> dp(N+1,vector<int>(X+1));
    
    for(int& a:price)
    	cin>>a;
    
    for(int& a:pages)
    	cin>>a;
    
	for(int i=1;i<=N;i++){
		for(int x=1;x<=X;x++){
			if(x-price[i-1]>=0)
				dp[i][x]=pages[i-1]+dp[i-1][x-price[i-1]];
			dp[i][x]=max(dp[i][x],dp[i-1][x]);
		}
	}
	
	cout<<dp[N][X]<<"\n";
	return 0;	
}
