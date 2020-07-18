/*
Given a binary tree and an integer X. Your task is to complete the function countSubtreesWithSumX() that returns the count of the number of subtress having total node’s data sum equal to the value X.
Example: For the tree given below:            

              5
            /    \
        -10     3
        /    \    /  \
      9     8  -4 7

Subtree with sum 7:
             -10
            /      \
          9        8

and one node 7.

Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
For each test case count the number of subtrees with given sum.

Your Task:
You don't need to read input or print anything. Your task is to complete the function countSubtreesWithSumX() which takes the root node and an integer X as inputs and returns the number of subtrees of the given Binary Tree having sum exactly equal to X.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= T <= 100
1 <= N <= 103
-103 <= Node Value <= 103

Example:
Input:
2
5 -10 3 9 8 -4 7
7
1 2 3
5
Output:
2
0

Explanation:
Testcase 1: Subtrees with sum 7 are [9, 8, -10] and [7] (refer the example in the problem description).
Testcase 2: No subtree has sum equal to 5.

#####################################################################################Solution####################################################################################
*/

// Method 1
class Tree
{
    int countSubtreesWithSumX(Node root, int X)
    {
        Counter obj = new Counter();
        subTreeSum(root,X,obj);
        return obj.count;
    }
    
    static int subTreeSum(Node root,int X,Counter obj){
        if(root == null)
            return 0;
        
        int leftSum = subTreeSum(root.left,X,obj);
        int rightSum = subTreeSum(root.right,X,obj);
        
        int sum = root.data+leftSum+rightSum;
        if(sum==X)
            obj.count++;
        
        return sum;
    }
}

class Counter{
    int count;
}

// Method 2
class Tree
{   int count = 0;
    boolean flag = true;
    Node ptr;
    int countSubtreesWithSumX(Node root, int X)
    {
        if(root==null)
            return 0;
        if(flag){
            ptr = root;
            flag=false;
        }
        int leftSum = countSubtreesWithSumX(root.left,X);
        int rightSum = countSubtreesWithSumX(root.right,X);
        int sum = leftSum+rightSum+root.data;
        
        if(sum==X)
            count++;
        if(ptr != root){
            return sum;
        }
        return count;
    }
}
