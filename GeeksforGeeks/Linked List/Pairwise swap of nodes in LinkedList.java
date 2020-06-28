/*
Given a linked list of N positive integers. You need to swap elements pairwise. Your task is to complete the function pairwise_swap().

Input:
The input line contains T, denoting the number of testcases. Each testcase contains two lines, the first line contains N(size of linked list). The second line contains N elements of linked list separately.

Output:
For each testcase, in new line, print the modified linked list.

User Task:
Since this is a functional problem you don't have to worry about input and output, you just have to complete the function pairwise_swap(). The printing is done automatically by the driver code.

Constraint:
1 <= T <= 100
1 <= N <= 100
1 <= Node values <= 1000

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

Example:
Input:
2
7
1 2 3 4 5 6 7
6
1 2 3 4 5 6
Output:
2 1 4 3 6 5 7
2 1 4 3 6 5

Explanation:
Testcase 1: The linked list after swapping becomes: 1 2 3 4 5 6 7 -> 2 1 4 3 6 5 7.
Testcase 2: The linked list after swapping becomes: 1 2 3 4 5 6 -> 2 1 4 3 6 5.

############################################################################Solution#############################################################################################
*/

class Swap
{
    public static Node pairwise_swap(Node head)
    {
        if(head == null || head.next == null)   
            return head;
        
        Node curr = head.next.next;
        Node prev = head;
        head = head.next;
        head.next = prev;
        prev.next = curr;
        
        while(curr != null && curr.next != null){
            prev.next = curr.next;
            Node temp = curr.next.next;
            prev.next.next = curr;
            prev = curr;
            curr.next = temp;
            curr = temp;
        }
        
        return head;
    }    
}
