/*
Given a Binary Tree of N edges. The task is to convert this to a Circular Doubly Linked List(CDLL) in-place. The left and right pointers in nodes are to be used as previous and next pointers respectively in converted CDLL. The order of nodes in CDLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (left most node in BT) must be head node of the CDLL.

Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
For each test case, in a new line, print the traversals of CDLL.

Your Task:
You don't have to take input. Complete the function bTreeToCList() that takes root as a parameter and returns the head of the list. The printing is done by the driver code.

Constraints:
1 <= T <= 250
1 <= N <= 103
1 <= Data of a node <= 104

Expected time complexity: O(N)

Expected auxiliary space: O(h) , where h = height of tree

Example:
Input:
2
1 3 2
10 20 30 40 60
Output:
3 1 2 
2 1 3
40 20 60 10 30 
30 10 60 20 40

Explanation:
Testcase 1: Given tree is
                          1
                      /        \
                    3         2
After converting tree to CDLL, when CDLL is is traversed from head to tail and then tail to head, elements are displayed as in the output.
Testcase 2: Given tree is 
                         10
                      /        \
                    20      30
                 /        \
               40       60
After converting tree to CDLL, when CDLL is is traversed from head to tail and then tail to head, elements are displayed as in the output.

#########################################################################Solution################################################################################################
*/

class Tree
{ 
    Node prev;
    Node temp;
    Node bTreeToClist(Node root)
    {
        if(root == null)
            return root;
            
        Node head = bTreeToClist(root.left);
        boolean flag = false;
        
        if(prev == null){
            temp = root;
            head = root;
        }
        else{
            prev.right = root;
            root.left = prev;
        }
        prev = root;
        
        bTreeToClist(root.right);
        if((temp == head && prev!=temp)|| temp.left == null && temp.right == null){
            prev.right = temp;
            temp.left = prev;
        }
        return head;
    }
    
}
