/*
Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i] amount of money present in it.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each test case contains an integer n which denotes the number of houses. Next line contains space separated numbers denoting the amount of money in each house.

Output:
For each testcase, in a newline, print an integer which denotes the maximum amount he can take home.

Constraints:
1 <= T <= 200
1 <= n <= 104
1 <= a[i] <= 104

Example:
Input:
2
6
5 5 10 100 10 5
3
1 2 3
Output:
110
4

Explanation:
Testcase1:
5+100+5=110
Testcase2:
1+3=4

###################################################################################Solution########################################################################################
*/

// Memoization
#include <iostream>
using namespace std;

int maxLoot(int N,int* arr,int* dp){
    if(N<=0)
        return 0;
    if(dp[N]!=-1)
        return dp[N];
    
    int loot = arr[N-1]+maxLoot(N-2,arr,dp);
    int not_loot = maxLoot(N-1,arr,dp);
    return dp[N] = max(loot,not_loot);
}
int main() {
	int T;
	cin>>T;
	while(T-->0){
	    int N;
	    cin>>N;
	    int arr[N];
	    int dp[N+1];
	    for(int i=0;i<N;i++)
	        cin>>arr[i];
	    for(int i=0;i<=N;i++)
	        dp[i] = -1;
	    cout<<maxLoot(N,arr,dp)<<"\n";    
	}
	return 0;
}

// Tabulation
int main() {
	int T;
	cin>>T;
	while(T-->0){
	    int N;
	    cin>>N;
	    int arr[N];
	    int dp[N+1]={0};
	    for(int i=0;i<N;i++)
	        cin>>arr[i];
	    for(int i=1;i<=N;i++){
	        int loot = arr[i-1];
	        if(i-2>=0)
	            loot+=dp[i-2];
	        int not_loot = dp[i-1];
	        dp[i] = max(loot,not_loot);
	    }
	    cout<<dp[N]<<"\n";    
	}
	return 0;
}
