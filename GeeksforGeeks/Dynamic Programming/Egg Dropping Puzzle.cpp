/*
Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such that it doesn't break. You have to determine the minimum number of attempts you need in order find the critical floor in the worst case while using the best strategy.There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
For more description on this problem see wiki page

Example 1:

Input:
N = 2, K = 10
Output: 4
Example 2:

Input:
N = 3, K = 5
Output: 3
Your Task:
Complete the function eggDrop() which takes two positive integer N and K as input parameters and returns the minimum number of attempts you need in order to find the critical floor.

Expected Time Complexity : O(N*K)
Expected Auxiliary Space: O(N*K)

Constraints:
1<=N<=10
1<=K<=50

#################################################################################################Solution##########################################################################
*/

int eggDrop(int e, int f) 
{
    int dp[f+1][e+1]={0};
    for(int i=1;i<=e;i++){
        dp[0][i] = 0;
        dp[1][i] = 1;
    }
    
    for(int i=0;i<=f;i++){
        dp[i][0] = 0;
        dp[i][1] = i;
    }
    
    for(int i=2;i<=f;i++){
        for(int j=2;j<=e;j++){
            dp[i][j] = INT_MAX;
            for(int k=1;k<=i;k++){
                int broke = dp[k-1][j-1];
                int not_broke = dp[i-k][j];
                dp[i][j]  = min(dp[i][j],1+max(broke,not_broke));
            }
        }
    }
    return dp[f][e];
}
