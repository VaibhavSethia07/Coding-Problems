/*
Given an array arr[] of N positive integers. The task is to find the maximum for every adjacent pairs in the array.

Input Format:
First line of input contains number of testcases T. For each testcase, first line of input contains size of array N, and next line contains N space separated integers denoting the array elements.

Output Format:
For each testcase, print the maximum for every adjacent pairs in the array.

Constraints:
1 <= T <= 100
2 <= N <= 106
1 <= arr[i] <= 106

User Task:
The task is to complete the function maximumAdjacent(), which takes sizeOfArray and array as parameters and prints the maximum of all adjacent pairs. The drivercode automatically adds a new line.

Example:
Input:
2
6
1 2 2 3 4 5
2
5 5

Output:
2 2 3 4 5
5
*/

###########################################################Solution#####################################################################
import java.lang.StringBuffer;
class StrongestNeighbour{
    static void maximumAdjacent(int sizeOfArray, int arr[]){
        
        /*********************************
         * Your code here
         * Function should print max adjacents for all pairs
         * Use string buffer for fast output
         * ***********************************/
         StringBuffer win=new StringBuffer();
         for(int i=0;i<sizeOfArray-1;i++){
            if(arr[i]>arr[i+1])
                win.append(arr[i]+" ");
            else
                win.append(arr[i+1]+" ");
         }
         System.out.print(win); 
    }
}
