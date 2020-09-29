/*
Given a positive integer n, find the nth fibonacci number. Since the answer can be very large, return the answer modulo 1000000007.

Example 1:

Input: n = 2
Output: 1 
Explanation: 1 is the 2nd number
of fibonacci series.
Example 2:

Input: n = 5
Output: 5
Explanation: 5 is the 5th number
of fibonacci series.

Your Task:  
You dont need to read input or print anything. Complete the function nthFibonacci() which takes n as input parameter and returns nth fibonacci number.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

#############################################################################Solution###############################################################################################
*/

class Solution {
  public:
    long long int nthFibonacci(long long int n){
        long long int dp[n+1];
        long long int m=1000000007;
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<=n;i++)
            dp[i]=(dp[i-1]+dp[i-2])%m;
        return dp[n];
    }
};
