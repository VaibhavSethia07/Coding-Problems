/*
Two of the nodes of a Binary Search Tree (BST) are swapped. Fix (or correct) the BST by swapping them back. Do not change the structure of the tree.

Input Format:

First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Note: It is guaranteed than the given input will form BST, except for 2 nodes that will be wrong.

Output Format:
For each testcase, 1 will be printed in a new line if BST is corrected as required. Otherwise, 0 will be printed.

Your Task:
You don't need to take any input. Just complete the function correctBst() that takes root node as parameter. The function should return the root of corrected BST. BST will then be checked by driver code and 0 or 1 will be printed.

Expected Time Complexity : O(n)

Expected Auxiliary Space : O(1)

Constraints:
1 <= T <= 1000
1 <= N <= 1000

Example:
Input:
2
10 5 8 2 20
11 3 17 N 4 10

Output:
1
1

Explanation:
Testcase 1:

###########################################################################################Solution##############################################################################
*/

class Sol
{   static Node prev;
    public Node correctBST(Node root)
    {   prev = null;
        Fix obj = new Fix();
        
        correcting(root,obj);
        swapData(obj.first,obj.second);
        
        return root;
    }
    
    public static void correcting(Node root,Fix obj){
        if(root == null)
            return;
            
        correcting(root.left,obj);
        
        if(prev != null && root.data<prev.data){
            if(obj.first == null)
                obj.first = prev;
            obj.second = root;
        }
        prev = root;
        correcting(root.right,obj);
    }
    
    public static void swapData(Node first,Node second){
        int temp = first.data;
        first.data = second.data;
        second.data = temp;
    }
}

class Fix{
    Node first = null;
    Node second = null;
}
