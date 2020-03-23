/*
Given an array arr[] of N distinct integers, check if this array is Sorted (non-increasing or non-decreasing) and Rotated counter-clockwise. Note that input array may be sorted in either increasing or decreasing order, then rotated.
A sorted array is not considered as sorted and rotated, i.e., there should be at least one rotation.

Input:
The first line of input contains number of testcases T. Each testcase contains 2 lines, the first line contains N, the number of elements in array, and second line contains N space separated elements of array.

Output:
Print "Yes" if the given array is sorted and rotated, else Print "No", without Inverted commas.

User Task:
The task is to complete the function checkRotatedAndSorted() which checks if an array is sorted and rotated clockwise.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= A[i] <= 106

Example:
Input:5
4
3 4 1 2
3
1 2 3
4
10 20 30 14
5
30 20 10 50 35
5
30 20 10 50 25

Output:
Yes
No
No
Yes
No

Explanation:
Testcase 1: The array is sorted (1, 2, 3, 4) and rotated twice (3, 4, 1, 2).
Testcase 2: The array is sorted (1, 2, 3) is not rotated.
Testcase 3: The array is sorted (10, 20, 30, 14) is not sorted and rotated as 14 is greater than 10.

#############################################################Solution###################################################################
*/
bool checkRotatedAndSorted(int arr[], int num){
    
    int start=0,end=num-1;
    int d=0,cnt=0;
    if(arr[start]>arr[end]){
        for(int i=start;i<end;i++){
            if(arr[i]>arr[i+1]){
                d=i+1;
                cnt++;
            }
        }
    }
    else{
        for(int i=start;i<end;i++){
            if(arr[i]<arr[i+1]){
                d=i;
                cnt++;
            }
        }
    }
    
    if(cnt==1)
        return true;
    return false;
}
