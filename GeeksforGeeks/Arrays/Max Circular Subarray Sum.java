/*
Given an array arr[] of N integers arranged in a circular fashion. Your task is to find the maximum contigious subarray sum.

Input:
First line of input contains a single integer T which denotes the number of test cases. First line of each test case contains a single integer N which denotes the total number of elements. Second line of each test case contains N space separated integers denoting the elements of the array.

Output:
For each test case print the maximum sum obtained by adding the consecutive elements.

User Task:
The task is to complete the function circularSubarraySum() which finds the circular subarray with maximum sum.

Constraints:
1 <= T <= 101
1 <= N <= 106
-106 <= Arr[i] <= 106

Example:
Input:
3
7
8 -8 9 -9 10 -11 12
8
10 -3 -4 7 6 5 -4 -1
8
-1 40 -14 7 6 5 -4 -1

Output:
22
23
52

Explanation:
Testcase 1: Starting from last element of the array, i.e, 12, and moving in circular fashion, we have max subarray as 12, 8, -8, 9, -9, 10, which gives maximum sum as 22.
*/

//##########################################################Solution######################################################################
//Solution 1(Naive Method)
class Kadane{
  static int circularSubarraySumNaive(int a[], int n) {
        int res=Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            int max_current=a[i];
            int global_current=a[i];
            
            for(int j=1;j<n;j++){
                int index=(i+j)%n;
                max_current=Math.max(a[index],max_current+a[index]);
                global_current=Math.max(max_current,global_current);
            }
            res=Math.max(res,global_current);
        }
        return res;
    }
 //Solution 2(Efficient Method)
    static int circularSubarraySumEfficient(int a[],int n){
        int normalKadane=kadane(a,n);
       
        if(normalKadane<0)
            return normalKadane;
         int sum=0;   
        for(int i=0;i<n;i++){
            sum+=a[i];
            a[i]=-a[i];
        }
        int circularKadane=kadane(a,n);
        return Math.max(normalKadane,sum+circularKadane);
    }
    
    static int kadane(int a[],int n){
        int max_current=a[0];
        int global_current=a[0];
        
        for(int i=1;i<n;i++){
            max_current=Math.max(a[i],a[i]+max_current);
            global_current=Math.max(max_current,global_current);
        }
        return global_current;
    }
}
