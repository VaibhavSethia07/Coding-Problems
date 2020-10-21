/*
Given an integer N, how many structurally unique binary search trees are there that store values 1...N?

Input:
First line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains a single line of input containing N.

Ouput:
For each testcase, in a new line, print the answer.

Constraints:
1<=T<=15
1<=N<=11

Example:
Input:
2
2
3
Output:
2
5

Explanation:

Testcase1:
for N = 2, there are 2 unique BSTs
     1               2  
      \            /
       2         1

Testcase2:
for N = 3, there are 5 possible BSTs
  1              3        3         2      1
    \           /        /           /    \      \
     3        2         1        1    3      2
    /       /                \                      \

######################################################################################Solution###################################################################################
*/


// Naive Method
#include <iostream>
using namespace std;

int uniqueBSTs(int);
int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    
	    cout<<uniqueBSTs(N)<<"\n";
	}
	return 0;
}

int uniqueBSTs(int N){
    if(N==0 || N==1)
        return 1;
        
    int res=0;
    for(int i=0;i<N;i++)
        res+=uniqueBSTs(N-1-i)*uniqueBSTs(i);
    
    return res;
}

// Memoization
#include <iostream>
using namespace std;

int uniqueBSTs(int,int*);
int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int dp[N+1]={0};
	    cout<<uniqueBSTs(N,dp)<<"\n";
	}
	return 0;
}

int uniqueBSTs(int N,int* dp){
    if(N==0 || N==1)
        return 1;
    
    if(dp[N]!=0)
        return dp[N];
        
    int res=0;
    for(int i=0;i<N;i++)
        res+=uniqueBSTs(N-1-i,dp)*uniqueBSTs(i,dp);
    
    return dp[N]=res;
}

// Tabulation
#include <iostream>
using namespace std;

int uniqueBSTs(int,int*);
int main() {
    int dp[12]={1};
    
    for(int i=1;i<=11;i++)
        uniqueBSTs(i,dp);
        
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    cout<<dp[N]<<"\n";
	}
	return 0;
}

int uniqueBSTs(int N,int* dp){
    int res=0;
    for(int i=0;i<N;i++)
        dp[N]+=dp[N-1-i]*dp[i];
    
    return dp[N];
}

// Using Nth Catalan Number Method
#include <iostream>
using namespace std;

int uniqueBSTs(int,int,int**);
int main() {
        
	int T;
	cin>>T;
	int* dp[2*11+1];
	for(int i=0;i<23;i++){
	    dp[i] = new int[23];
	    for(int j=0;j<23;j++)
	        dp[i][j]=0;
	}
	while(T--){
	    int N;
	    cin>>N;
	    cout<<uniqueBSTs(2*N,N,dp)/(N+1)<<"\n";
	}
	return 0;
}

int uniqueBSTs(int n,int k,int** dp){
    if(k==0 || k==n)
        return 1;
    if(k==1 || k==n)
        return n;
    if(dp[n][k]!=0)
        return dp[n][k];
        
    return dp[n][k] = uniqueBSTs(n-1,k-1,dp)+uniqueBSTs(n-1,k,dp);
}
