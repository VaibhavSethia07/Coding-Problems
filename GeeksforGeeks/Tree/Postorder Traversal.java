/*
Given a binary tree, find the Postorder Traversal of it.
For Example, the postorder traversal of the following tree is:  5 10 39 1

        1
     /     \
   10     39
  /
5

Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
For each test case, in a new line, print the postorder traversal.

Your Task:
You don't need to read input or print anything. Your task is to complete the function postOrder() that takes root node as input and returns an array containing the postorder traversal of the given Binary Tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 100
1 <= Data of a node <= 1000

Example:
Input:
2
19 10 8 11 13
11 15 N 7
Output:
11 13 10 8 19
7 15 11

Explanation:
Testcase1: The tree is
       19
     /      \
   10      8
  /    \
11   13
So, the postorder would be 11 13 10 8 19 .
Testcase2: The tree is
                          11
                         /
                      15
                       /
                     7
So, the postorder would be 7 15 11.

#######################################################################################Solution##################################################################################
*/

class Tree
{
    ArrayList<Integer> postOrder(Node root)
    {
        ArrayList<Integer> al = new ArrayList<>();
        
        if(root != null){
            al.addAll(postOrder(root.left));
            al.addAll(postOrder(root.right));
            al.add(root.data);
        }
        
        return al;
    }
}
