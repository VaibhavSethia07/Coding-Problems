/*
Merge two sorted linked lists
Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) and return head of the merged list.
Note: It is strongly recommended to do merging in-place using O(1) extra space.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains N and M, and next two line contains N and M sorted elements in two lines for each.

Output:
For each testcase, print the merged list in sorted form.

User Task:
The task is to complete the function sortedMerge() which takes references to the heads of two linked lists as the arguments and returns the head of merged linked list.

Expected Time Complexity : O(n+m)
Expected Auxilliary Space : O(1)

Constraints:
1 <= T <= 100
1 <= N, M <= 104
1 <= Node's data <= 105

Example:
Input:
2
4 3
5 10 15 40 
2 3 20
2 2
1 1
2 4 
Output:
2 3 5 10 15 20 40
1 1 2 4

Explanation:
Testcase 1: After merging the two linked lists, we have merged list as 2, 3, 5, 10, 15, 20, 40.
Testcase 2: After merging the given two linked list , we have 1, 1, 2, 4 as output.

##################################################################################Solution#######################################################################################
*/

class LinkedList
{
    Node sortedMerge(Node headA, Node headB) {
     // This is a "method-only" submission. 
     // You only need to complete this method
     Node head = null;
     Node tail = null;
     Node a = headA;
     Node b = headB;
     
     if(a.data<=b.data){
         head = a;
         tail = a;
         a = a.next;
     }
     else{
         head = b;
         tail = b;
         b = b.next;
     }
     
     while(a != null && b!= null){
         if(a.data <= b.data){
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
     
     if(a == null)
         tail.next = b;
     if(b == null)
         tail.next = a;
         
     return head;
   } 
}
