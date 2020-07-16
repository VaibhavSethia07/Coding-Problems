/*
Given two binary trees, the task is to find if both of them are identical or not. 

Input:
First line of input contains the number of test cases T. For each test case, there will be two lines of input each of which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

 

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N
Output:
The function should return true if both trees are identical else false.

User task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function isIdentical() that takes two roots as parameters and returns true or false. The printing is done by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 1000
1 <=Data of a node <= 1000

Example:
Input:
3
1 2 3
1 2 3
1 2 3
1 3 2
1 2 3 N 3 N 10
1 2 3 N 3 N 10
Output:
Yes
No
Yes

Explanation:
Testcase 1: There are two trees both having 3 nodes and 2 edges, both trees are identical having the root as 1, left child of 1 is 2 and right child of 1 is 3.
Testcase 2: There are two trees both having 3 nodes and 2 edges, but both trees are not identical.
Testcase 3: There are two trees which are totally identical to each other.

##############################################################################Solution###########################################################################################
*/

class Tree
{
	boolean isIdentical(Node root1, Node root2)
	{
	    if(root1 == null && root2 == null)
	        return true;
	    else if(root1 == null || root2 == null)
	        return false;
	    return ((root1.data == root2.data) && isIdentical(root1.left,root2.left) && isIdentical(root1.right,root2.right));
	}
	
}
