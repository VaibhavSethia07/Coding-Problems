/*
Given a BST and a key. Insert a new Node with value equal to that key into the BST. 

Input:
The first line of input contains the number of test cases T. For each test case, there will two lines. The first line of input is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.

For example:
 
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Second-line is an integer representing the key value which needs to be inserted

Output:
For each test case, in a new line, the inorder of the BST gets printed.

Your Task:
You don't need to read input or print anything. Your task is to complete the function insert() which takes the root of the BST and a Key as inputs and returns the root of the BST after inserting the Key value into it. 

Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 10
1 <= N <= 100000
1 <= K <= 1000000

Example:
Input:
2
2 1 3 
4
2 1 3 N N N 6 4
1
Output:
1 2 3 4
1 2 3 4 6

Explanation:
Testcase 1: After inserting the node 4 the tree will be
                                          2
                                      /        \
                                    1          3
                                                   \
                                                    4
Inorder traversal will be 1 2 3 4.
Testcase 2: After inserting the node 1 the tree will be 
                                         2
                                    /           \
                                  1            3
                                /     \       /     \
                              N     N     N     6
                                                   /
                                                 4
Inorder traversal of the above tree will be 1 2 3 4 6.

Note:
In case a node with value equal to the given Key is already present in the BST, you simply need to ignore the insertion, ie no insertion has to be made in that case.
############################################################################Solution#############################################################################################
*/

// Recursive Solution
class Solution{
    
    // The function returns the root of the BST (currently rooted at 'root') 
    // after inserting a new Node with value 'Key' into it. 
    Node insert(Node root, int Key)
    {   
        if(root == null)
            return new Node(Key);
            
        if(root.data > Key)
            root.left = insert(root.left,Key);
        else if(root.data<Key)
            root.right = insert(root.right,Key);

        return root;
    }
}

// Iterative Solution
class Solution{
    
    // The function returns the root of the BST (currently rooted at 'root') 
    // after inserting a new Node with value 'Key' into it. 
    Node insert(Node root, int Key)
    {
        Node parent = null;
        Node curr = root;
        
        while(curr != null){
            parent = curr;
            if(curr.data > Key)
                curr = curr.left;
            else if(curr.data < Key)
                curr = curr.right;
            else
                return root;
        }
        
        if(parent == null)
            return new Node(Key);
        else if(parent.data > Key)
            parent.left = new Node(Key);
        else
            parent.right = new Node(Key);
        
        return root;
    }
}
