/*
Given an unsorted array arr[] of size N, rotate it by D elements (counter-clockwise). 

Input: 
The first line of the input contains T denoting the number of testcases. First line of eacg test case contains two space separated elements, N denoting the size of the array and an integer D denoting the number size of the rotation. Subsequent line will be the N space separated array elements.

Output:
For each testcase, in a new line, output the rotated array.

User Task:
The task is to complete the function rotate() which rotates the array by given D elements. The newline is automatically added by the driver code.

Constraints:
1 <= T <= 200
1 <= N <= 107
1 <= D <= N
0 <= arr[i] <= 105

Example:
Input:
2
5 2
1 2 3 4 5 
10 3
2 4 6 8 10 12 14 16 18 20

Output:
3 4 5 1 2
8 10 12 14 16 18 20 2 4 6
*/

#############################################################Solution####################################################################
class RotateArray
{
    static void rotateArr(int arr[], int d, int n)
    {   RotateArray rotate=new RotateArray();
        rotate.reverse(arr,0,d-1);
        rotate.reverse(arr,d,n-1);
        rotate.reverse(arr,0,n-1);
    
    }
    
    private void reverse(int arr[],int start,int end){
        int temp=0;
        while(start<end){
            temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;
            end--;
        }
    }
}
