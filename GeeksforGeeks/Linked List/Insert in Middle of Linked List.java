/*
Insert in Middle of Linked List
Given a linked list of size N and a key. The task is to insert the key in the middle of the linked list.

Input:
The first line of input contains the number of test cases T. For each test case, the first line contains the length of linked list N and the next line contains N elements to be inserted into the linked list and the last line contains the element to be inserted to the middle.

Output:
For each test case, there will be a single line of output containing the element of the modified linked list.

User Task:
The task is to complete the function insertInMiddle() which takes head reference and element to be inserted as the arguments. The printing is done automatically by the driver code.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

Constraints:
1 <= T <= 100
1 <= N <= 104

Example:
Input:
2
3
1 2 4
3
4
10 20 40 50
30
Output:
1 2 3 4
10 20 30 40 50

Explanation:
Testcase 1: The new element is inserted after the current middle element in the linked list.
Testcase 2: The new element is inserted after the current middle element in the linked list and Hence, the output is 10 20 30 40 50.

#################################################################################Solution########################################################################################
*/

// Solution 1
class Solution {
    
    public Node insertInMid(Node head, int data){
        if(head == null)
            return head;
            
        int count = 1;
        Node curr = head;
        while(curr != null){
            curr = curr.next;
            count++;
        }
        
        curr = head;
        Node temp = new Node(data);
        for(int i=1;i<count/2;i++)
            curr = curr.next;
            
        temp.next = curr.next;
        curr.next = temp;
        
        return head;    
    }
}

// Solution 1
class Solution {
    
    public Node insertInMid(Node head, int data){
        if(head == null)
            return head;
            
        Node slow = head, fast = head;
        
        while(fast != null && fast.next != null && fast.next.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        
        Node temp = new Node(data);
        temp.next = slow.next;
        slow.next = temp;
        
        return head;
    }
}


