/*
Given a sorted array arr[] of N integers and a number K is given. The task is to check if the element K is present in the array or not.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of elements in the array and the number K seperated by space. Next line contains N elements.

Output:
For each testcase, if the element is present in the array print "1" (without quotes), else print "-1" (without quotes).

User Task:
The task is to complete the function searchInSorted() which searches for an element in sorted array.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= K <= 106
1 <= arr[i] <= 106

Example:
Input:
2
5 6
1 2 3 4 6
5 2
1 3 4 5 6

Output:
1
-1

#################################################################Solution###############################################################
*/

class SearchElement {
  static int searchInSorted(int arr[], int n, int x)
    {
        return binarySearch(arr,0,n-1,x);
    }
    
    public static int binarySearch(int arr[],int start,int end,int x){
        if(start>end)
            return -1;
        
        int mid = start + (end-start)/2;
        
        if(arr[mid]==x)
            return 1;
        if(arr[mid]>x)
            return binarySearch(arr,start,mid-1,x);
            
        return binarySearch(arr,mid+1,end,x);
        
    }
}
