class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        long dp[n+1][m+1];
        
        memset(dp,0,sizeof(dp));
        if(obstacleGrid[n-1][m-1] || obstacleGrid[0][0])
            return 0;
        dp[n-1][m-1]=1;
        for(int i=m-2;i>=0;i--)
            if(obstacleGrid[n-1][i]==0)
                dp[n-1][i]=dp[n-1][i+1];
                    
        for(int i=n-2;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(obstacleGrid[i][j]==0)
                    dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cout<<dp[i][j]<<" ";
            cout<<"\n";
        }
        return dp[0][0];
    }
};
