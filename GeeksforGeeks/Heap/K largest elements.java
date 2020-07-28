/*
Given an array of N positive integers, print k largest elements from the array. 

Input:
First line of input contains number of testcases T. For each testcase, there will be two lines, first of which will contain the integers N and K. Second line will contain the elements of the array.

Output:
Print the k largest element in descending order.

Your Task:
Complete the function kLargest() that takes the array, N and K as input parameters and returns a list of k largest element in descending order. 

Expected Time Complexity: O(N log K)
Expected Auxiliary Space: O(K)

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 104
K ≤ N
1 ≤ array[i] ≤ 105

Example:
Sample Input:
2
5 2
12 5 787 1 23
7 3
1 23 12 9 30 2 50

Sample Output:
787 23
50 30 23

Explanation:
Testcase 1: First largest element in the array is 787 and the second largest is 23.
Testcase 2: Three Largest element in the array are 50, 30 and 23.

################################################################################Solution#########################################################################################
*/

// Naive Solution
class Solution
{
    public static ArrayList<Integer> kLargest(int arr[], int n, int k)
    {
        ArrayList<Integer> res = new ArrayList<>();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        
        for(int i=0;i<n;i++)
            maxHeap.add(arr[i]);
            
        for(int i=0;i<k;i++)
            res.add(maxHeap.poll());
            
        return res;
    }
}

// Efficient Solution
class Solution
{
    public static ArrayList<Integer> kLargest(int arr[], int n, int k)
    {
        ArrayList<Integer> res = new ArrayList<>();
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        
        for(int i=0;i<k;i++)
            minHeap.add(arr[i]);
            
        for(int i=k;i<n;i++)
            if(arr[i]>minHeap.peek()){
                minHeap.poll();
                minHeap.add(arr[i]);
            }
            
        while(!minHeap.isEmpty())
            res.add(minHeap.poll());
            
        Collections.reverse(res);
        
        return res;
    }
}
