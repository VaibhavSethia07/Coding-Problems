/*
Clone a linked list with next and random pointer
You are given a Singly Linked List with N nodes where each node next pointing to its next node. You are also given M random pointers , where you will be given M number of pairs denoting two nodes a and b  i.e. a->arb = b.

ArbitLinked List1
Input:
First line of input contains number of testcases T. For each testcase, first line of input contains two integers N and M. Next line of input contains values of N nodes of the linked list and last line contains M pairs denoting arbitrary connecting  nodes, for which each ith node is connected to any jth node. ( ith->arb = jth ).
NOTE : If their is any node whose arbitrary pointer is not given then its by default null.

Output:
For each testcase, clone the given linked list.

Your Task:
The task is to complete the function copyList() which takes one argument the head of the linked list to be cloned and should return the head of the cloned linked list.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(1)

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= M <= N
1 <= a, b <= 100

Example:
Input:
2           
4 2                                       
1 2 3 4                             
1 2 2 4
4 3
1 3 5 9
1 1 3 4
Output:
1
1

Explanation:
Testcase 1: In this test case, there are 4 nodes in linked list.  Among these 4 nodes,  2 nodes have arbit pointer set, rest two nodes have arbit pointer as NULL. Third line tells us the value of four nodes. The fourth line gives the information about arbitrary pointers. The first node arbit pointer is set to node 2.  The second node arbit pointer is set to node 4.
Testcase 2: In the given testcase , applying the method as stated in the abpve testcase , the output will be 1.

######################################################################################Solution###################################################################################
*/

// Solution 1
class Clone {
    Node copyList(Node head) {
        HashMap<Node,Node> hm = new HashMap<>();
        
        for(Node curr = head; curr != null;curr = curr.next)
            hm.put(curr,new Node(curr.data));
            
        for(Node curr = head; curr != null; curr = curr.next){
            Node cloneNode = hm.get(curr);
            cloneNode.next = hm.get(curr.next);
            cloneNode.arb = hm.get(curr.arb);
        }
        
        Node h2 = hm.get(head);
        return h2;
    }
}

// Solution 2
class Clone {
    Node copyList(Node head) {
        for(Node curr = head; curr != null ; curr = curr.next.next){
            Node clone = new Node(curr.data);
            clone.next = curr.next;
            curr.next = clone;
        }
        
        for(Node curr = head; curr != null ;curr = curr.next.next)
            if(curr.arb != null)
                curr.next.arb = curr.arb.next;
            
        Node h2 = head.next;
        Node curr = head;
        
        while(curr != null ){
            Node temp = curr.next.next;
            if(temp != null)
                curr.next.next = temp.next;
            curr.next = temp;
            curr = temp;
        }
        
        return h2;
    }
}
