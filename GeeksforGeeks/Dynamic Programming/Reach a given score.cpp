/*
Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find the number of distinct combinations to reach the given score.

Input:
The first line of input contains an integer T denoting the number of test cases. T test cases follow. The first line of each test case is n.

Output:
For each testcase, in a new line, print the number of ways/combinations to reach the given score.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ T ≤ 100
1 ≤ n ≤ 1000

Example:
Input:
3
8
20
13

Output:
1
4
2

Explanation
For 1st example when n = 8
{ 3, 5 } and {5, 3} are the two possible permutations but these represent the same cobmination. Hence output is 1.

#####################################################################################Solution######################################################################################
*/

// Naive Solution
#include <iostream>
using namespace std;

long long int moves(int* arr,int N,int M){
    if(N==0)
        return 1;
    if(N<0 || M==0)
        return 0;
    long int score=moves(arr,N-arr[M-1],M);
    long int noscore=moves(arr,N,M-1);
    return score+noscore;
}

int main() {
    int T;
    cin>>T;
    while(T-->0){
        int N;
        cin>>N;
        int arr[]={3,5,10};
        cout<<moves(arr,N,3)<<"\n";
    }
	return 0;
}

// Memoization
#include <iostream>
using namespace std;

long long int moves(int* arr,int N,int M,int** dp){
    if(N==0)
        return 1;
    if(N<0 || M==0)
        return 0;
    if(dp[N][M]!=-1)
        return dp[N][M];
    long int score=moves(arr,N-arr[M-1],M,dp);
    long int noscore=moves(arr,N,M-1,dp);
    return dp[N][M]=score+noscore;
}

int main() {
    int T;
    cin>>T;
    while(T-->0){
        int N;
        cin>>N;
        int arr[]={3,5,10};
        int** dp = new int*[N+1];
        for(int i=0;i<=N;i++){
            dp[i] = new int[4];
            for(int j=0;j<4;j++)
                dp[i][j] = -1;
        }
        cout<<moves(arr,N,3,dp)<<"\n";
    }
	return 0;
}

// Tabulation
#include <iostream>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T-->0){
        int N;
        cin>>N;
        int arr[]={3,5,10};
        int** dp = new int*[N+1];
        for(int i=0;i<=N;i++){
            dp[i] = new int[4];
            for(int j=0;j<4;j++){
                dp[i][j]=0;
                dp[0][j] = 1;
            }
            dp[i][0]=0;
        }
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=4;j++){
                if(i-arr[j-1]>=0)
                    dp[i][j]+=dp[i-arr[j-1]][j];
                dp[i][j]+=dp[i][j-1];
            }
        }
        cout<<dp[N][3]<<"\n";
    }
	return 0;
}
