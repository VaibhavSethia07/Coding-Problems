/*
Given a Binary Search Tree and a range. Print all the numbers in the BST that lie in the given range.
Note: Element greater than or equal to root go to the right side.

Input:
First line of input contains the number of test cases T. For each test case, there will be two lines of input First line contains a string representing the tree as described below and second line contains two space seperated integers l and h denoting given range.

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
For each testcase, in a new line, print print all the numbers in the BST that lie in the given range in non-decreasing order.

Your Task:
You don't need to read input or print anything. Your task is to complete the function printNearNodes() which takes the root Node of the BST and the range elements low and high as inputs and returns an array that contains the BST elements in the given range low to high (inclusive) in non-decreasing order.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= T <= 100
1 <= N <= 104
1 <= l < h < 105

Example:
Input:
2
17 4 18 2 9 
4 24
16 7 20 1 10 
13 23
Output:
4 9 17 18 
16 20 

Explanation:
Testcase 1: For the given input, elements which lies in the range of 4 and 24(inclusive) are 4 9 17 18. The generated BST is:
       17
      /    \
    4     18
  /   \
2     9
Testcase 2: For the given input , elements which lies in the range of 13 and 23 inclusive of both are 16 and 20. The generated BST is:
       16
      /    \
    7     20
  /   \
1     10

#####################################################################################Solution####################################################################################
*/

class Solution
{   
	public static ArrayList<Integer> printNearNodes(Node root, int low, int high)
	{
	    ArrayList<Integer> res = new ArrayList<>();
	    if(root == null)
	        return res;
	       
	    nearNodesUtil(root,res,low,high);
	    return res;
    }
    
    static void nearNodesUtil(Node root,ArrayList<Integer> res,int low,int high){
        if(root == null)
            return;
        
        nearNodesUtil(root.left,res,low,high);
        if(root.data>= low && root.data<=high)
            res.add(root.data);
        nearNodesUtil(root.right,res,low,high);
    }
}
