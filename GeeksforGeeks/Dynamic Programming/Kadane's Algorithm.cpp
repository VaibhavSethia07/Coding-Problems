/*
Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print the maximum sum of the contiguous sub-array in a separate line for each test case.

Constraints:
1 ≤ T ≤ 110
1 ≤ N ≤ 106
-107 ≤ A[i] <= 107

Example:
Input
2
5
1 2 3 -2 5
4
-1 -2 -3 -4
Output
9
-1

####################################################################################Solution#######################################################################################
*/

#include <iostream>
using namespace std;
int kadanesAlgo(int* arr,int N);

int main() {
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int arr[N];
        
        for(int i=0;i<N;i++)
            cin>>arr[i];
        cout<<kadanesAlgo(arr,N)<<"\n";
    }
	return 0;
}

int kadanesAlgo(int* arr,int N){
    int curr_max = arr[0];
    int global_max = arr[0];
    
    for(int i=1;i<N;i++){
        curr_max = max(curr_max+arr[i],arr[i]);
        global_max = max(global_max,curr_max);
    }
    return global_max;
}
