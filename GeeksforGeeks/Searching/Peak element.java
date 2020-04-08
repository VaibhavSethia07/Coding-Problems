/*
Given an array A of N integers. The task is to find a peak element in it in O( log N ) .
An array element is peak if it is not smaller than its neighbours. For corner elements, we need to consider only one neighbour.
Note: There may be multiple peak element possible, in that case you may return any valid index.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer N. Then in the next line are N space separated values of the array.

Output:
For each test case output will be 1 if the index returned by the function is an index with peak element.

User Task:
You don't have to take any input. Just complete the provided function peakElement() and return the valid index.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= A[] <= 106

Example:
Input:
2
3
1 2 3
2
3 4
Output:
1
1

Explanation:
Testcase 1: In the given array, 3 is the peak element as it is greater than its neighbour.
Testcase 2: 4 is the peak element as it is greater than its neighbour elements.

################################################################Solution################################################################
*/

class Peak
{
	public int peakElement(int[] arr,int n)
    {
       int start = 0;
       int end = n-1;
       
       while(start<=end){
           int mid = start + (end-start)/2;
           
           if((mid==0 || arr[mid]>=arr[mid-1]) && (mid==n-1 || arr[mid]>=arr[mid+1])){
               return mid;
           }
           
           else if(mid>0 && arr[mid]<arr[mid-1]){
               end = mid-1;
           }
           else
                start = mid+1;
       }
       return -1;
    }
}
