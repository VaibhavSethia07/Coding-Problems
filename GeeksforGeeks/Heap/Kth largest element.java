/*
Given an array arr[] of N positive integers and a number K. The task is to find the kth largest element in the array.

Input Format:
First line of input contains number of testcases. For each testcase, there will be a single line of input containing number of elements in the array and K. Next line contains N elements.

Output Format:
For each testcase, there will be a single line of output containing the kth largest element in the array.

Your Task:
You are required to complete the method KthLargest() which takes 3 arguments and returns the Kth Largest element.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= arr[i] <= 106
1 <= K <= N

Expected Time Complexity : O(NlogK)
Expected Auxilliary Space : O(K)

Example:
Input:
2
5 3
3 5 4 2 9
5 5
4 3 7 6 5

Output:
4
3

Explanation:
Testcase 1: Third largest element in the array is 4.
Testcase 2: Fifth largest element in the array is 3.

####################################################################################Solution#####################################################################################
*/

// Naive Solution
class solve {
    public static int KthLargest(int arr[], int n, int k) {
        if(k>n)
            return -1;
        
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        
        for(int i=0;i<n;i++)
            maxHeap.add(arr[i]);
            
        while(--k>0)
            maxHeap.poll();
            
        return maxHeap.poll();
    }
}

// Efficient Solution
class solve {
    public static int KthLargest(int arr[], int n, int k) {
        if(n<k)
            return -1;
            
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        
        for(int i=0;i<k;i++)
            minHeap.add(arr[i]);
            
        for(int i=k;i<n;i++)
            if(arr[i]>minHeap.peek()){
                minHeap.poll();
                minHeap.add(arr[i]);
            }
            
        return minHeap.peek();
    }
}
