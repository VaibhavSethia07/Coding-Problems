/*
Given two BST, Return elements of both BSTs in sorted form.

Input Format:
The first line of input contains the number of test cases T. For each test case, there will be two lines of input. First of which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.

For example:
 
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Second-line is a string which represents a BST in the same format as described above.

Output Format:
For each test case, in a new line, print the elements of both BSTs in sorted form.

Your Task:
You don't need to read input or print anything. Your task is to complete the function merge() which takes roots of both the BSTs as its input and returns an array of integers denoting the node values of both the BSTs in a sorted order.

Expected Time Complexity: O(M+N) where M and N are the sizes if the two BSTs.
Expected Auxiliary Space: O(Height of BST1 + Height of BST2).

Constraints:
1 <= T <= 10
1 <= Number of Nodes <= 100000

Example:
Input:
2
5 3 6 2 4
2 1 3 N N N 7 6
12 9 N 6 11
8 5 10 2

Output:
1 2 2 3 3 4 5 6 6 7
2 5 6 8 9 10 11 12

###################################################################################Solution######################################################################################
*/

class Solution{
    // Return a integer of integers having all the nodes in both the BSTs in a sorted order.
    static Node prev = null;
    public List<Integer> merge(Node root1,Node root2)
    {
        ArrayList<Integer> res = new ArrayList<>();
        prev = null;
        root1 = BTtoDLL(root1);
        prev = null;
        root2 = BTtoDLL(root2);
        while(root1 != null && root2 != null){
            if(root1.data<=root2.data){
                res.add(root1.data);
                root1 = root1.right;
            }
            else{
                res.add(root2.data);
                root2 = root2.right;
            }
        }
        
        while(root1 != null){
            res.add(root1.data);
            root1 = root1.right;
        }
        
        while(root2 != null){
            res.add(root2.data);
            root2 = root2.right;
        }
        
        return res;
    }
    
    public Node BTtoDLL(Node root){
        if(root == null)
            return null;
            
        Node head = BTtoDLL(root.left);
        
        if(prev == null)
            head = root;
        else{
            prev.right = root;
            root.left = prev;
        }
        prev = root;
        
        BTtoDLL(root.right);
        
        return head;
    }
}
