/*
Nth node from end of linked list
Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.

Input:
The first line of input contains the number of testcase T. For each testcase, the first line of input contains the number of nodes in the linked list and the number N. The next line contains L nodes of the linked list.

Output:
For each testcase, output the data of node which is at Nth distance from the end or -1 in case node doesn't exist.

User Task:
The task is to complete the function getNthFromLast() which takes two arguments: reference to head and N and you need to return Nth from the end.

Note:
Try to solve in single traversal.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 200
1 <= L <= 103
1 <= N <= 103

Example:
Input:
2
9 2
1 2 3 4 5 6 7 8 9
4 5
10 5 100 5
Output:
8
-1

Explanation:
Testcase 1: In the first example, there are 9 nodes in linked list and we need to find 2nd node from end. 2nd node from end os 8.  
Testcase 2: In the second example, there are 4 nodes in the linked list and we need to find 5th from the end. Since 'n' is more than the number of nodes in the linked list, the output is -1.

####################################################################################Solution#####################################################################################
*/

// Solution 1
class GfG
{
    // Function to find the nth node from end in the linked list
    // head: head of the linked list
    // n: nth node from end to find
    int getNthFromLast(Node head, int n)
    {
    	int count = 0;
    	
    	for(Node curr = head; curr != null;curr=curr.next)
    	    count++;
    	    
    	if(count<n)
    	    return -1;
    	    
    	Node curr = head;  
    	for(int i=0;i<count-n;i++)
    	    curr = curr.next;
    	   
    	return curr.data;
    }
}

// Soluton 2
class GfG
{
    // Function to find the nth node from end in the linked list
    // head: head of the linked list
    // n: nth node from end to find
    int getNthFromLast(Node head, int n)
    {
        Node first = head;
        Node second = head;
        
        for(int i=0;i<n;i++){
            if(first == null)
                return -1;
            first = first.next;
        }
        
        while(first != null){
            first = first.next;
            second = second.next;
        }
        return second.data;
    }
}
