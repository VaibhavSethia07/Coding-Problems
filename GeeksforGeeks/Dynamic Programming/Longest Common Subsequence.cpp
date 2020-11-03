/*
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Input:
First line of the input contains no of test cases  T,the T test cases follow.
Each test case consist of 2 space separated integers A and B denoting the size of string str1 and str2 respectively
The next two lines contains the 2 string str1 and str2 .

Output:
For each test case print the length of longest  common subsequence of the two strings .

Constraints:
1<=T<=200
1<=size(str1),size(str2)<=100

Example:
Input:
2
6 6
ABCDGH
AEDFHR
3 2
ABC
AC

Output:
3
2

Explanation
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.

LCS of "ABC" and "AC" is "AC" of length 2

##############################################################################Solution###########################################################################################
*/

// Naive Method
using namespace std;

int lcs(string s1,string s2,int i,int j){
    if(i==0 || j==0)
        return 0;
    if(s1[i-1]==s2[j-1])
        return 1+lcs(s1,s2,i-1,j-1);
        
    return max(lcs(s1,s2,i-1,j),lcs(s1,s2,i,j-1));
}

int main() {
	int T;
	cin>>T;
	
	while(T-->0){
	    int N,M;
	    string s1,s2;
	    cin>>N>>M>>s1>>s2;
	    
	    cout<<lcs(s1,s2,N,M)<<"\n";
	}
	
	return 0;
}

// Memoization Solution
using namespace std;

int lcs(string s1,string s2,int i,int j,int** dp){
    if(i==0 || j==0)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
        
    if(s1[i-1]==s2[j-1])
        dp[i][j]= 1+lcs(s1,s2,i-1,j-1,dp);
    else    
        dp[i][j] = max(lcs(s1,s2,i-1,j,dp),lcs(s1,s2,i,j-1,dp));
    
    return dp[i][j];
}

int main() {
	int T;
	cin>>T;
	
	while(T-->0){
	    int N,M;
	    string s1,s2;
	    cin>>N>>M>>s1>>s2;
	    
	    int* dp[N+1];
	    for(int i=0;i<N+1;i++){
	        dp[i] = new int[M+1];
	        for(int j=0;j<M+1;j++)
	            dp[i][j] = -1;
	    }
	    cout<<lcs(s1,s2,N,M,dp)<<"\n";
	}
	
	return 0;
}

// Tabulation Solution
using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T-->0){
	    int N,M;
	    string s1,s2;
	    cin>>N>>M>>s1>>s2;
	    
	    int* dp[N+1];
	    for(int i=0;i<N+1;i++){
	        dp[i] = new int[M+1];
	        for(int j=0;j<M+1;j++){
	            dp[i][j] = -1;
	            if(i==0 || j==0)
	                dp[i][j] = 0;
	        }
	    }
	    
	    for(int i=1;i<=N;i++){
	        for(int j=1;j<=M;j++){
	            if(s1[i-1]==s2[j-1])
	                dp[i][j] = 1+dp[i-1][j-1];
	           else
	                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	       }
	    }
	    
	    cout<<dp[N][M]<<"\n";
	}
	
	return 0;
}
