/*
Given an unsorted array arr[] of N integers and a sum. The task is to count the number of subarray which adds to a given number.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer N denoting the size of the array. The next line contains N space separated integers forming the array. The last line contains an integer denoting the value of the sum.

Output:
For each testcase, in a new line, print the count of the subarray which adds to the given sum.

Your Task:
This is a function problem. You only need to complete the function subArraySum() that takes arr, n, sum as parameters and returns the count.

Constraints:
1 <= T <= 200
1 <= N <= 105
-105 <= arr[i] <= 105
-105 <= sum <= 105

Example:
Input:
2
5
10 2 -2 -20 10
-10
6
1 4 20 3 10 5
33
Output:
3
1

##################################################################Solution##############################################################
*/

class sumRange
{
    static int subArraySum(int arr[], int n, int sum)
    {
        HashMap<Integer,Integer> hm = new HashMap<>();
        
        int prefixSum = 0;
        int count = 0;
        hm.put(0,1);
        
        for(int i=0;i<n;i++){
            prefixSum += arr[i];
            
             if(hm.containsKey(prefixSum-sum)){
                int value = hm.get(prefixSum-sum);
                count += value;
            }
            
            if(!hm.containsKey(prefixSum))
                hm.put(prefixSum,1);
            else{
                int value = hm.get(prefixSum)+1;
                hm.put(prefixSum,value);
            }
        }
        
        return count;
    }
}
