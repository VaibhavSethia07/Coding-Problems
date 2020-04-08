/*
Given a sorted array arr of N positive integers (elements may be repeated) and a number x. The task is to find the leftmost index of x in the array arr.

Input:
First line of input contains number of testcases T. For each testcase, first line contains number of elements N, and next line contains N elements. Last line contains x.

Output:
For each testcase, print the leftmost index at which x is present in the array. If the element is not present in the array, then output "-1" (without quotes).
Note: Avoid O(N) approach, try to solve in O(log N) time complexity.

User Task:
The task is to complete the function leftIndex() which finds leftmost occurrence of x in given input array. Return -1, if element is not present in the array.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= arr[i] <= 106
1 <= x <= 106

Example:
Input:
2
10
1 1 2 2 3 4 5 5 6 7
1
7
10 20 20 20 20 20 20
20

Output:
0
1

################################################################Solution################################################################
*/

class LeftIndex{ 
    static int leftIndex(int sizeOfArray, int arr[], int elementToSearch)
    {
       
       int start=0;
       int end=sizeOfArray-1;
       
       while(start<=end){
           int mid = start + (end-start)/2;
           
           if(arr[mid] == elementToSearch && (mid==0 || arr[mid-1]!=elementToSearch))
                return mid;
                
           else if(arr[mid]>=elementToSearch)
                end=mid-1;
           else
                start=mid+1;
       }
       
       return -1;
    }
}
