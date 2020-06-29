/*
Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of nodes in the linked list and next line contains N elements of the linked list.

Output:
For each test, in a new line, print the sorted linked list.

Your Task:
For C++ and Python: The task is to complete the function mergeSort() which sort the linked list using merge sort function.
For Java: The task is to complete the function mergeSort() and return the node which can be used to print the sorted linked list.

Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(1)

Constraints:
1 <= T <= 100
1 <= N <= 105

Note: Try to solve the problem in constant space.

Example:

Input:
2
5
3 5 2 4 1
3
9 15 0
Output:
1 2 3 4 5
0 9 15

Explanation:
Testcase 1: After sorting the given linked list, the resultant matrix will be 1->2->3->4->5.
Testcase 2: After sorting the given linked list , resultant will be 0->9->15.

###############################################################################Solution##########################################################################################
*/

class LinkedList
{
    static Node mergeSort(Node head)
    {
        if(head == null || head.next == null)
            return head;
        
        Node slow = head;    
        Node fast = head;
        Node beforeMid = head;
        while(fast != null && fast.next != null){
            beforeMid = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        Node mid = slow;
        beforeMid.next = null;
        
        Node left = mergeSort(head);
        Node right = mergeSort(mid);
        
        return sortedList(left,right);
    }
    
    static Node sortedList(Node a,Node b){
        if(a == null)
            return b;
        if(b == null)
            return a;
        Node head = null;
        Node tail = null;
        
        if(a.data <= b.data){
            head = a;
            tail = a;
            a = a.next;
        }
        else{
            head = b;
            tail = b;
            b = b.next;
        }
        
        while(a != null && b != null){
            if(a.data<=b.data){
                tail.next = a;
                tail = a;
                a = a.next;
            }
            else{
                tail.next = b;
                tail = b;
                b = b.next;
            }
        }
        
        if(a != null){
           tail.next = a;
           tail = a;
        }
        if(b != null){
           tail.next = b;
           tail = b;
        }
            
        return head;
    }
}
