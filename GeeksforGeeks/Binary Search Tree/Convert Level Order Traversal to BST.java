/*
Given an array of size N containing level order traversal of a BST. The task is to complete the function constructBst(), that construct the BST (Binary Search Tree) from its given level order traversal.

Input:
First line of input contains number of testcases T. For each testcase, first line contains number of elements and next line contains n elements which is level order travesal of a BST.

Output:
For each test return the pointer to the root of the newly constructed BST.

User Task:
Your task is to complete the function constructBst() which has two arguments, first as the array containing level order traversal of BST and next argument as the length of array.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= N <= 103

Example:
Input:
2
9
7 4 12 3 6 8 1 5 10
6
1 3 4 6 7 8

Output:
7 4 3 1 6 5 12 8 10
1 3 4 6 7 8

Explanation:
Testcase 1: After constructing BST, the preorder traversal of BST is 7 4 3 1 6 5 12 8 10.
Testcase 2: After constructing BST, the preorder traversal of BST is 1 3 4 6 7 8.

####################################################################################Solution#####################################################################################
*/

// Naive Method
class GFG {
    
    public Node constructBST(int[] arr){
        int N = arr.length;
        Node root = null;
        for(int i=0;i<N;i++)
            root = insert(root,arr[i]);
            
        return root;
    }
    
    static Node insert(Node root,int x){
        if(root == null)
            return new Node(x);
        
        if(root.data>x)
            root.left = insert(root.left,x);
        else if(root.data<x)    
            root.right = insert(root.right,x);
            
        return root;
    }
}

// Efficient Method
class GFG {
    
    public Node constructBST(int[] arr){
        int N = arr.length;
        
        if(N==0)
            return null;
            
        Queue<Range> q = new LinkedList<>();
        Range root = new Range(arr[0]);
        q.add(root);
        int i=1;
        while(!q.isEmpty()){
            Range curr = q.poll();
            
            if(i<N && arr[i]>curr.min && arr[i]<curr.data){
                Range currLeft = new Range(arr[i]);
                curr.left = currLeft;
                currLeft.min = curr.min;
                currLeft.max = curr.data;
                q.add(currLeft);
                i++;
            }
            
            if(i<N && arr[i]>curr.data && arr[i]<curr.max){
                Range currRight = new Range(arr[i]);
                curr.right = currRight;
                currRight.min = curr.data;
                currRight.max = curr.max;
                q.add(currRight);
                i++;
            }
        }
        
        return (Node)root;
    }
}

class Range extends Node{
    int min = Integer.MIN_VALUE;
    int max = Integer.MAX_VALUE;
    Range(int x){
        super(x);
    }
}
