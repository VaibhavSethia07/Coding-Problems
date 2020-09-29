/*
Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins. 

Example 1:

Input:
n = 4 , m = 3
S[] = {1,2,3}
Output: 4
Explanation: Four Possible ways are:
{1,1,1,1},{1,1,2},{2,2},{1,3}.

â€‹Example 2:

Input:
n = 10 , m = 4
S[] ={2,5,3,6}
Output: 5
Explanation: Five Possible ways are:
{2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} 
and {5,5}.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function count() which accepts an array S[] its size m and n as input parameter and returns the number of ways to make change for N cents.



Expected Time Complexity: O(m*n).
Expected Auxiliary Space: O(n). 

#########################################################################################Solution##################################################################################
*/

// Memoization
class Solution
{
  public:
    long long int minCount(int coins[],int sum,int N,long long int** dp,int M){
        if(sum==0)
            return 1;
        if(N>=M || sum<0)
            return 0;
        if(dp[sum][N]!=-1)
            return dp[sum][N];
        
        long long pick = minCount(coins,sum-coins[N],N,dp,M);
        long long dontpick = minCount(coins,sum,N+1,dp,M);
        return dp[sum][N]=pick+dontpick;
        
    }
    long long int count( int S[], int m, int n )
    {
        long long int** dp = new long long int*[n+1]; 
        for(int i=0;i<=n;i++){
            dp[i] = new long long int[m+1];
            for(int j=0;j<=m;j++)
                dp[i][j] = -1;
        }
        
        return minCount(S,n,0,dp,m);
     
    }
};

// Tabulation 
class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
       long long int** dp = new long long int*[n+1];
       for(int i=0;i<=n;i++){
           dp[i] = new long long int[m+1];
           dp[i][0]=0;
           for(int j=0;j<=m;j++)
                dp[0][j]=1;
       }
       
       for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i-S[j-1]>=0)
                    dp[i][j] = dp[i-S[j-1]][j];
                dp[i][j]+= dp[i][j-1];
            }
       }
       
       return dp[n][m];
    }
};
