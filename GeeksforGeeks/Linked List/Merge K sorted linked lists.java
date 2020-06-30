/*
Merge K sorted linked lists
Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of linked lists N and next line contains data of nodes of all K linked lists, with first element as M, the length of linked list and next M elements for the same linked list.

Output:
For each testcase, in a new line, print the merged linked list.

Your Task:
The task is to complete the function mergeKList() which merges the K given lists into a sorted one. The printing is done automatically by the driver code.

Expected Time Complexity: O(nk Logk)
Expected Auxiliary Space: O(k)

Constraints
1 <= T <= 50
1 <= N <= 103

Example:
Input:
2
4
3 1 2 3 2 4 5 2 5 6 2 7 8
3
2 1 3 3 4 5 6 1 8
Output:
1 2 3 4 5 5 6 7 8
1 3 4 5 6 8

Explanation :
Testcase 1: The test case has 4 sorted linked list of size 3, 2, 2, 2
1st    list     1 -> 2-> 3
2nd   list      4->5
3rd    list      5->6
4th    list      7->8
The merged list will be 1->2->3->4->5->5->6->7->8.
Testcase 2: The test case has 3 sorted linked list of size 2, 3, 1.
1st list 1 -> 3
2nd list 4 -> 5 -> 6
3rd list 8
The merged list will be 1->3->4->5->6->8.

####################################################################################Solution#####################################################################################
*/

class Merge
{
    Node mergeKList(Node[]a,int N)
    {
        return mergeK(a,a[0],null,0,N);
    }
    
    static Node mergeK(Node a[],Node A,Node B,int i,int N){
        
        Node curr = merge2(A,B);
        if(i==N-1)
            return curr;
            
        return mergeK(a,curr,a[i+1],i+1,N);
    }
    
    static Node merge2(Node A,Node B){
        if(A == null)
            return B;
        if(B == null)
            return A;
            
        Node head = null;
        Node tail = null;
        
        if(A.data <= B.data){
            head = A;
            tail = A;
            A = A.next;
        }
        else{
            head = B;
            tail = B;
            B = B.next;
        }
        
        while(A != null && B != null){
            if(A.data <= B.data){
                tail.next = A;
                tail = A;
                A = A.next;
            }
            else{
                tail.next = B;
                tail = B;
                B = B.next;
            }
        }
        
        if(A == null)
            tail.next = B;
        if(B == null)
            tail.next = A;
            
        return head;
    }
}
