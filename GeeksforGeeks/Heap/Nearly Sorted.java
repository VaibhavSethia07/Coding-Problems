/*
Given an array of n elements, where each element is at most k away from its target position, you need to sort the array optimally.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains two lines of input. The first line contains two elements n and k separated by a space. The second line contains n elements of array.

Output:
For each testcase, in a new line, print the sorted array.

Note: DO NOT use STL sort() function for this question.

Your Task:
You are required to complete the method nearlySorted() which takes 3 arguments and returns the sorted array.

Expected Time Complexity : O(nlogn)
Expected Auxilliary Space : O(n)

Constraints:
1 <= T <= 50
1 <= n <= 106
1 <= k <= n
1 <= arri <= 107

Examples:
Input:
2
7 3
6 5 3 2 8 10 9
5 2
4 3 1 2 5
Output:
2 3 5 6 8 9 10
1 2 3 4 5

#################################################################################Solution########################################################################################
*/

class solve{

    ArrayList <Integer> nearlySorted(int arr[], int num, int k){
        ArrayList<Integer> res = new ArrayList<>();
        
        Queue<Integer> minHeap = new PriorityQueue<>(); 
        
        for(int i=0;i<k+1;i++){
            if(i==num)
                continue;
            minHeap.add(arr[i]);
        }
            
        for(int i=k+1;i<num;i++){
            res.add(minHeap.poll());
            minHeap.add(arr[i]);
        }
        
        while(!minHeap.isEmpty())  
            res.add(minHeap.poll());
            
        return res;
    }
}
