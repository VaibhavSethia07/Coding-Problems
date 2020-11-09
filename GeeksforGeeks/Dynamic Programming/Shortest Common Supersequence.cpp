/*
Given two strings str1 and str2, find the length of the smallest string which has both, str1 and str2 as its sub-sequences.
Note: str1 and str2 can have both uppercase and lowercase letters.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains two space-separated strings.

Output:
For each testcase, in a new line, output the length of the required string.

Expected Time Complexity: O(Length(str1) * Length(str2)).
Expected Auxiliary Space: O(Length(str1) * Length(str2)).

Constraints:
1 <= T <= 100
1<= |str1|, |str2| <= 100

Example:
Input:
2
abcd xycd
efgh jghi
Output:
6
6
Explanation:
Test Case 1: One of the shortest answer can be abxycd, which is of length 6.

##################################################################################Solution#########################################################################################
*/

#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T-->0){
	    string s1,s2;
	    cin>>s1>>s2;
	    long long int N = s1.length();
	    long long int M = s2.length();
	    long long int* dp[N+1];
	    for(int i=0;i<N+1;i++){
	        dp[i] = new long long int[M+1];
	        for(int j=0;j<M+1;j++)
	            dp[i][j] = 0;
	    }
	    
	    for(int a=1;a<=N;a++){
	        for(int b=1;b<=M;b++)
	            if(s1[a-1]==s2[b-1])
	                dp[a][b] = 1+dp[a-1][b-1];
	           else
	                dp[a][b] = max(dp[a-1][b],dp[a][b-1]);
	    }
	    cout<<(N+M-dp[N][M])<<"\n";
	}
	return 0;
}
