/*
Given two Binary Search Trees(without duplicates). Find need to print the common nodes in them. In other words, find intersection of two BSTs

Input:
The first line of input contains the number of test cases T. For each test case, there will be 2 lines of input. Each line will contain a string representing a tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.

For example:
 
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
For each test case, in a new line, print the nodes common to both BSTs in sorted order.

Your Task:
You don't need to read input or print anything. Your task is to complete the function printCommon() that takes roots of both the BSTs as input and returns an array containing the intersection of the 2 BSTs in a sorted order. 

Expected Time Complexity: O(N1 + N2) where N1 and N2 are the sizes of the 2 BSTs.
Expected Auxiliary Space: O(H1 + H2) where H1 and H2 are the Heights of the 2 BSTs.

Constraints:
1 <= T <= 400
1 <= N <= 103

Example:
Input:
2
5 1 10 0 4 7 N N N N N N 9
10 7 20 4 9
10 2 11 1 3
2 1 3
Output:
4 7 9 10
1 2 3

Explanation:
Testcase1: In the given two BSTs the common nodes are 4 7 9 and 10.

BST1:

                 5
              /      \
            1         10
          /   \        /
         0     4    7
                        \
                         9

BST2:

               10
             /    \
            7     20
          /   \
         4     9

The common elements of above two BSTs are 4 7 9 10
Testcase 2: In the given two BSTs the common nodes are  1 2 and 3.

#######################################################################################Solution##################################################################################
*/


// Method 1
class BST
{
	// print a list containing the intersection of the two BSTs in a sorted order
	public static ArrayList<Integer> printCommon(Node root1,Node root2)
    {
        ArrayList<Integer> res = new ArrayList<>();
        HashSet<Integer> hs = new HashSet<>();
        
        inorder(root1,hs);
        findCommon(root2,res,hs);
        return res;
    }
    
    static void inorder(Node root1,HashSet<Integer> hs){
        if(root1 == null)
            return;
            
        inorder(root1.left,hs);
        hs.add(root1.data);
        inorder(root1.right,hs);
    }
    
    static void findCommon(Node root2,ArrayList<Integer> res,HashSet<Integer> hs){
        if(root2 == null) return;
            
        findCommon(root2.left,res,hs);
        if(hs.contains(root2.data))
            res.add(root2.data);
        findCommon(root2.right,res,hs);
    }
}

// Method 2
class BST
{
	// print a list containing the intersection of the two BSTs in a sorted order
	public static ArrayList<Integer> printCommon(Node root1,Node root2)
    {
        Stack<Integer> s1 = new Stack<>();
        Stack<Integer> s2 = new Stack<>();
        ArrayList<Integer> res = new ArrayList<>();
        
        postOrder(root1,s1);
        postOrder(root2,s2);
        
        while(!s1.isEmpty() && !s2.isEmpty()){
           int x = s1.pop();
           int y = s2.pop();
           
           if(x==y)
                res.add(x);
           else if(x<y)
                s2.push(y);
           else
                s1.push(x);
        }
        
        return res;
        
    }
    
    static void postOrder(Node root,Stack<Integer> s){
        if(root == null)
            return;
        postOrder(root.right,s);
        s.push(root.data);
        postOrder(root.left,s);
    }
    
}
