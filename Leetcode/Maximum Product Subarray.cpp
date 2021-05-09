#include <bits/stdc++.h>
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        long mx=nums[0],mn=nums[0],res=nums[0];
        
        for(int i=1;i<(int)nums.size();i++){
            if(nums[i]<0)
                swap(mx,mn);
            
            mn=min((long)nums[i],nums[i]*mn);
            mx=max((long)nums[i],nums[i]*mx);
            res=max({res,mn,mx});
        }
        
        return res;
    }
};
