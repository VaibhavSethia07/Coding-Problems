/*
Given an array arr[] of size N of positive integers which may have duplicates. The task is to find maximum and second maximum from the array, and both of them should be distinct, so If no second max exists, then second max will be -1.

Input Format:
First line of input contains number of testcases T. For each testcase, first line of input contains size of array N, next line contains array elements.

Output Format:
For each testcase, print the maximum and second maximum from the array. IF no second max exists, print "-1" for second max.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= arr[i] <= 106

User Task:
The task is to complete the function largestAndSecondLargest(), which should print maximum and second maximum element from the array.

Example:
Input:
3
5
1 2 3 4 5
3
2 1 2
2
5 5

Output:
5 4
2 1
5 -1
*/

##############################################################Solution##################################################################
class ArrayMax{
    
    // Function to find largest and second largest element in the array
    static void largestAndSecondLargest(int sizeOfArray, int arr[]){
        
        int max = -1;
        int max2 = -1;
        int temp=0;
        for(int i=0;i<sizeOfArray;i++){
            int tempMax=max;
            max=Math.max(max,arr[i]);
            temp=Math.min(tempMax,arr[i]);
            
             if(max==temp )
                temp=Math.min(max2,arr[i]);
            max2=Math.max(temp,max2);
           
        }
        if(max==max2)
            max2=-1;
        System.out.println(max + " " + max2);
    }
}
