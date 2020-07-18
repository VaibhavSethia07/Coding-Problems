/*
Given a binary tree, the task is to find the maximum path sum. The path may start and end at any node in the tree.

Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
Print the maximum path sum in the binary tree.

User Task:
You don't need to take input or print anything. Your task is to complete the function findMaxSum() that takes root as input and returns max sum between any two nodes in the given Binary Tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 103
1 <= |Data on node| <= 104

Example:
Input:
2
10 2 -25 20 1 3 4
10 2 5 N N N -2
Output:
32
17

Explanation:
Testcase 1: Path in the given tree goes like 10 , 2 , 20 which gives the max sum as 32.
Testcase 2: Path in the given tree goes like 2 , 10 , 5 which gives the max sum as 17.

#################################################################################Solution########################################################################################
*/

class Tree
{
    // This function should returns sum of
    // maximum sum path from any node in
    // a tree rooted with given root.
    int findMaxSum(Node node)
    {
        Global obj = new Global();
        findMax(node,obj);
        return obj.globalSum;
    }
    
    static int findMax(Node root,Global obj){
        if(root == null)
            return 0;
            
        int leftSum = findMax(root.left,obj);
        int rightSum = findMax(root.right,obj);
        
        int s1 = root.data;
        int s2 = root.data+Math.max(leftSum,rightSum);
        int s3 = root.data+leftSum+rightSum;
        
        obj.globalSum = Math.max(Math.max(Math.max(s1,s2),s3),obj.globalSum);
        return Math.max(s1,s2);
    }
}

class Global{
    int globalSum = Integer.MIN_VALUE;
}
