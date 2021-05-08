class Solution {
public:
    int circular_rob(vector<int>& nums,int start,int end){
        int dp[nums.size()+1];
        
        dp[start]=nums[start];
        dp[start+1]=max(nums[start],nums[start+1]);
        
        for(int i=start+2;i<=end;i++){
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        
        return dp[end];
    }
    
    int rob(vector<int>& nums) {
        int n=(int)nums.size();
        
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        return max(circular_rob(nums,0,n-2),circular_rob(nums,1,n-1));
    }
};
