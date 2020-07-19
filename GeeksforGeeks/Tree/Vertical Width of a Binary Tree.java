/*
Given a Binary Tree of N nodes. The task is to find the vertical width of the tree.
The width of a binary tree is the number of vertical paths in that tree.



The above tree contains 6 vertical lines which is the required vertical width of the tree.

Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:
  

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
For each test case, there will be a single line of output containing the vertical widht of the binary tree.

User Task:
You don't have to read input or print anything. Your task is to complete the function verticalWidth() which takes root as the only parameter, and returns the vertical width of the binary tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 103

Example:
Input:

2
1 2 3 4 5 6 7 N N N N N 8 N 9
1 2 3
Output:
6
3

Explanation:
Testcase 1: According to the explanation given in the above figure , for the given input vertical width of the tree will be 6.
Testcase 2: According to the explanation given in the above figure , for the given input vertical width of the tree will be 3.

################################################################################Solution#########################################################################################
*/

class Tree
{
    
    public static int verticalWidth(Node root)
	{
	    HashSet<Integer> hs = new HashSet<>();
	    verticalDistance(root,0,hs);
	    return hs.size();
	}
	
	static void verticalDistance(Node root,int distance,HashSet<Integer> hs){
	    if(root == null)
	        return;
	    
	    hs.add(distance);
	    verticalDistance(root.left,distance-1,hs);
	    verticalDistance(root.right,distance+1,hs);
	}
}
