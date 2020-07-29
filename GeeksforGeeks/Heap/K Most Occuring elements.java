/*
Given an array arr[] of N integers in which elements may be repeating several times. Also, a positive number K is given and the task is to find sum of total frequencies of K most occurring elements

Note: The value of K is guaranteed to be less than or equal to the number of distinct elements in arr.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains the size of array N, and next line contains N positive integers. The last line contains K.

Output:
For each testcase, print the sum of total frequencies of K most occurring elements in the given array.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= K <= N
1 <= arr[i] <= 106

Expected Time Complexity : O(N)

Example:
Input:
2
8
3 1 4 4 5 2 6 1
2
8
3 3 3 4 1 1 6 1
2

Output:
4
6

Explanation:
Testcase 1: Since, 4 and 1 are 2 most occurring elements in the array with their frequencies as 2, 2. So total frequency is 2 + 2 = 4.

Testcase 2: Since, 3 and 1 are most occurring elements in the array with frequencies 3, 3 respectively. So, total frequency is 6.

###################################################################################Solution######################################################################################
*/

class solve{
    void kMostOccuring(int arr[], int n, int k){
        HashMap<Integer,Integer> hm = new HashMap<>();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        
        for(int i=0;i<n;i++){
            if(hm.containsKey(arr[i]))
                hm.put(arr[i],hm.get(arr[i])+1);
            else
                hm.put(arr[i],1);
        }
        
        Iterator<Map.Entry<Integer,Integer>> itr = hm.entrySet().iterator();
        while(itr.hasNext()){
            Map.Entry<Integer,Integer> entry = itr.next();
            maxHeap.add(entry.getValue());
        }
        int cnt = 0;
        while(k-->0)
            cnt+=maxHeap.poll();
            
        System.out.println(cnt);
    }
}
