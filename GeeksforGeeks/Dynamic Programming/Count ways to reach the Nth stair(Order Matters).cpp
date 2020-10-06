/*
There are N stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does matter).

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, an integer N will be given.

Output:
For each testcase, in a new line, print number of possible ways to reach Nth stair. Answer your output % 10^9+7.

Constraints:
1<=T<=105
1<=N<=105

Example:
Input:
3
4
10
24
Output:
5
89
75025

################################################################################Solution############################################################################################
*/

// Memoization
#include <iostream>
using namespace std;
int mod = 1000000000+7;
long long int dp[100001]={0};
	    
long long int ways(int N,long long int* dp){
    if(N==1)
        return 1;
        
    if(N==2)
        return 2;
    if(dp[N]!=0)
        return dp[N];
    return dp[N] = (ways(N-1,dp)%mod+ways(N-2,dp)%mod)%mod;
    
}

int main() {
	int T;
	cin>>T;
	dp[1] = 1;
	dp[2] = 2;
	    
	dp[100000] = ways(100000,dp);
	while(T-->0){
	    int N;
	    cin>>N;
	    cout<<dp[N]%mod<<"\n";
	}
	return 0;
}

// Tabulation
#include <iostream>
using namespace std;
int mod = 1000000000+7;
int dp[100001]={0};
	    
int main() {
	int T;
	cin>>T;
	dp[1] = 1;
	dp[2] = 2;
	    
	for(int i=3;i<=100000;i++)
	        dp[i] = (dp[i-1]%mod+dp[i-2]%mod)%mod;
	
	while(T-->0){
	    int N;
	    cin>>N;
	    cout<<dp[N]<<"\n";
	   // cout<<ways(N,dp)<<"\n";
	}
	return 0;
}
