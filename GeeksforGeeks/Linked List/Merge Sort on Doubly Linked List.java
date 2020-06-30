/*
Merge Sort on Doubly Linked List
Given Pointer/Reference to the head of a doubly linked list of N nodes, the task is to Sort the given doubly linked list using Merge Sort in both non-decreasing and non-increasing order.

Input:
There are be multiple test cases, for each test case function mergeSort() will be called separately. The only input to the function is the pointer/reference to the head of the doubly linked list.

Output:
For each test, print the sorted doubly linked list in both order i.e. in non-decreasing and non-increasing order.

Your Task:
The task is to complete the function sortDoubly() which sorts the doubly linked list. The printing is done automatically by the driver code.

Constraints:
1 <= T <= 100
1 <= N <= 105

Example:
Input:
2
8
7 3 5 2 6 4 1 8
5
9 15 0 -1 0
Output:
1 2 3 4 5 6 7 8
8 7 6 5 4 3 2 1
-1 0 0 9 15
15 9 0 0 -1

Explanation:
Testcase 1: After sorting the given linked list in both ways, resultant matrix will be as given in the first two line of output, where first line is the output for non-decreasing order and next line is for non-increasing order.
Testcase 2: After sorting the given linked list in both ways, the resultant list will be -1 0 0 9 15 in non-decreasing order and 15 9 0 0 -1 in non-increasing order.

####################################################################################Solution#####################################################################################
*/
// Solution 1
class LinkedList
{
    static Node sortDoubly(Node head)
    {
        if(head == null || head.next == null)
            return head;
            
        Node slow = head;
        Node fast = head;
        
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        
        Node mid = slow;
        Node beforeMid = slow.prev;
        beforeMid.next = null;
        mid.prev = null;
        
        Node left = sortDoubly(head);
        Node right = sortDoubly(mid);
        
        return mergeDoubly(left,right);
    }
    
    static Node mergeDoubly(Node a,Node b){
        if(a == null)
            return b;
        if(b == null)
            return a;
            
        Node head = null;
        Node tail = null;
        Node temp = null;
        
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
            if(a.data <= b.data){
                tail.next = a;
                temp = tail;
                tail = a;
                tail.prev = temp;
                a = a.next;
            }
            else{
                tail.next = b;
                temp = tail;
                tail = b;
                tail.prev = temp;
                b = b.next;
            }
        }
        
        if(a == null){
             tail.next = b;
             temp = tail;
             tail = b;
             tail.prev = temp;
        }
        if(b == null){
             tail.next = a;
             temp = tail;
             tail = a;
             tail.prev = temp;
        }
            
        return head;
    }
}

// Solution 2
class LinkedList
{
    static Node sortDoubly(Node head)
    {
        if(head == null || head.next == null)
            return head;
            
        Node slow = head;
        Node fast = head;
        
        while(fast != null && fast.next != null)
            fast = fast.next;
            
        while((slow != fast) && (slow.next != fast)){
            slow = slow.next;
            fast = fast.prev;
        }
        
        Node mid = fast;
        Node beforeMid = fast.prev;
        
        beforeMid.next = null;
        mid.prev = null;
        
        Node left = sortDoubly(head);
        Node right = sortDoubly(mid);
        
        return mergeDoubly(left,right);
    }
    
    static Node mergeDoubly(Node a,Node b){
        if(a == null)
            return b;
        if(b == null)
            return a;
            
        Node head = null;
        Node tail = null;
        Node temp = null;
        
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
            if(a.data <= b.data){
                tail.next = a;
                temp = tail;
                tail = a;
                tail.prev = temp;
                a = a.next;
            }
            else{
                tail.next = b;
                temp = tail;
                tail = b;
                tail.prev = temp;
                b = b.next;
            }
        }
        
        if(a == null){
             tail.next = b;
             temp = tail;
             tail = b;
             tail.prev = temp;
        }
        if(b == null){
             tail.next = a;
             temp = tail;
             tail = a;
             tail.prev = temp;
        }
            
        return head;
    }
}
