/*
Given a Queue Q containing N elements. The task is to reverse the Queue. Your task is to complete the function rev(), that reverses the N elements of the queue.

Input: 
The first line of input contains an integer T denoting the Test cases. Then T test cases follow. The first line contains N which is the number of elements which will be reversed. Second line contains N space seperated elements.

Output:
For each testcase, in a new line, print the reversed queue.

Your Task:
This is a function problem. You only need to complete the function rev that takes a queue as parameter and returns the reversed queue. The printing is done automatically by the driver code.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(n)

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 105
1 ≤ elements of Queue ≤ 105

Example:
Input : 
2
6
4 3 1 10 2 6
4
4 3 2 1 
Output : 
6 2 10 1 3 4
1 2 3 4

Explanation :
Testcase 1: After reversing the given elements of the queue , the resultant queue will be 6 2 10 1 3 4.
Testcase 2: After reversing the given elements of the queue , the resultant queue will be 1 2 3 4.

#################################################################################Solution########################################################################################
*/

// Solution 1
class GfG{
    public Queue<Integer> rev(Queue<Integer> q){
        Stack<Integer> st = new Stack<>();
        
        while(!q.isEmpty())
            st.push(q.poll());
        
        while(!st.isEmpty())
            q.add(st.pop());
        
        return q;
    }
}

// Solution 2
class GfG{
    public Queue<Integer> rev(Queue<Integer> q){
        if(q.isEmpty())
            return q;
        int x = q.poll();
        q = rev(q);
        q.add(x);
        return q;
    }
}
