/*
Given an array A of size N containing 0s, 1s, and 2s. The task is to segregate the 0s , 1s and 2s in the array as all the 0s should appear in the first part of the array, 1s should appear in middle part of the array and finally all the 2s in the remaining part of the array.
Note: Do not use inbuilt sort function.

Input:
The first line contains an integer 'T' denoting the total number of test cases. Then T testcases follow. Each testcases contains two lines of input. The first line denotes the size of the array N. The second lines contains the elements of the array A separated by spaces.

Output: 
For each testcase, in a newline, print the sorted array.

Your Task:
This is a function problem. You only need to complete the function segragate012 that takes A and N as parameter and sorts the array.

Constraints:
1 <= T <= 500
1 <= N <= 106
0 <= Ai <= 2

Example:
Input :
2
5
0 2 1 2 0
3
0 1 0
Output:
0 0 1 2 2
0 0 1

Explanation:
Testcase 1: After segragating the 0s, 1s and 2s, we have 0 0 1 2 2 which shown in the output.
Testcase 2: For the given array input , output will be 0 0 1.

###########################################################Solution#####################################################################
*/

class Sort012
{
    public static void segragate012(int arr[], int n){
        int start=0,end = n-1;
        int index=0;
        
        if(arr.length==0 || arr.equals(null))
            return;
            
        while(index<=end && start<end){
            if(arr[index]==0){
                arr[index]=arr[start];
                arr[start]=0;
                index++;
                start++;
            }
            else if(arr[index]==2){
                arr[index] = arr[end];
                arr[end] = 2;
                end--;
            }
            else
                index++;
        }
    }
}

