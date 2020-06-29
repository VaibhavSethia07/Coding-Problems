/*
Given a singly linked list of size N, and an integer K. You need to swap the Kth node from beginning and Kth node from the end in the linked list.
Note: You need to swap the nodes through the links and not changing the content of the nodes.

Input: 
The first line of input contains the number of testcases T. The first line of every test-case contains N, number of nodes in a linked list, and K, the nodes to be swapped, and the second line contains the elements of the linked list.

Output:  
For each test case, if the nodes are swapped correctly, the output will be 1, else 0.

User Task: 
The task is to complete the function swapkthnode(), which has arguments head, num(no of nodes), and K, and it should return a new head. The validation is done internally by the driver code to ensure that the swapping is done by changing references/pointers only.  A correct code would always cause output as 1.

Expected Time Complexity: O(n)
Expected Auxillary space Complexity: O(1)

Constraints:
1 <= T <= 100
1 <= N <= 103
1 <= K <= 103

Example:
Input:
3
4 1
1 2 3 4
5 3
1 2 3 4 5
4 4
1 2 3 4
Output:
1
1
1

Explanation:
Testcase 1: Here K = 1, hence after swapping the 1st node from the beginning and end the new list will be 4 2 3 1.
Testcase 2: Here k = 3, hence after swapping the 3rd node from the beginning and end the new list will be 1 2 3 4 5.
Testcase 3: Here k = 4, hence after swapping the 4th node from the beginning and end the new list will be 4 2 3 1.

################################################################################Solution#########################################################################################
*/

class GFG
{
    // Should swap Kth node from beginning and 
    // Kth node from end in list and return new head.
    Node swapkthnode(Node head, int num, int K)
    {
        if(num<K || head == null || head.next == null )
            return head;
            
        Node currStart = head, prevStart = null;
        Node currEnd = head, prevEnd = null, nextEnd = head;
        
        for(int i=1;i<=K;i++)
            nextEnd = nextEnd.next;
            
        while(nextEnd != null){
            prevEnd = currEnd;
            currEnd = currEnd.next;
            nextEnd = nextEnd.next;
        }
        
        nextEnd = currEnd.next;
        
        for(int i=1;i<K;i++){
            prevStart = currStart;
            currStart = currStart.next;
        }
        
        if(prevStart != null)
            prevStart.next = currEnd;
        
        if(prevEnd != currStart)
            currEnd.next = currStart.next;
        else
            currEnd.next = currStart;
            
        currStart.next = nextEnd;
        
        if(prevEnd != null && prevEnd != currStart)
            prevEnd.next = currStart;
            
        if(K == 1)
            head = currEnd;
        if(K == num)
            head = currStart;
        return head;
    }
}
