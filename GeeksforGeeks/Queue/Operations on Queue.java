/*
Given a queue of integers and Q queries. The task is to perform operations on queue according to the query.

Input:
First line of input contains nubmer of testcases T. For each testcase, first line of input contains Q, number of queries. Next line contains Q queries seperated by space. Queries are as:

i x : (adds element x in the queue from rear).

r : (Removes the front element of queue).

h : (Returns the front element).

f y : (check if the element y is present or not in the queue). Return "Yes" if present, else "No".

Output:
For each testcase, perform Q queries and print the output wherever required.

Your Task:
Your task is to complete functions enqueue(), dequeue(), front() and find() which performs the operations described above in the problem description.

Expected Time Complexity: O(1) for enqueue(), dequeue() and front(); O(N) for find().
Expected Auxiliary Space: O(1) for all the 4 functions. 

Constraints:
1 <= T <= 100
1 <= Q <= 103

Example:
Input:
2
6
i 2 i 4 i 3 i 5 h f 8
4
i 3 i 4 r f 3
Output:
2
No
No

####################################################################################Solution#####################################################################################
*/

class GfgQueue {
    Queue<Integer> q = new LinkedList<>();
    
    void enqueue(int x){
        q.add(x);
    }
    void dequeue(){
        q.poll();
    }
    int front(){
        if(q.isEmpty())
            return -1;
        return q.peek();
    }
    String find(int x){
        if(q.contains(x))
            return "Yes";
        return "No";
    }
}
