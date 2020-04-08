/*
Given an integer array Arr[] and an element x. The task is to find if the given element is present in array or not.

Input:
First line contains an integer, the number of test cases 'T'. For each test case, first line contains an integer 'N', size of array. The second line contains the elements of the array separated by spaces. Third line contains element to be find in the array.

Output:
For each testcase, output a single line containing first index of element to be found in array. If element is not in the array, then print "-1" (without quotes).

User Task:
The task is to complete the function search() which searched for the given element in the array.

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= Arr[i] <= 100

Example:
Input:
2
4
1 2 3 4
3
5
1 2 3 4 5
5
Output:
2
4

##########################################################Solution######################################################################
*/

class Searching{
  static int search(int arr[], int n, int x)
    {
        
        for(int i=0;i<n;i++)
            if(arr[i]==x)
                return i;
        return -1;
        
    }
    
}
