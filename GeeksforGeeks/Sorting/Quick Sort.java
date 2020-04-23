/*
Given an array arr[] of size N. The task is to complete partition() function which is used to implement Quick Sort.

Input:
First line of the input denotes number of test cases 'T'. First line of the test case is the size of array and second line consists of array elements.

Output:
For each testcase, in a new line, print the sorted array.

Your Task:
This is a function problem. You only need to complete the function partition(). The printing is done automatically by the driver code.

Constraints:
1 <= T <= 50
1 <= N <= 103
1 <= arr[i] <= 104

Example:
Input:
2
5
4 1 3 9 7
10
10 9 8 7 6 5 4 3 2 1
Output:
1 3 4 7 9
1 2 3 4 5 6 7 8 9 10

Explanation:
Testcase 1: Elements in sorted form are 1 3 4 7 9.
Testcase 2: Elements in sorted form are 1 2 3 4 5 6 7 8 9 10.

#####################################################Solution###########################################################################
*/

class QuickSort
{
    /* This function takes last element as pivot, places  the pivot element 
    at its correct position in sorted  array, and places all smaller (smaller
    than pivot) to left of pivot and all greater elements to right  of pivot */
    int partition (int arr[], int low, int high)
    {
       int i = (low -1);
       int pivot = arr[high];
       
       for(int j=low;j<high;j++){
           if(arr[j]<=pivot){
               i++;
               
               int temp = arr[i]; 
                arr[i] = arr[j]; 
                arr[j] = temp;
           }
       }
        int temp = arr[i+1]; 
        arr[i+1] = arr[high]; 
        arr[high] = temp;
        return (i+1);
    }

    static void swap(int a,int b){
        int temp = a;
        a = b;
        b = temp;
    }
}
