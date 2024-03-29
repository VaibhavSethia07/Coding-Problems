/*
Inorder traversal means traversing through the tree in a Left, Node, Right manner. We first traverse left, then print the current node, and then traverse right. This is done recursively for each node.
You are given an array arr of size sizeOfArray. You need to create a BST using elements of the array. The BST is to be created using the elements in the order of their arrival.

Input:
The first line of input contains testcases number. Each testcase contains two lines of input. The first line contains size of the array. The second line contains elements of the array.

Output:
For each testcase, in a newline, print the Inorder traversal.

Your Task:
This is a function problem. You don't need to take any input. For this problem, your task is to complete the Inorder function that prints preorder traversal of the BST. This function takes in root as parameter.
Expected Time Complexity: O(N), where N = Number of nodes in BST
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= testcases <= 100
1 <= sizeOfArray <= 100
1 <= arri <= 100

Example:
Input:
2
5
5 2 3 7 8
3
30 10 20
Output:
2 3 5 7 8
10 20 30

Explanation:
Testcase 1: For the given elements of tree , the inorder traversal will be 2 3 5 7 8 as the tree will be
                                     5
                                /          \
                              2           7
                                 \            \
                                 3            8
Testcase 2: For the given elements of tree , the inorder traversal will be 10 20 30 as the tree will be
                                      30
                                   /
                                10
                                      \
                                       20

####################################################################################Solution#####################################################################################
*/

public static void inOrder(Node root)
    {
        if(root==null)
        return;
        
        inOrder(root.left);
        System.out.print(root.data+" ");
        inOrder(root.right);
    }
