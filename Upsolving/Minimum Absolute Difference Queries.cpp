class Solution {
public:
   
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int N=(int)nums.size();
        vector<int> result;
        
        vector<vector<int>> prefix(N,vector<int>(101));
        for(int i=0;i<N;i++){
            prefix[i][nums[i]]=1;
        }
        
        for(int i=0;i<101;i++){
            for(int j=1;j<N;j++){
                prefix[j][i]+=prefix[j-1][i];
            }
        }
        
        for(int q=0;q<(int)queries.size();q++){
            int left=queries[q][0],right=queries[q][1];
            
            int prev=-1,ans=1e9;
            for(int i=1;i<101;i++){
                int freq;
                if(left==0)
                    freq=prefix[right][i];
                else
                    freq=prefix[right][i]-prefix[left-1][i];
                
                if(freq!=0){
                    if(prev!=-1){
                        ans=min(ans,i-prev);
                    }
                    prev=i;
                }
            }
            
            if(ans==1e9)
                ans=-1;
            
            result.push_back(ans);
        }
        return result;
    }
};
