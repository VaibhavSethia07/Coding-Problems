/*
Given a Binary Tree and a positive integer k. The task is to count all distinct nodes that are distance k from a leaf node. A node is at k distance from a leaf if it is present k levels above the leaf and also, is a direct ancestor of this leaf node. If k is more than the height of Binary Tree, then nothing should be counted.

Input:
The first line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
Count the distinct number of nodes that are at distance k from the leaf nodes.

Your Task:
You don't have to read input or print anything. Complete the function printKDistantfromLeaf() that takes root node and k as inputs and returns the number of nodes that are at distance k from a leaf node. Any such node should be counted only once. For example, if a node is at a distance k from 2 or more leaf nodes, then it would add only 1 to our count.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= T <= 30
1 <= N <= 105

Example:
Input:
2
1 2 3 4 5 6 7 N N N N N 8
2
1 3 N 5 N 7 8 N N 9
4
Output:
2
1

Explanation:
Testcase 1:
There are only two unique nodes that are at a distance of 2 units from the leaf node. 
(node 3 for leaf with value 8 and node 1 for leaves with values 4, 5 and 7)
Note that node 2 isn't considered for leaf with value 8 because it isn't a direct ancestor of node 8.
Testcase 2:
Only one node is there which is at a distance of 4 units from the leaf node.
(node 1 for leaf with value 9)

##################################################################################Solution#######################################################################################
*/

class Solution{

    int printKDistantfromLeaf(Node root, int k)
    {
        ArrayList<Node> path = new ArrayList<>();
        HashSet<Node> uniqueNodes = new HashSet<>();
        findPath(root,k,path,uniqueNodes);
        
        return uniqueNodes.size();
        
    }
    
    static void findPath(Node root,int K,ArrayList<Node> path,HashSet<Node> uniqueNodes){
        if(root == null)
            return;
        
        path.add(root);
        if(root.left == null && root.right == null){
            if(K<path.size())
                uniqueNodes.add(path.get(path.size()-K-1));
        }
        
        findPath(root.left,K,path,uniqueNodes);
        findPath(root.right,K,path,uniqueNodes);
        path.remove(root);
    }
}
