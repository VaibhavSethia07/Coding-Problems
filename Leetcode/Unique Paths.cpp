class Solution {
public:
    int uniquePaths(int m, int n) {
        long dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=n-1;i>=0;i--)
            dp[m-1][i]=1;
        
        for(int i=m-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
       
        return dp[0][0];
    }
};
