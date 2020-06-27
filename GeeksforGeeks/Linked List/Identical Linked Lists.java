/*
Identical Linked Lists
Given two Singly Linked List of N and M nodes respectively. The task is to check whether two linked lists are identical or not. 
Two Linked Lists are identical when they have same data and with same arrangement too.

Input:
The first line of input contains the number of test cases T. For each test case, the first line of input contains the length of linked lists N and M and the next line contains elements of the linked lists.

Output:
For each test, the output will be 'Identical' if two lists are identical else 'Not identical'.

User Task:
The task is to complete the function areIdentical() which takes the head of both linked lists as arguments and returns True or False.

Constraints:
1 <= T <= 100
1 <= N <= 103

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

Example:
Input:
2
6
1 2 3 4 5 6
4
99 59 42 20
5
1 2 3 4 5
5
1 2 3 4 5
Output:
Not identical
Identical

Explanation:
Testcase 1: Each element of the first linked list is not equal to each elements of the second linked list in the same order.
Testcase 2: Each element of the first linked list is equal to each elements of the second linked list in the same order.

########################################################################Solution#################################################################################################
*/

class Solution {
    
    // Function which returns true if both linked
    // lists are identical else return false
    public boolean isIdentical (Node head1, Node head2){
        //write your code here and return true if they are identical, otherwise false
        if(head1 == null && head2 == null)
            return true;
        else if(head1 == null || head2 == null)
            return false;
            
        Node curr1 = head1;
        Node curr2 = head2;
        
        while(curr1 != null && curr2 != null){
            if(curr1.data != curr2.data)
                return false;
            curr1 = curr1.next;
            curr2 = curr2.next;
        }
        
        if(curr1 == null && curr2 == null)
            return true;
        return false;
    }
}
