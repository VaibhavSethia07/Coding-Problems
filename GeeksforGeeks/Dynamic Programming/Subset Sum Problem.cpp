/*
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.

Example 2:

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explaination: This array can never be 
partitioned into two such parts.

Your Task:
You do not need to read input or print anything. Your task is to complete the function equalPartition() which takes the value N and the array as input parameters and returns 1 if the partition is possible. Otherwise, returns 0.


Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(N*sum of elements)


Constraints:
1 ≤ N ≤ 100
1 ≤ arr[i] ≤ 1000

############################################################################################Solution###############################################################################
*/

// Memoization
class Solution{
public:
    int subset_sum(int* arr,int N,int sum,int target,int** dp){
        if(N==0)
            return 0;
        if(sum==target)
            return 1;
        if(sum>target)
            return 0;
        if(dp[N][sum]!=-1)
            return dp[N][sum];
            
        int left = subset_sum(arr,N-1,sum+arr[N-1],target,dp);
        if(left)
            return dp[N][sum]=1;
        int right = subset_sum(arr,N-1,sum,target,dp);
        if(right)
            return dp[N][sum]=1;
        return dp[N][sum]=0;
    }
    int equalPartition(int N, int arr[])
    {
        int target=0;
        for(int i=0;i<N;i++)
            target+=arr[i];
            
        if(target%2==1)
            return 0;
        int* dp[N+1];
        for(int i=0;i<=N;i++){
            dp[i] = new int[target/2+1];
            for(int j=0;j<target/2+1;j++)
                dp[i][j] = -1;
        }
        return subset_sum(arr,N,0,target/2,dp);    
    }
};

// Tabulation
class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int target=0;
        for(int i=0;i<N;i++)
            target+=arr[i];
            
        if(target%2==1)
            return 0;
        if(target==0)
            return 1;
        target/=2;
        bool dp[N+1][target+1]={0};
        for(int i=0;i<=N;i++)
            dp[i][0]=true;
        for(int i=0;i<target+1;i++)
            dp[0][i] = false;
 
        for(int i=1;i<=N;i++){
            for(int j=1;j<=target;j++){
               if(j<arr[i-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
        }
        return dp[N][target]?1:0;    
    }
};
