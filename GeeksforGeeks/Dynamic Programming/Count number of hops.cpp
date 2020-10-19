/*
A frog jumps either 1, 2 or 3 steps to go to top. In how many ways can it reach the top.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each testcase contains one line of input N denoting the total number of steps.

Output:
For each testcase, in a new line, print the number of ways to reach the top.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 50

Example:
Input:
2
1
5
Output:
1
13

##########################################################################################Solution#################################################################################
*/

// Memoization
#include <iostream>
using namespace std;

int countHops(int,int*);

int main() {
	int T;
	cin>>T;
	while(T-->0){
	    int N;
	    cin>>N;
	    int dp[N+1];
	    for(int i=0;i<=N;i++)
	        dp[i]=-1;
	    dp[0] = 0;
	    cout<<countHops(N,dp)<<"\n";
	}
	return 0;
}

int countHops(int N,int* dp){
    if(N==0)
        return 1;
    if(N<0)
        return 0;
     
    if(dp[N]!=-1)
        return dp[N];
    return dp[N]=(countHops(N-1,dp)+countHops(N-2,dp)+countHops(N-3,dp));
}

// Improved Memoization (Array declared globally)
#include <iostream>
using namespace std;

int countHops(int);
int dp[51];
int main() {
	int T;
	cin>>T;
	for(int i=0;i<=51;i++)
	    dp[i] =-1;
	dp[0] = 0;
	countHops(50);
	while(T-->0){
	    int N;
	    cin>>N;
	    cout<<dp[N]<<"\n";
	}
	return 0;
}

int countHops(int N){
    if(N==0)
        return 1;
    if(N<0)
        return 0;
     
    if(dp[N]!=-1)
        return dp[N];
    return dp[N]=(countHops(N-1)+countHops(N-2)+countHops(N-3));
}

// Tabulation
#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	int dp[51];
	dp[0] = 1;
	for(int i=1;i<51;i++){
	    dp[i] =0;
	    if(i-1>=0)
	        dp[i]+=dp[i-1];
	    if(i-2>=0)
	        dp[i]+=dp[i-2];
	    if(i-3>=0)
	        dp[i]+=dp[i-3];
	}
	while(T-->0){
	    int N;
	    cin>>N;
	    if(N==0)
	        cout<<0<<"\n";
	    else
	        cout<<dp[N]<<"\n";
	}
	return 0;
}
