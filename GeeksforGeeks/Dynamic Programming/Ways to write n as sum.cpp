/*
Given a positive integer N, the task is to find the number of different ways in which N can be written as a sum of two or more positive integers.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains the integer N. 

Output:
For each testcase, in a new line, output the number of ways N can be written as the sum of two or more positive integers for each test case in a new line. Since the answer can be quite large print the answer modulo 109+7.

Constraints:
1 <= T <= 100
1 <= N <= 103

Example:
Input:
2
5
3
Output:
6
2

Explanation:
Testcase1:
5:
1+1+1+1+1
1+1+1+2
1+1+3
1+4
2+1+2
2+3
So, a total of 6 ways.

############################################################################################Solution#############################################################################
*/

#include <iostream>
using namespace std;
long long int mod=1000000000+7;
long long int* dp[1001] ;
long long int ways(int N,int start,long long int** dp){
    if(N==0)
        return 1;
    if(N<0)
        return 0;
    if(start>N)
        return 0;
    if(dp[N][start]!=-1)
        return dp[N][start];
    long long int left = ways(N-start,start,dp)%mod;
    long long int right = ways(N,start+1,dp)%mod;
    return dp[N][start]=(left%mod+right%mod)%mod;
}

int main() {
	int T;
	cin>>T;
	for(int i=0;i<1001;i++){
	    dp[i] = new long long int[1001];
	    for(int j=0;j<1001;j++)
	       dp[i][j] = -1;
	}
	
	    
	while(T-->0){
	    int N;
	    cin>>N;
	    cout<<ways(N,1,dp)-1<<"\n";
	}
	return 0;
}
