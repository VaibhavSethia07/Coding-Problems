/*
Given a binary tree you need to check if it follows max heap property or not.
Input:
The task is to complete the method which takes one argument, root of Binary Tree. The struct Node has a data part which stores the data, pointer to left child and pointer to right child.There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return true if property holds else false.
 

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:
Input:
2
2
5 2 L 5 3 R
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
1
0

There are two test cases.  First case represents a tree with 3 nodes and 2 edges where root is 5, left child of 5 is 2 and right child of 5 is 3.   
Second test case represents a tree with 4 edges and 5 nodes.
###########################################################################Solution###############################################################################################
*/

// Naive Solution
class GfG
{
    /*You are required to complete this method */
    boolean isHeap(Node tree)
    {
        if(tree == null)
            return true;
            
        int cnt1 = getSize(tree);
        if(isProp1(tree,cnt1)==false)
            return false;
        return isProp2(tree);   
        
    }
    
    static int getSize(Node root){
        if(root == null)
            return 0;
        return 1+getSize(root.left)+getSize(root.right);
    } 
    
    static boolean isProp1(Node root,int cnt1){
        int cnt2 = 0;
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            Node curr = q.poll();
            if(curr == null)
                break;
            else
                cnt2++;
                
            q.add(curr.left);
            q.add(curr.right);
        }
        
        return cnt1==cnt2;
    }
    
    static boolean isProp2(Node root){
        if(root == null)    
            return true;
        boolean check = true;
        if(root.right != null && root.data<root.right.data)
            check = false;
        if(root.left != null && root.data<root.left.data)
            check = false;
            
        
        return check && isProp2(root.left) && isProp2(root.right);
    }
}

// Efficient Solution
class GfG
{
    /*You are required to complete this method */
    boolean isHeap(Node tree)
    {
        if(tree == null)
            return true;
            
        int cnt = getSize(tree);
        
        return isProp1(tree,0,cnt) && isProp2(tree);   
        
    }
    
    static int getSize(Node root){
        if(root == null)
            return 0;
        return 1+getSize(root.left)+getSize(root.right);
    } 
    
    static boolean isProp1(Node root,int index,int cnt){
        if(root == null)
            return true;
            
        if(index>=cnt)
            return false;
            
        return isProp1(root.left,2*index+1,cnt) && isProp1(root.right,2*index+2,cnt);
    }
    
    static boolean isProp2(Node root){
        if(root == null)    
            return true;
        boolean check = true;
        if(root.right != null && root.data<root.right.data)
            check = false;
        if(root.left != null && root.data<root.left.data)
            check = false;
            
        
        return check && isProp2(root.left) && isProp2(root.right);
    }
}
