/*
You are given an array arr[] whose size is denoted by sizeOfArr. You need to reverse the elements of the array.

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains two lines of input. The first line contains the sizeOfArray. The second line contains the elements of array.

Output Format:
For each testcase, in a new line, print the reversed array.

Your Task:
This is a function problem. You don't have to take any input. Just complete the function arrayReversal() that takes array and size as parameters and reverses the array. The reversed array will be printed by the driver code.

Constraints:
1 <= T <= 100
1 <= sizeOfArray <= 107
1 <= arri <= 107

Examples:
Input:
1
6
1 2 3 4 5 6

Output:
6 5 4 3 2 1
*/

#######################################################Solution#########################################################################
class Reverse
{
    public static void arrayReversal(int arr[],int sizeOfArray) 
    { 
       int start=0,end=sizeOfArray-1,temp=0;
       
       while(start<end){
           temp=arr[start];
           arr[start]=arr[end];
           arr[end]=temp;
           start++;
           end--;
       }
    }
}
