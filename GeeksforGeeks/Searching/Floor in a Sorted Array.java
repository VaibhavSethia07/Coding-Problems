/*
Given a sorted array arr[] of size N without duplicates, and given a value x. Find the floor of x in given array. Floor of x is defined as the largest element K in arr[] such that K is smaller than or equal to x.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of elements in the array and element whose floor is to be searched. Last line of input contains array elements.

Output:
Output the index of floor of x if exists, else print -1.

User Task:
The task is to complete the function findFloor() which finds the floor of x.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
1 ≤ arr[i] ≤ 1018
0 ≤ X ≤ arr[n-1]

Example:
Input:
3
7 0
1 2 8 10 11 12 19
7 5
1 2 8 10 11 12 19
7 10
1 2 8 10 11 12 19

Output:
-1
1
3

#############################################################Solution###################################################################
*/

class FloorSearch{
    
    static int findFloor(long arr[], int left, int right, long x)
    {
        if(left>right)
            return -1;
            
        int mid = left + (right-left)/2;
        
        if((arr[mid]==x) || ((arr[mid]<x || mid==0 )  && (mid==arr.length-1 ||(arr[mid+1]>x && mid != 0) )))
            return mid;
            
        else if(arr[mid]>x)
            return findFloor(arr,left,mid-1,x);
        else
            return findFloor(arr,mid+1,right,x);
    }
    
}
