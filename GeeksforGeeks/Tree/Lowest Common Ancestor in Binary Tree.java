/*
Given a Binary Tree with all unique values and two nodes value n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them is present. 

Input:
The first line of input contains the number of test cases T. For every test case, the first line of input contains two space-separated integers, denoting node values for which we want to find LCA,  and the second line will contain a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.

For example:

 
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
For each test case, in a new line, print the Lowest Common Ancestor of the two nodes.

Your Task:
This is a function problem. You don't have to read the input. Just complete the function lca() that takes nodes, n1, and n2 as parameters and returns LCA node as output.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H).
Note: H is the height of the tree.

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 100
1 <= Data of a node <= 1000

Example:
Input:
2
2 3
1 2 3
3 4
5 2 N 3 4
Output:
1
2

Explanation:
Testcase1: The tree is
        1
     /      \
   2        3
The LCA of 2 and 3 is 1.
Testcase 2: The tree is
          5
        /
      2
     /   \
   3     4
The lowest common ancestor of given nodes 3 and 4 is 2.

##################################################################################Solution#######################################################################################
*/
// Naive Solution
class Tree
{

	Node lca(Node root, int n1,int n2)
	{
	    if(root == null)
	        return root;
	     
	    ArrayList<Node> path1 = new ArrayList<>();
	    ArrayList<Node> path2 = new ArrayList<>();
	    
	    if(!findPath(root,n1,path1) || !findPath(root,n2,path2))
	        return null;
	    
	    Node res = root;
	    for(int i=0;i<Math.min(path1.size(),path2.size());i++)
	        if(path1.get(i) == path2.get(i))
	            res = path1.get(i);
	    return res;
	}
	
	static boolean findPath(Node root,int n,ArrayList<Node> path){
	    if(root == null)
	        return false;
	   
	    path.add(root);
	    if(root.data == n)
	        return true;
	        
	    if(!findPath(root.left,n,path) && !findPath(root.right,n,path)){
	        path.remove(path.size()-1);
	        return false;
	    }
	    
	    return true;   
	}
}

// Efficient Solution
class Tree
{
	Node lca(Node root, int n1,int n2)
	{
	    if(root == null)
	        return null;
	        
	    if(root.data == n1 || root.data == n2)
	        return root;
	       
	    Node lca1 = lca(root.left,n1,n2);
	    Node lca2 = lca(root.right,n1,n2);
	    
	    if(lca1 != null && lca2 != null)
	        return root;
	       
	    if(lca1 != null)
	        return lca1;
	    else
	        return lca2;
	}
}
