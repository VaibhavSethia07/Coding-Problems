/*
Given a number N, print the first N Fibonacci numbers.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains the integer N.

Output:
Print the first n fibonacci numbers with a space between each number. Print the answer for each test case in a new line.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1<= T <=100
1<= N <=84

Example:
Input:
2
7
5

Output:
1 1 2 3 5 8 13
1 1 2 3 5

Explanation: Some of the numbers of the Fibonacci numbers are 1, 1, 2, 3, 5, 8, 13 ..... (N stars from 1).

###################################################################################Solution########################################################################################
*/

// Memoization
#include <iostream>
using namespace std;

long long int fibo(int N,long long int* dp){
    if(N==0 || N==1)
        return N;
    
    if(dp[N]!=-1)
        return dp[N];
    
    dp[N] = fibo(N-1,dp)+fibo(N-2,dp);
    cout<<dp[N]<<" ";
    return dp[N];
    
}

int main() {
    int T;
    cin>>T;
    while(T-->0){
        int N;
        cin>>N;
        long long int dp[N+1];
        for(int i=0;i<=N;i++)
            dp[i]=-1;
        cout<<1<<" ";
        
        if(N>1)
            fibo(N,dp);
        cout<<"\n";
    }
	return 0;
}

// Tabulation
#include <iostream>
using namespace std;


int main() {
    int T;
    cin>>T;
    while(T-->0){
        int N;
        cin>>N;
        long long int dp[N+1];
        dp[0] = 0;
        dp[1] = 1;
        cout<<1<<" ";
        for(int i=2;i<=N;i++){
            dp[i]=dp[i-1]+dp[i-2];
            cout<<dp[i]<<" ";
        }
        cout<<"\n";
    }
	return 0;
}
