/*
Given two integers n and r, find nCr. Since the answer may be very large, calculate the answer modulo 109+7.

Example 1:

Input: n = 3, r = 2
Output: 3
Explaination: 3C2 = 3. 

Example 2:

Input: n = 2, r = 4
Output: 0
Explaination: r is greater than n.

Your Task:
You do not need to take input or print anything. Your task is to complete the function nCr() which takes n and r as input parameters and returns nCr modulo 109+7..


Expected Time Complexity: O(n*r)
Expected Auxiliary Space: O(r)


Constraints:
1 ≤ n ≤ 1000
1 ≤ r ≤ 800

##################################################################################Solution#########################################################################################
*/

// Memoization
class Solution{
    int mod = 1e9+7;
    int dp[1001][801]={{0}};
public:
    int nCr(int n, int r){
        if(r>n)
            return 0;
        if(r==0 || r==n)
            return 1;
        if(r==1 || r==n-1)
            return n;
        if(dp[n][r]!=0)
            return dp[n][r];
            
        return dp[n][r]=(nCr(n-1,r)%mod+nCr(n-1,r-1)%mod)%mod;
    }   
};

// Tabulation
class Solution{
    long long int dp[1001][1001]={{0}};
    long long int mod=1e9+7;
    
    
public:
    int nCr(int n, int r){
        if(r>n)
            return 0;
        nCrUtil();
        return dp[n][r];
    }
    long long int nCrUtil(){
        dp[0][0]=1;
        for(int i=1;i<1001;i++){
            dp[i][0]=1;
            for(int j=1;j<=i;j++)
                dp[i][j] = (dp[i-1][j]%mod+dp[i-1][j-1]%mod)%mod;
        }
        
        return 0;
    }
};
