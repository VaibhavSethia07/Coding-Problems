/*
Given a M X N matrix with your initial position at the top-left cell, find the number of possible unique paths to reach the bottom-right cell of the matrix from the initial position.

Note: Possible moves can be either down or right at any point in time, i.e., we can move to matrix[i+1][j] or matrix[i][j+1] from matrix[i][j].

Input:
The first line contains an integer T, depicting the total number of test cases. Then following T lines contain two integers M and N depicting the size of the grid.

Output:
Print the number of unique paths to reach the bottom-right cell from the top-left cell.

Expected Time Complexity: O(M*N).
Expected Auxiliary Space: O(M*N).

Constraints:
1 ≤ T ≤ 30
1 ≤ M ≤ 20
1 ≤ N ≤ 20

Example:
Input:
2
2 2
3 4

Output:
2
10

Example:
Testcase 1:
There are only two unique paths to reach the end of the matrix of size two from the starting cell of the matrix.

##################################################################################Solution#######################################################################################
*/

// Memoization
#include <iostream>
using namespace std;

int uniquePaths(int a,int b,int** dp){
    if(a==1 && b==1)
        return 1;
    
    if(a<1 || b<1)
        return 0;
        
    if(dp[a][b]!=-1)
        return dp[a][b];
    return dp[a][b] = uniquePaths(a-1,b,dp)+uniquePaths(a,b-1,dp);
}

int main() {
	int T;
	cin>>T;
	
	while(T-->0){
	    int N,M;
	    cin>>N>>M;
	    int* dp[N+1];
	    for(int a=0;a<N+1;a++){
	        dp[a] = new int[M+1];
	        for(int b=0;b<M+1;b++)
	            dp[a][b] = -1;
	    }
	    
	    cout<<uniquePaths(N,M,dp)<<"\n";
	}
	return 0;
}

// Tabulation
int main() {
	int T;
	cin>>T;
	
	while(T-->0){
	    int N,M;
	    cin>>N>>M;
	    int* dp[N+1];
	    for(int a=0;a<N+1;a++)
	        dp[a] = new int[M+1];
	    for(int a=1;a<N+1;a++){
	        for(int b=1;b<M+1;b++){
	            if(a==1 && b==1)
	                dp[a][b] = 1;
	            else
	                dp[a][b] = dp[a-1][b]+dp[a][b-1];
	        }
	    }
	    cout<<dp[N][M]<<"\n";
	}
	return 0;
}
