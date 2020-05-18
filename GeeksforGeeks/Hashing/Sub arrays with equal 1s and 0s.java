/*
Subarrays with equal 1s and 0s
Given an array arr[] of size N containing 0s and 1s only. The task is to count the subarrays having equal number of 0s and 1s.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains an Integer N denoting size of array and the second line contains N space separated 0 and 1.

Output:
For each test case, in a new line, print the count of required sub arrays in new line

Your Task:
This is a function problem. You only need to complete the function countSubarrWithEqualZeroAndOne that takes arr, and n as parameters and returns count of required subarrays.

Constraints:
1 <= T <= 100
1 <= N <= 106
0 <= A[i] <= 1

Example:
Input:
2
7
1 0 0 1 0 1 1
5
1 1 1 1 0
Output:
8
1

Explanation:
Testcase 1: The index range for the 8 sub-arrays are:
(0, 1), (2, 3), (0, 3), (3, 4), (4, 5)
(2, 5), (0, 5), (1, 6)
Testcase 2: The index range for the subarray is (3,4).

################################################################Solution################################################################
*/

class countsubArray
{
    static int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        HashMap<Integer,Integer>hm = new HashMap<>();
        
        int prefixSum = 0;
        int count = 0;
        
        hm.put(0,0);
        for(int i=0;i<n;i++){
            int virtual =(arr[i] == 0?-1:1);
            prefixSum += virtual;
            
            if(!hm.containsKey(prefixSum))
                hm.put(prefixSum,0);
            else{
                int val = hm.get(prefixSum)+1;
                count += val;
                hm.put(prefixSum,val);
            }
        }
        
        return count;
    }
}
