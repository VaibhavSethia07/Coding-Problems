/*
Given an array A[] of N numbers and another number x. The task is to determine whether or not there exist three elements in A[] whose sum is exactly x.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains n and x. Next line contains array elements.

Output:
Print "1" (without quotes) if there exist three elements in A whose sum is exactly x, else "0" (without quotes).

Your Task:
This is a function problem. You only need to complete the function find3Numbers() that takes A, arr_size, and sum as parameters and returns true or false.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 103
1 ≤ A[i] ≤ 105

Example:
Input:
2
6 13
1 4 45 6 10 8
5 10
1 2 4 3 6
Output:
1
1

Explanation:
Testcase 1: There is one triplet with sum 13 in the array. Triplet elements are 1, 4, 8, whose sum is 13.
Testcase 2: There is one triplet with sum 10 in the array. Triplet elements are 1 , 3 , 10.

##############################################################Solution##################################################################
*/

class TripletSum
{
    // function to find the triplet which sum to x
    public static int find3Numbers(int arr[], int n, int x) { 
        Arrays.sort(arr);
        // System.out.println(Arrays.toString(arr));
        int upperEnd=upperBound(arr,0,n-1,n,x);
        
        if(upperEnd==-1)
            return 0;
        // System.out.println(Arrays.toString(arr));
        for(int index=upperEnd;index>=2;index--){
            int c= arr[index];
            int start=0;
            int end=index-1;
            while(start<end){
                if(arr[start]+arr[end]==x-c){
                    // System.out.println(arr[start]+" "+arr[end]+" "+c);
                    return 1;
                }
                else if(arr[start]+arr[end]>x-c)
                    end--;
                else
                    start++;
            }
        }
        return 0;
    }
    
    private static int upperBound(int arr[],int start,int end,int n,int x){
        if(start>end)
            return -1;
        
        int mid = start + (end-start)/2;
        if(arr[mid]<x &&(mid==end || (mid<n && arr[mid+1]>=x))){
            // System.out.println(mid);
            return mid;
        }
        else if(arr[mid]>=x)
            return upperBound(arr,start,mid-1,n,x);
        else
            return upperBound(arr,mid+1,end,n,x);
    }
}
