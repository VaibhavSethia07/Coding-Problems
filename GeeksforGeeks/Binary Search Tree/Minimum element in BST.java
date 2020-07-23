/*
Given a Binary Search Tree. The task is to find the minimum element in this given BST. If the tree is empty, there is no minimum elemnt, so print -1 in that case.

Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
For each testcase in new line, print the minimum element in BST.

User Task:
The task is to complete the function minValue() which takes root as the argument and returns the minimum element of BST.

Expected Time Complexity: O(Height of the BST)
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= T <= 100
1 <= N <= 104

Example:
Input:
2
5 4 6 3 N N 7 1
9 N 10 N 11
Output:
1
9

Explanation:
Testcase 1: We construct the following BST by inserting given values one by one in an empty BST.
            5
          /     \
       4         6
     /              \
   3                7
   /
 1

The minimum value in the given BST is 1.
Testcase 2: We construct the following BST by inserting given values one by one in an empty BST.
             9
                \
                10
                    \
                    11
The minimum value in the given BST is 9.

######################################################################################Solution###################################################################################
*/

class Tree
{
    int minValue(Node node)
    {
        if(node == null)
            return -1;
        
        if(node.left == null)
            return node.data;
            
        return minValue(node.left);
    }
}
