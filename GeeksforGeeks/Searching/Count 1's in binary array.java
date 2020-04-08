/*
Given a binary sorted non-increasing array arr of size N. You need to print the count of 1's in the binary array.

Input:
The input line contains T, denotes the number of testcases. Each input contains two lines. The first line contains N(size of binary array). The second line contains N elements of binary array separated by space.

Output:
For each testcase in new line, print the count 1's in binary array.

User Task:
The task is to complete the function countOne() which return count of 1s in the input array.

Constraint:
1 <= T <= 100
1 <= N <= 5*106
arr[i] = 0,1

Example:
Input:
2
8
1 1 1 1 1 0 0 0
8
1 1 0 0 0 0 0 0
Output:
5
2

#################################################################Solution###############################################################
*/

class Ones{
    
    // Object of Arrays class to access array declared
    // in Arrays class
    // To access i-th element of array, use obj.arr[i]
    static Arrays obj = new Arrays();
    
    public static int countOnes(int n){
        
       int start=0,end=n-1;
       
       while(start<=end){
           int mid = start + (end-start)/2;
           
           if(obj.arr[mid]==1 && (mid ==n-1 || obj.arr[mid+1] != 1))
                return mid+1;
            
           else if(obj.arr[mid] == 1)
                start = mid+1;
           else
                end = mid-1;
       }
       return 0;  
    }
