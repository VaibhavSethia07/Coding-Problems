/*
Detect Loop in linked list
Given a linked list of N nodes. The task is to check if the the linked list has a loop. Linked list can contain self loop.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains length of linked list and next line contains the data of linked list. Third line contains an integer denoting the position of the linked list node(counting from head) to which the last node connects in order to create a loop. If this integer is 0, this means no loop exists.

Output:
For each testcase, print "True", if linked list contains loop, else print "False".

User Task:
The task is to complete the function detectloop() which contains reference to the head as only argument. This function should return 1 if linked list contains loop, else return 0.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= T <= 100
1 <= N <= 104
1 <= Data on Node <= 103

Example:
Input:
2
3
1 3 4
2
4
1 8 3 4
0
Output:
True
False

Explaination:
Testcase 1: In above test case N = 3. The linked list with nodes N = 3 is given. Then value of x=2 is given which means last node is connected with xth node of linked list. Therefore, there exists a loop. 
Testcase 2: For N = 4 ,x = 0 means then lastNode->next = NULL, then the Linked list does not contains any loop.

###########################################################################Solution##############################################################################################
*/

// Solution 1
class Solution {
    public static boolean detectLoop(Node head){
        HashSet<Node> hs = new HashSet<>();
        
        for(Node curr = head;curr != null;curr = curr.next){
            if(hs.contains(curr))
                return true;
            hs.add(curr);
        }
        
        return false;
    }
}

// Solution 2
class Solution {
    public static boolean detectLoop(Node head){
        Node temp = new Node(0);
        Node curr = head;
        
        while(curr != null){
            if(curr.next == temp)
                return true;
            Node next = curr.next;
            curr.next = temp;
            curr = next;
        }
        
        return false;
    }
}

// Solution 3
class Solution {
    public static boolean detectLoop(Node head){
        Node slow = head;
        Node fast = head;
        
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
            
            if(slow == fast)
                return true;
        }
        
        return false;
    }
}
