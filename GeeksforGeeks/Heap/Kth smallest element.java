/*
Given an array arr[] of N positive integers and a number K. The task is to find the kth smallest element in the array.

Input:
First line of input contains number of testcases. For each testcase, there will be a single line of input containing number of elements in the array and K. Next line contains N elements.

Output:
For each testcase, there will be a single line of output containing the kth smallest element in the array.

Your Task:
You are required to complete the method kthSmallest() which takes 3 arguments and returns kth smallest element.

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
7

Explanation:
Testcase 1: Third smallest element in the array is 4.
Testcase 2: Fifth smallest element in the array is 7.

################################################################################Solution#########################################################################################
*/

// Naive Solution
class solve{
    public static int kthSmallest(int arr[], int n, int k){
        if(n<k)
            return -1;
            
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        
        for(int i=0;i<n;i++)
            minHeap.add(arr[i]);
            
        while(--k>0)
            minHeap.poll();
            
        return minHeap.peek();
    }
}

// Efficient Solution
class solve{
    public static int kthSmallest(int arr[], int n, int k){
        if(n<k)
            return -1;
            
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        
        for(int i=0;i<k;i++)
            maxHeap.add(arr[i]);
            
        for(int i=k;i<n;i++)
            if(arr[i]<maxHeap.peek()){
                maxHeap.poll();
                maxHeap.add(arr[i]);
            }
            
        return maxHeap.peek();
    }
}
