/*
ou are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).

Example 1:

Input:
N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3
Example 2:

Input:
N = 3
W = 3
values[] = {1,2,3}
weight[] = {4,5,6}
Output: 0
Your Task:
Complete the function knapSack() which takes maximum capacity W, weight array wt[], value array val[] and number of items n as a parameter and returns the maximum possible value you can get.

Expected Time Complexity: O(N*W).
Expected Auxiliary Space: O(N*W)

Constraints:
1 ≤ N ≤ 1000
1 ≤ W ≤ 1000
1 ≤ wt[i] ≤ 1000
1 ≤ v[i] ≤ 1000

########################################################################################Solution###################################################################################
*/

// Memoization
int knapSack01(int N,int W,int* wt,int* val,int** dp){
    if(N==0 || W==0)
        return 0;
    if(dp[N][W]!=-1)
        return dp[N][W];
    int left=0;
    if(W-wt[N-1]>=0)
        left = val[N-1]+knapSack01(N-1,W-wt[N-1],wt,val,dp);
    int right = knapSack01(N-1,W,wt,val,dp);
    return dp[N][W] = max(left,right);
}
int knapSack(int W, int wt[], int val[], int n) 
{ 
    int* dp[n+1];
    for(int i=0;i<=n;i++){
         dp[i] = new int[W+1];
        for(int j=0;j<=W;j++)
           dp[i][j] = -1;
    }
    return knapSack01(n,W,wt,val,dp);
}

// Tabulation
int knapSack(int W, int wt[], int val[], int n) 
{ 
    int* dp[n+1];
    for(int i=0;i<=n;i++)
         dp[i] = new int[W+1];
         
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            int left=0;
            if(j-wt[i-1]>=0)
                left = val[i-1]+dp[i-1][j-wt[i-1]];
            int right = dp[i-1][j];
            dp[i][j] = max(left,right);
        }
    }
    return dp[n][W];
}
