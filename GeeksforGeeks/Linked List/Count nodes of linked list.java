/*
Count nodes of linked list
Given a singly linked list. The task is to find the length of the linked list, where length is defined as the number of nodes in the linked list.

Input:
The first line of input contains the number of test cases T. For each test case, the first line of input contains the number of nodes N, to be inserted into the linked list and the next line contains data of N nodes.

Output:
There will be a single line of output for each test case, which contains the length of the linked list.

User Task:
Your task is to complete the given function getCount(), which takes a head reference as an argument and should return the length of the linked list.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= value <= 103

Example:
Input:
2
5
1 2 3 4 5
7
2 4 6 7 5 1 0
Output:
5
7

################################################################################Solution###########################################################################################
*/

public static int getCount(Node head)
    {
        if(head == null)
            return 0;
          
        int count = 0;
        
        for(Node curr = head; curr != null;  curr = curr.next)
            count++;
            
        return count;
    }
