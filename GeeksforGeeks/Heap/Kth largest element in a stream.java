/*
Kth largest element in a stream
Given an input stream of n integers, find the kth largest element for each element in the stream.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two lines. The first line of each test case contains two space separated integers k and n . Then in the next line are n space separated values of the array.

Output:
For each test case, in a new line, print the space separated values denoting the kth largest element at each insertion, if the kth largest element at a particular insertion in the stream doesn't exist print -1.

Your Task:
You are required to complete the method kthLargest() which takes 3 arguments and prints kth largest element or -1.

Constraints:
1 <= T <= 100
1 <= n <= 106
1 <= K <= n
1 <= stream[i] <= 105

Expected Time Complexity : O(NlogK)
Expected Auxilliary Space : O(K)

Example:
Input:
2
4 6
1 2 3 4 5 6
1 2
3 4

Output:
-1 -1 -1 1 2 3
3 4 

Explanation:
Testcase1:
k = 4
For 1, the 4th largest element doesn't exist so we print -1.
For 2, the 4th largest element doesn't exist so we print -1.
For 3, the 4th largest element doesn't exist so we print -1.
For 4, the 4th largest element is 1 {1, 2, 3, 4}
For 5, the 4th largest element is 2 {2, 3, 4 ,5}
For 6, the 4th largest element is 3 {3, 4, 5, 6}

##########################################################################Solution###############################################################################################
*/

class solve{
    public void kthLargest(int arr[], int n, int k){
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        
        for(int i=0;i<k;i++){
            minHeap.add(arr[i]);
            if(i!=k-1)
                System.out.print(-1+" ");
            else
                System.out.print(minHeap.peek()+" ");
        }
        
        for(int i=k;i<n;i++){
            if(arr[i]>=minHeap.peek()){
                minHeap.poll();
                minHeap.add(arr[i]);
            }
            System.out.print(minHeap.peek()+" ");
        }
    }
}
