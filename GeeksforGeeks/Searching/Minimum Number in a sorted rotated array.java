/*
Given an array A  which is sorted and contains N distinct elements. Also, this array is rotated at some unknown point. The task is to find the minimum element in it. 
Note: Expected time complexity is O(logN).

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains the number of elements in the array arr[] as N and next line contains space separated n elements in the array arr[].

Output:
Print an integer which denotes the minimum element in the array.

User Task:
The task is to complete the function minNumber() which finds the minimum in sorted and rotated array.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= arr[i] <= 107

Example:
Input:
3
10
2 3 4 5 6 7 8 9 10 1
5
3 4 5 1 2
8
10 20 30 45 50 60 4 6
Output:
1
1
4
*/
//Solution 1
class MinimumNumber{
    
    static long minNumber(int arr[], long low, long high)
    {
        if(low ==high )
            return arr[(int)low];

        long mid = low + (high-low)/2;
            
        if(arr[(int)mid]>arr[(int)high])
            return minNumber(arr,mid+1,high);
        else
            return minNumber(arr,low,mid);
        
    } 
}

