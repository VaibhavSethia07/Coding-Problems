/*
You are given an array A of size N. The array contains integers and is of even length. The elements of the array represent N coin of values V1, V2, ....Vn. You play against an opponent in an alternating way.

In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.

You need to determine the maximum possible amount of money you can win if you go first.

Example 1:

Input:
N = 4
A[] = {5,3,7,10}
Output: 15
Explanation: The user collects maximum
value as 15(10 + 5)
Example 2:

Input:
N = 4
A[] = {8,15,3,7}
Output: 22
Explanation: The user collects maximum
value as 22(7 + 15)
Your Task:
Complete the function maximumAmount() which takes an array arr[] (represent values of N coins) and N as number of coins as a parameter and returns the maximum possible amount of money you can win if you go first.

Expected Time Complexity : O(N*N)
Expected Auxiliary Space: O(N*N)

Constraints:
2 <= N <= 100
1 <= Ai <= 106

###########################################################################################Solution##############################################################################
*/

// Memoization
long long strategy(int* arr,int i,int j,long long** dp){
    if(i+1==j)
        return max(arr[i],arr[j]);
    
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    long long strategy1 = arr[i]+min(strategy(arr,i+2,j,dp),strategy(arr,i+1,j-1,dp));
    long long strategy2 = arr[j]+min(strategy(arr,i+1,j-1,dp),strategy(arr,i,j-2,dp));
    
    return dp[i][j] = max(strategy1,strategy2);
}



long long maximumAmount(int arr[], int n) 
{
    long long* dp[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new long long[n+1];
        for(int j=0;j<=n;j++)
            dp[i][j] =-1;
    }
        
    return strategy(arr,0,n-1,dp);
}

// Tabulation
long long maximumAmount(int arr[], int n) 
{
    long long dp[n][n]={0};
    
    for(int i=0;i<n-1;i++)
        dp[i][i+1] = max(arr[i],arr[i+1]);
        
    for(int gap=3;gap<n;gap+=2){
        for(int i=0;i+gap<n;i++){
            int j=i+gap;
             long long subres1 = arr[i]+min(dp[i+2][j],dp[i+1][j-1]);
             long long subres2 = arr[j]+min(dp[i+1][j-1],dp[i][j-2]);
             dp[i][j] = max(subres1,subres2);
        }
    }
    
    return dp[0][n-1];
}
