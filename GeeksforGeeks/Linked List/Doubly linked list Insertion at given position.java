/*
Doubly linked list Insertion at given position
Given a doubly-linked list, a position p, and an integer x. The task is to add a new node with value x at the position just after pth node in the doubly linked list.

Input:
The first line of input contains the number of test cases T. For each test case, the first line of input contains the number of nodes in the linked list, and next line contains two integers p and x.

Output:
For each testcase, there will be a single line of output which prints the modified linked list.

User Task:
The task is to complete the function addNode() which head reference, position and data to be inserted as the arguments, with no return type.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

Constraints:
1 <= T <= 200
1 <= N <= 104
0 <= p < N

Example:
Input:
2
3
2 4 5
2 6
4
1 2 3 4
0 44
Output:
2 4 5 6
1 44 2 3 4

Explanation:
Testcase 1: p = 2, and x = 6. So, 6 is inserted after p, i.e, at position 3 (0-based indexing).
Testcase 2: p = 0, and x = 44 . So, 44 is inserted after p, i.e, at position 1 (0-based indexing).

###########################################################################################Solution##############################################################################
*/

class GfG
{
void addNode(Node head_ref, int pos, int data)
	{
	    Node temp = new Node(data);
	    
	    if(head_ref == null){
	        head_ref = temp; 
	        return;    
	    }
	    
	    Node curr = head_ref;
	    for(int i=0;i<pos;i++)
	        curr = curr.next;
	        
	   temp.next = curr.next;
	   if(curr.next != null)
	       curr.next.prev = temp;
	       
	   curr.next = temp;
	   temp.prev = curr;
	}
}
