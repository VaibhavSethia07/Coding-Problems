
class Solution {
public:
    string longestPalindrome(string s) {
        int N=s.length();
        
        bool dp[N][N];
        memset(dp,false,sizeof(dp));
        int ans=1;
        int pos=0;
        /* Iterate over the lengths */
        for(int L=1;L<=N;L++){
            for(int i=0,j=L-1;j<N;i++,j++){
               if(L==1)
                    dp[i][j]=1;
                else if(L==2 && s[i]==s[j])
                    dp[i][j]=1;
                else{
                    if(s[i]==s[j] && dp[i+1][j-1])
                        dp[i][j]=1;
                }
                
                if(dp[i][j]){
                    ans=L;
                    pos=i;
                }
            }
        }
        return s.substr(pos,ans);   
    }
};
