/*
Given a Binary Tree, you need to find the maximum value which you can get by subtracting the value of node B from the value of node A, where A and B are two nodes of the binary tree and A is an ancestor of B. 

Input:
The first line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
The function should return an integer denoting the maximum difference.

User Task:
The task is to complete the function maxDiff() which finds the maximum difference between the node and its ancestor.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H).
Note: H is the height of the tree.

Constraints:
1 <= T <= 30
1 <= Number of edges <= 104
0 <= Data of a node <= 105

Example:
Input:
2
5 2 1
1 2 3 N N N 7
Output:
4
-1

Explanation:
Testcase 1:

             5
           /    \
         2      1
The maximum difference we can get is 4, which is bewteen 5 and 1.

Testcase 2:

             1
           /    \
         2      3
                   \
                    7
The maximum difference we can get is -1, which is between 1 and 2.

#############################################################################################Solution############################################################################
*/

class Tree
{
    int maxDiff(Node root)
    {
        Global obj = new Global();
        maxDiffUtil(root,obj);
        return obj.globalDiff;
    }
    
    static int maxDiffUtil(Node root,Global obj){
        if(root == null)
            return Integer.MAX_VALUE;
            
        int leftSmall = maxDiffUtil(root.left,obj);
        int rightSmall = maxDiffUtil(root.right,obj);
        
        int currSmall = Math.min(leftSmall,rightSmall);
        obj.globalDiff = Math.max(obj.globalDiff,root.data-currSmall);
        
        return Math.min(root.data,currSmall);
        
    }
}

class Global{
    int globalDiff=Integer.MIN_VALUE;
}
