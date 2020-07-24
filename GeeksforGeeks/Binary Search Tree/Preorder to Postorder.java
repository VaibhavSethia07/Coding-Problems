/*
Given an array arr[] of N nodes representing preorder traversal of BST. The task is to print its postorder traversal.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, the size of array. The second line of each test case contains N input as arr[i].

Output:
For each testcase, in a new line, postorder traversal of the given preorder traversal is printed.

Your Task:
You need to complete the given function and return the root of the tree. The driver code will then use this root to print the post order traversal.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= N <= 103
1 <= arr[i] <= 104

Example:
Input:
2
5
40 30 35 80 100
8
40 30 32 35 80 90 100 120

Output:
35 30 100 80 40
35 32 30 120 100 90 80 40

Explanation:
Test Case 1:
PreOrder: 40 30 35 80 100
InOrder: 30 35 40 80 100
Therefore, the BST will be:
              40
            /      \
         30       80
             \         \   
             35      100

Hence, the postOrder traversal will be: 35 30 100 80 40

######################################################################################Solution###################################################################################
*/

// Naive Solution
static int preIndex;
public static Node constructTree(int pre[], int size) {
    int in[] = new int[size];
    for(int i=0;i<size;i++)
        in[i] = pre[i];
    preIndex = 0;
    Arrays.sort(in);
    return constructing(in,pre,0,size-1);
} 

public static Node constructing(int in[],int pre[],int start,int end){
    if(start>end)
        return null;
        
    Node root = new Node(pre[preIndex++]);
    
    int inIndex=0;
    for(int i=start;i<=end;i++)
        if(in[i] == root.data){
            inIndex = i;
            break;
        }
        
    root.left = constructing(in,pre,start,inIndex-1);
    root.right = constructing(in,pre,inIndex+1,end);
    
    return root;
}

// Efficient Solution
static int preIndex;
public static Node constructTree(int pre[], int size) {
    int in[] = new int[size];
    HashMap<Integer,Integer> hs = new HashMap<>();
    for(int i=0;i<size;i++)
        in[i] = pre[i];
        
    preIndex = 0;
    
    Arrays.sort(in);
    for(int i=0;i<size;i++)
        hs.put(in[i],i);
        
    return constructing(hs,pre,0,size-1);
} 

public static Node constructing(HashMap<Integer,Integer> hs,int pre[],int start,int end){
    if(start>end)
        return null;
        
    Node root = new Node(pre[preIndex++]);
    
    int inIndex=hs.get(root.data);
    
        
    root.left = constructing(hs,pre,start,inIndex-1);
    root.right = constructing(hs,pre,inIndex+1,end);
    
    return root;
}

// Best Solution
static int preIndex;
public static Node constructTree(int pre[], int size) {
    preIndex = 0;
    return constructing(pre,Integer.MIN_VALUE,Integer.MAX_VALUE);
}

public static Node constructing(int pre[],int min,int max){
    if(min>max || preIndex>=pre.length)
        return null;
        
    Node root = null;
    if(pre[preIndex]>=min && pre[preIndex]<max)
        root = new Node(pre[preIndex++]);
    else
        return null;
    
    root.left = constructing(pre,min,root.data);
    root.right = constructing(pre,root.data,max);
    
    return root;
}

