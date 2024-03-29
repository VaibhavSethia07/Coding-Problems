/*
Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Input:
First line consists of T test cases. First line of every test case consists of 2 integers, N and K, denoting number of elements and number of elements to be reversed respectively. Second line of every test case consists of elements of array.

Output:
For each testcase, in a new line, print the modified queue.

Your Task:
Since this is a function problem, you don't need to take inputs. Just complete the provided function modifyQueue that takes queue and k as parameters and returns a modified queue. The printing is done automatically by the driver code.

Expected TIme Complexity : O(n)
Expected Auxilliary Space : O(n)

Constraints:
1 <= T <= 100
1 <= N <= 1000
1 <= K <= N

Example:
Input:
2
5 3
1 2 3 4 5
4 4
4 3 2 1
Output:
3 2 1 4 5
1 2 3 4

Explanation:
Testcase 1: After reversing the given input from the 3rd position the resultant output will be 3 2 1 4 5.
Testcase 2: After reversing the given input from the 4th position the resultant output will be 1 2 3 4.

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.

#########################################################################Solution################################################################################################
*/

class GfG
{
    public Queue<Integer> modifyQueue(Queue<Integer> q, int k)
    {
        Queue<Integer> auxQueue = new LinkedList<>();
        Stack<Integer> st = new Stack<>();
        
        while(k-->0)
            st.push(q.poll());
            
        while(!st.isEmpty())
            auxQueue.add(st.pop());
        
        while(!q.isEmpty())
            auxQueue.add(q.poll());
        
        return auxQueue;
    }
}
