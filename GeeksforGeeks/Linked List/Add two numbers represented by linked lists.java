/*
Add two numbers represented by linked lists
Given two numbers represented by two linked lists of size N and M. The task is to return a sum list. The sum list is a linked list representation of the addition of two input numbers.

Input:
The first line of input contains the number of test cases T. For each test case, the first line of input contains the length of the first linked list and next line contains N elements of the linked list. Again, the next line contains M, and the following line contains M elements of the linked list.

Output:
Output the resultant linked list.

User Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the new list.

Expected Time Complexity: O(N) + O(M)
Expected Auxiliary Space: O(N) + O(M)

Constraints:
1 <= T <= 100
1 <= N, M <= 5000

Example:
Input:
2
2
4 5
3
3 4 5
2
6 3
1
7
Output:
3 9 0  
7 0

Explanation:
Testcase 1: For the given two linked list (4 5) and (3 4 5), after adding the two linked list resultant linked list will be (3 9 0).
Testcase 2: For the given two linked list (6 3) and (7), after adding the two linked list resultant linked list will be (7 0).

###########################################################################Solution##############################################################################################
*/

class Solution{
    static Node head;
    static Node addLists(Node first, Node second){
        head = null;
        ArrayList<Integer> al1 = new ArrayList<>();
        ArrayList<Integer> al2 = new ArrayList<>();
        
        for(Node curr = first;curr != null; curr = curr.next)
            al1.add(curr.data);
            
        for(Node curr = second; curr != null;curr = curr.next)
            al2.add(curr.data);
            
        int sum = 0,carry = 0;
        int digit1 = 0, digit2 = 0;
        
        while(!al1.isEmpty() && !al2.isEmpty()){
            digit1 = al1.remove(al1.size()-1);
            digit2 = al2.remove(al2.size()-1);
            sum = ((digit1 + digit2)+ carry)%10;
            carry = ((digit1 + digit2)+ carry)/10;
            
            Node node = new Node(sum);
            (new Solution()).insertAtBegin(node);
        }
        
        while(!al1.isEmpty()){
            digit1 = al1.remove(al1.size()-1);
            sum = (digit1 + carry)%10;
            carry = (digit1 + carry)/10;
            Node node = new Node(sum);
            (new Solution()).insertAtBegin(node);
        }
            
        while(!al2.isEmpty()){
            digit2 = al2.remove(al2.size()-1);
            sum = (digit2 + carry)%10;
            carry = (digit2 + carry)/10;
            Node node = new Node(sum);
            (new Solution()).insertAtBegin(node);
        }
        
        if(carry != 0){
            Node node = new Node(carry);
            (new Solution()).insertAtBegin(node);
        }
            
        return head;
    }
    
    void insertAtBegin(Node node){
        node.next = head;
        head = node;
    }
}

// Solution2
class GfG {

    Node cur; // Dont change the variable name, its used in main function
    int carry; // Dont change the variable name, its used in main function
    int sum;
   
    
    void addCarryToRemaining(Node head, LinkedList res)  { 
        if(head != cur ){
            addCarryToRemaining(head.next,res);
            sum = (head.data + carry)%10;
            carry = (head.data + carry)/10;
            res.push(sum);
        }
        
    } 
    
	void addSameSize(Node head1, Node head2, LinkedList res) { 
	    Node h1 = reverse(head1);
	    Node h2 = reverse(head2);
	    
	    Node curr1 = h1;
	    Node curr2 = h2;
	    
	    while(curr1 != null && curr2 != null){
	        sum = (curr1.data + curr2.data + carry)%10;
	        carry = (curr1.data + curr2.data + carry)/10;
	        res.push(sum);
	        curr1 = curr1.next;
	        curr2 = curr2.next;
	    }
    }
    
    Node reverse(Node head){
        
        if(head == null || head.next == null)
            return head;
            
        Node restHead = reverse(head.next);
        Node restTail = head.next;
        restTail.next = head;
        head.next = null;
        
        return restHead;
    }
} 
