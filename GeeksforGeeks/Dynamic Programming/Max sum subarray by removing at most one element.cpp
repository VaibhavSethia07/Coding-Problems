/*
You are given array A of size n. You need to find the maximum-sum sub-array with the condition that you are allowed to skip at most one element.

Example 1:

Input:
n = 5
A[] = {1,2,3,-4,5}
Output: 11
Explanation: We can get maximum sum
subarray by skipping -4.
Example 2:

Input:
n = 8
A[] = {-2,-3,4,-1,-2,1,5,-3}
Output: 9
Explanation: We can get maximum sum
subarray by skipping -2 as [4,-1,1,5]
sums to 9, which is the maximum
achievable sum.
Your Task:

Your task is to complete the function maxSumSubarray that take array and size as parameters and returns the maximum sum.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= n <= 100
-103 <= Ai<= 103

#######################################################################################Solution#####################################################################################
*/

// Naive Solution
int maxSumSubarray(int A[], int n)
{
   int res=INT_MIN;
   
   for(int start=0;start<n;start++){
       int curr=0;
       int mn=INT_MAX;
       for(int end=start;end<n;end++){
           curr+=A[end];
           if(end-1>=start){
                mn=min(mn,A[end-1]);
                res=max(res,max(curr,curr-mn));
           }
           else
                res=max(res,curr);
       }
   }
   
   return res;
}

// Optimized Solution
int maxSumSubarray(int arr[], int n)
{
    int fwd[n];
    int bwd[n];
    
    int curr = arr[0];
    int global = arr[0];
    fwd[0] = arr[0];
    bwd[n-1] = arr[n-1];
    
    for(int i=1;i<n;i++){
        curr = max(arr[i],curr+arr[i]);
        fwd[i] = curr;
        global = max(global,curr);
    }
    curr = arr[n-1];
    for(int i=n-2;i>=0;i--){
        curr = max(arr[i],curr+arr[i]);
        bwd[i] = curr;
    }
    
    global = max(global, max(bwd[1],fwd[n-1]));
    
    for(int i=1;i<n-1;i++)
        global = max(global, fwd[i-1]+bwd[i+1]);
        
    return global;
}
