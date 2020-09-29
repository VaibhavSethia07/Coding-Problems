/*
Given a value V and array coins[] of size M, the task is to make the change for V cents, given that you have an infinite supply of each of coins{coins1, coins2, ..., coinsm} valued coins. Find the minimum number of coins to make the change. If not possible to make change then output -1

Example 1:

Input: V = 30, M = 3, coins[] = {25, 10, 5}
Output: 2
Explanation: Use one 25 cent coin
and one 5 cent coin
Example 2:
Input: V = 11, M = 4,coins[] = {9, 6, 5, 1} 
Output: 2 
Explanation: Use one 6 cent coin
and one 5 cent coin

Your Task:  
You don't need to read input or print anything. Complete the function minCoins() which takes V, M and array coins as input parameters and returns the answer.

Expected Time Complexity: O(V*M)
Expected Auxiliary Space: O(V)

Constraints:
1 ≤ V*M ≤ 106
All the elements of array are distinct

######################################################################################Solution#####################################################################################
*/
// Memoization 
class Solution{

	public:
	int minCoinsDP(int* coins,int M,int V,int* dp){
	    if(V==0)
	        return 0;
	    if(V<0)
	        return -1;
	    if(dp[V]!=-1)
	        return dp[V];
	    Solution sol;  
	    int res = INT_MAX;
	    for(int i=0;i<M;i++){
	        int sub_res = sol.minCoinsDP(coins,M,V-coins[i],dp);
	        if(sub_res!=-1)
	            res = min(res,sub_res+1);
	    }
	    
	    if(res==INT_MAX)
	        return dp[V]=-1;
	   return dp[V]=res;
	    
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    int dp[V+1];
	    for(int i=0;i<=V;i++)
	        dp[i]=-1;
	    Solution sol;
	    return sol.minCoinsDP(coins,M,V,dp);
	}
	  
};

// Tabulation
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    int dp[V+1];
	    for(int i=0;i<=V;i++)
	        dp[i] = INT_MAX;
	    dp[0]=0;  
	    for(int i=0;i<=V;i++){
	        for(int j=0;j<M;j++){
	            if(i-coins[j]>=0){
	                int sub_res  = dp[i-coins[j]];
	                if(sub_res!=INT_MAX)
	                    dp[i] = min(dp[i],sub_res+1);
	            }
	        }
	    }
	    if(dp[V]!=INT_MAX)
	       return dp[V];
	    return -1;
	}
};
