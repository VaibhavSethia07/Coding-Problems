/*
Given a Binary Tree, find diameter of it.
+The diameter of a tree is the number of nodes on the longest path between two leaves in the tree. The diagram below shows two trees each with diameter nine, the leaves that form the ends of a longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).



Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:
  
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
For each testcase, in a new line, print the diameter.

Your Task:
You need to complete the function diameter() that takes node as parameter and returns the diameter.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 10000
1 <= Data of a node <= 1000

Example:
Input:
2
1 2 3
10 20 30 40 60 

Output:
3
4

Explanation:
Testcase1: The tree is
        1
     /      \
   2        3
The diameter is of 3 length.
Testcase2: The tree is
                           10
                        /        \
                     20         30
                  /       \
               40       60
The diameter is of 4 length.

##############################################################################Solution###########################################################################################
*/

// Naive Solution
class Tree {
    /* Complete the function to get diameter of a binary tree */
    int diameter(Node root) {
        if(root == null)
            return 0;
            
        int lh = height(root.left);
        int rh = height(root.right);
        int d1 = lh + rh + 1;
        
        int d2 = diameter(root.left);
        int d3 = diameter(root.right);
        
        return Math.max(d1,Math.max(d2,d3));
    }
    
    int height(Node root){
        if(root == null)
            return 0;
            
        return 1 + Math.max(height(root.left),height(root.right));
    }
}

// Efficent Solution
class Diameter{
    int res;
    Diameter(){
        res = 0;
    }
}
class Tree {
    /* Complete the function to get diameter of a binary tree */
    int diameter(Node root) {
        Diameter d = new Diameter();
        height(root,d);
        return d.res;
    }
    
    static int height(Node root,Diameter obj){
        if(root == null)
            return 0;
            
        int lh = height(root.left,obj);
        int rh = height(root.right,obj);
        obj.res = Math.max(obj.res,lh+rh+1);
        
        return 1+Math.max(lh,rh);
    }
}
