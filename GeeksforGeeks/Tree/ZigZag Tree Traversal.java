/*
Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:


For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
For each test case print on a new line space-separated all the nodes of the tree in ZigZag manner.

Your Task:
You don't need to read input or print anything. Your task is to complete the function zigZagTraversal() which takes the root node of the Binary Tree as its input and returns a list containing the node values as they appear in the Zig-Zag Level-Order Traversal of the Tree.
For Example: For the below binary tree the zigzag order traversal will be 1 3 2 7 6 5 4. Binary Tree Example

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= N <= 104

Example:
Input:
2
3 2 1
7 7 9 8 8 6 N 10 9
Output:
3 1 2
7 9 7 8 8 6 9 10

Explanation:
Testcase 1: Given tree is
                         3
                      /       \
                    2        1
Hence the zigzag traversal will be 3 1 2.
Testcase 2: Given tree is 
                           7
                       /        \
                    9           7
                /        \      /     \
               8        8    6     N
            /      \
          10     9  
Hence the zigzag traversal will be 7 9 7 8 8 6 9 10.

########################################################################################Solution#################################################################################
*/

// Method 1
class GFG
{
    // return an array containing the zig zag level order traversal of the given tree
	ArrayList<Integer> zigZagTraversal(Node root)
	{
	    ArrayList<Integer> res = new ArrayList<>();
	    if(root == null)
	        return res;
	    
	    Stack<Integer> st = new Stack<>();
	    Queue<Node> q = new LinkedList<>();
	    boolean reverse = false;
	    
	    q.add(root);
	    while(!q.isEmpty()){
	        int count = q.size();
	        for(int i=0;i<count;i++){
	            Node curr = q.poll();
	            if(reverse)
	                st.push(curr.data);
	            else
	                res.add(curr.data);
	                
	            if(curr.left != null)
	                q.add(curr.left);
	            if(curr.right != null)
	                q.add(curr.right);
	                
	        }
	        
	        while(reverse && !st.isEmpty()){
	            res.add(st.pop());
	        }
	        
	        reverse = !reverse;
	    }
	    return res;
	}
}

// Method 2
class GFG
{
    // return an array containing the zig zag level order traversal of the given tree
	ArrayList<Integer> zigZagTraversal(Node root)
	{
	    ArrayList<Integer> res = new ArrayList<>();
	    
	    if(root == null)
	        return res;
	        
	    Stack<Node> s1 = new Stack<>();
	    Stack<Node> s2 = new Stack<>();
	    
	    s1.push(root);
	    while(!s1.isEmpty() || !s2.isEmpty()){
	        Node curr;
	        while(!s1.isEmpty()){
	            curr = s1.pop();
	            res.add(curr.data);
	            
	            if(curr.left != null)
	                s2.push(curr.left);
	               
	            if(curr.right != null)
	                s2.push(curr.right);
	        }
	        
	        while(!s2.isEmpty()){
	            curr = s2.pop();
	            res.add(curr.data);
	            
	            if(curr.right != null)
	                s1.push(curr.right);
	                
	            if(curr.left != null)
	                s1.push(curr.left);
	        }
	    }
	    return res;
	}
}
