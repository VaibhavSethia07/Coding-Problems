/*
Given inorder and postorder traversals of a Binary Tree in the arrays in[] and post[] respectively. The task is to construct the binary tree from these traversals.
For example, if given inorder and postorder traversals are {4, 8, 2, 5, 1, 6, 3, 7} and {8, 4, 5, 2, 6, 7, 3, 1}  respectively, then your function should construct below tree.

          1
       /      \
     2        3
   /    \     /   \
  4     5   6    7
    \
      8

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of nodes in the tree, and next two lines contains inorder and postorder respectively.

Output:
For each testcase, print the preorder traversal of tree.

Your Task:
Complete the function buildTree() which takes the inorder, postorder traversals and the number of nodes in the tree as inputs and returns the root node of the newly constructed Binary Tree.

Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= N <= 103
1 <= in[i], post[i] <= 103

Example:
Input:
2
8
4 8 2 5 1 6 3 7
8 4 5 2 6 7 3 1
5
9 5 2 3 4
5 9 3 4 2
Output:
1 2 4 8 5 3 6 7
2 9 5 4 3

Explanation:
Testcase 1: For the given postorder and inorder traversal of tree the  resultant binary tree will be
          1
       /      \
     2        3
   /    \     /   \
  4     5   6    7
    \
      8
Testcase 2: For the given postorder and inorder traversal of tree the  resultant binary tree will be
               2
          /           \
        9            5
      /     \
    4      3

#################################################################################Solution########################################################################################
*/

// Naive Solution
class GfG {
    // Complete the function
    Node buildTree(int in[], int post[], int n) {
        int start = 0;
        int end = n-1;
        return construct(in,post,start,end,new Index(n));
    }
    
    Node construct(int in[],int post[],int start,int end,Index obj){
        if(start>end)
            return null;
            
        Node root = new Node(post[--obj.postIndex]);
        
        int inIndex = 0;
        for(int i=start;i<=end;i++){
            if(root.data == in[i]){
                inIndex = i;
                break;
            }
        }
        
        root.right = construct(in,post,inIndex+1,end,obj);
        root.left = construct(in,post,start,inIndex-1,obj);
        
        return root;
    }
}

class Index{
    int postIndex;
    Index(int postIndex){
        this.postIndex = postIndex;
    }
}

// Efficient Solution
class GfG {
    // Complete the function
    Node buildTree(int in[], int post[], int n) {
        if(n==0)
            return null;
            
        int start = 0;
        int end = n-1;
        Index obj = new Index(n);
        for(int i=0;i<n;i++)
            obj.hm.put(in[i],i);
            
        return construct(in,post,start,end,obj);
    }
    
    Node construct(int in[],int post[],int start,int end,Index obj){
        if(start>end)
            return null;
            
        Node root = new Node(post[--obj.postIndex]);
        
        int inIndex = obj.hm.get(root.data);
        
        root.right = construct(in,post,inIndex+1,end,obj);
        root.left = construct(in,post,start,inIndex-1,obj);
        
        return root;
    }
}

class Index{
    int postIndex;
    HashMap<Integer,Integer> hm;
    Index(int postIndex){
        this.postIndex = postIndex;
        hm = new HashMap<>();
    }
}
