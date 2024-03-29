/*
Inorder Traversal
Given a Binary Tree, find the In-Order Traversal of it.

Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:
 
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
For each test case, in a new line, print the inorder traversal.

Your Task:
You don't need to read input or print anything. Your task is to complete the function inOrder() that takes root node of the tree as input and returns a list containing the In-Order Traversal of the given Binary Tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 30
1 <= Number of nodes <= 105
1 <= Data of a node <= 105

Example:
Input:
2
1 3 2
10 20 30 40 60 50
Output:
3 1 2
40 20 60 10 50 30

Explanation:
Testcase1: The tree is
        1
     /      \
   3       2
So, the in order would be 3 1 2
Testcase2: The tree is
                           10
                        /        \
                     20         30
                  /       \        /
               40       60    50
So, the inorder would be 40 20 60 10 50 30

#####################################################################################Solution####################################################################################
*/

class Tree
{
    // Return a list containing the inorder traversal of the given tree
    static void inOrderUtil(Node root,ArrayList<Integer> al){
        if(root != null){
            inOrderUtil(root.left,al);
            al.add(root.data);
            inOrderUtil(root.right,al);
        }
    }
    
    ArrayList<Integer> inOrder(Node root)
    {
        ArrayList<Integer> al = new ArrayList<>();
        inOrderUtil(root,al);
        return al;
    }
}
