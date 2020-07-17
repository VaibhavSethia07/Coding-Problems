/*
Serialization is to store a tree in an array so that it can be later restored and Deserialization is reading tree back from the array. Now your task is to complete the function serialize which stores the tree into an array A[ ] and deSerialize which deserializes the array to tree and returns it.
Note: The structure of tree must be maintained.

Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
The output in the expected output will be the inorder traversal of the returned tree.

Your Task:
The task is to complete two function serialize which takes the root node of the tree as input andstores the tree into an array and deSerialize which deserializes the array to the original tree and returns the root of it.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 1000
1 <= Data of a node <= 1000

Example:
Input:
2
1 2 3
10 20 30 40 60
Output:
2 1 3
40 20 60 10 30

Explanation:
Testcase 1: Given tree is 
                           1
                       /         \
                     2           3
Hence , the given output is 2 1 3.
Testcase 2: Given tree is 
                         10
                       /       \
                     20      30
                  /        \
                40      60
Hence, the given output is 40 20 60 10 30.

#########################################################################################Solution################################################################################
*/

class Tree {
    int index;
	public void serialize(Node root, ArrayList<Integer> A) {
	    if(root == null){
	        A.add(-1);
	    }else{
	        A.add(root.data);
    	    serialize(root.left,A);
    	    serialize(root.right,A);
	    }
	}
	
    public Node deSerialize(ArrayList<Integer> A){
        if(index == A.size())
            return null;
        int val = A.get(index);
        index++;
        if(val == -1)
            return null;
        Node root = new Node(val);
        
        root.left =deSerialize(A);
        root.right=deSerialize(A);
        
        return root;
        
    }
}
