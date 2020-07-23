/*
Given a Binary Search Tree (with all values unique) and two node values. Find the Lowest Common Ancestors of the two nodes in the BST.

Input:
First line of input contains the number of test cases T. For each test case, there will be two line of input. First line is a string representing the tree as described below:

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

The second line of Input contains two space separated integer values n1 and n2.

Output:
For each testcase, in a new line, print the LCA of n1 and n2.

Your Task:
You don't need to read input or print anything. Your task is to complete the function LCA() which takes the root Node of the BST and two integer values n1 and n2 as inputs and returns the Lowest Common Ancestor of the Nodes with values n1 and n2 in the given BST. 

Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= T <= 100
1 <= N <= 104

Example:
Input:
2
5 4 6 3 N N 7 N N N 8
7 8
2 1 3
1 3
Output:
7
2

Explanation:
Testcase1: The BST in above test case will look like
              5
          /        \ 
        4          6
     /     \     /      \
   3      N  N       7
 /    \                 /    \ 
N   N              N     8
Here, the LCA of 7 and 8 is 7.
Testcase 2: For the given above test case the BST will be
                    2
                  /    \
                1      3
Here, the LCA of 1 and 3 will be 2

###########################################################################Solution##############################################################################################
*/

// Naive Method
class BST
{   
    // Returns the LCA of the nodes with values n1 and n2
    // in the BST rooted at 'root' 
	Node LCA(Node root, int n1, int n2)
	{
	    if(root == null)
	        return null;
	        
	   ArrayList<Node> path1 = new ArrayList<>();
	   ArrayList<Node> path2 = new ArrayList<>();
	    
	   findPath(root,n1,path1);
	   findPath(root,n2,path2);
	   
	   if(path1.isEmpty() || path2.isEmpty())
	       return null;
	       
	   for(int i=Math.min(path1.size(),path2.size())-1;i>=0;i--)
	        if(path1.get(i) == path2.get(i))
	           return path1.get(i);
	           
	   return root;
    }
    
    void findPath(Node root,int n, ArrayList<Node> path){
        if(root == null)
            return;
        
        path.add(root);
        
        if(root.data > n){
            findPath(root.left,n,path);
        }
        else if(root.data < n){
            findPath(root.right,n,path);
        }
    }  
}

// Efficient Method
class BST
{   
    // Returns the LCA of the nodes with values n1 and n2
    // in the BST rooted at 'root' 
	Node LCA(Node root, int n1, int n2)
	{
	    if(root == null)
	        return null;
	        
	    if(root.data == n1 || root.data == n2)
	        return root;
	       
	    Node lca1 = LCA(root.left,n1,n2);
	    Node lca2 = LCA(root.right,n1,n2);
	    
	    if(lca1 != null && lca2 != null)
	        return root;
	    else if(lca1 != null)
	        return lca1;
	    else 
	        return lca2;
	        
    }   
}

// Best Method
class BST
{   
    // Returns the LCA of the nodes with values n1 and n2
    // in the BST rooted at 'root' 
	Node LCA(Node root, int n1, int n2)
	{
	    int Min = Math.min(n1,n2);
	    int Max = Math.max(n1,n2);
	   // System.out.println(Min+" "+Max);
	    if(root == null)
	        return root;
	    else if(root.data>=Min && root.data<=Max)
	        return root;
	    else if(root.data>Max)
	        return LCA(root.left,n1,n2);
	    else if(root.data<Min)
	        return LCA(root.right,n1,n2);
	        
	    return root;
    }
}
