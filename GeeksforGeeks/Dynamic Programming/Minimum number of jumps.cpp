/*
Given an array of integers where each element represents the max number of steps that can be made forward from that element. The task is to find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.

Input: 
The first line contains an integer T, depicting total number of test cases.  Then following T lines contains a number n denoting the size of the array. Next line contains the sequence of integers a1, a2, ..., an.

Output:
For each testcase, in a new line, print the minimum number of jumps. If answer is not possible print "-1"(without quotes).

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
0 <= ai <= 107

Example:
Input:
2
11
1 3 5 8 9 2 6 7 6 8 9
6
1 4 3 2 6 7
Output:
3
2

Explanation:
Testcase 1: First jump from 1st element, and we jump to 2nd element with value 3. Now, from here we jump to 5h element with value 9. and from here we will jump to last.

##########################################################################Solution##################################################################################################
*/

// Memoization
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minJumps(int* arr,int N,int* dp){
    if(N==1)
        return 0;
    if(dp[N]!=-1)
        return dp[N];

    int result=INT_MAX;
    for(int i=0;i<N-1;i++){
        if(i+arr[i]>=N-1){
            int sub_result = minJumps(arr,i+1,dp);
            if(sub_result!=INT_MAX)
                result=min(result,sub_result+1);
        }
    }
    return dp[N]=result;
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
            dp[i]=-1;
        int res = minJumps(arr,N,dp); 
        if(res!=INT_MAX)
            cout<<res<<"\n";
        else
            cout<<-1<<"\n";
    }
	return 0;
}

// Tabulation
#include <bits/stdc++.h>
using namespace std;

int minJumps(int* arr,int N,int* dp){
    if(N==1)
        return 0;
    if(dp[N]!=-1)
        return dp[N];
    int res = INT_MAX;
    for(int i=N-2;i>=0;i--){
        if(i+arr[i]>=N-1){
            int sub_res = minJumps(arr,i+1,dp);
            
            if(sub_res!=INT_MAX)
                res = min(res,sub_res+1);
        }
    }
    return dp[N]=res;
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
            dp[i]=-1;
        int res = minJumps(arr,N,dp); 
        if(res!=INT_MAX)
            cout<<res<<"\n";
        else
            cout<<-1<<"\n";
    }
	return 0;
}
