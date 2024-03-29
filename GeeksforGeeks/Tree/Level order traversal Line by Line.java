/*
Given a Binary Tree, your task is to print its level order traversal such that each level is separated by $.
For the below tree the output will be 1 $ 2 3 $ 4 5 6 7 $ 8 $.

          1
       /     \
     2        3
   /    \     /   \
  4     5   6    7
    \
     8

Input:
The first line of input contains the number of test cases T. For every test case, the only line of input contains a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.

For example:

 
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
For each test case, in a new line, print the output in the required format.

Your Task:
This is a function problem. You don't need to read input. Just complete the function levelOrder() that takes nodes as parameter and prints level order line-by-line. The newline for every test case is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T<= 100
1 <= Number of edges <= 1000
1 <= Data of a node <= 100

Example:
Input:
2
1 4 N 4 2 
10 20 30 40 60 N N 
Output:
1 $ 4 $ 4 2 $
10 $ 20 30 $ 40 60 $

Explanation:
Testcase1: The tree is
                    1
                 /
               4
            /     \
         4        2
So, the level order would be 1 $ 4 $ 4 2 $
Testcase2: The tree is
                           10
                        /        \
                     20         30
                  /       \
               40       60
So, the level order would be 10 $ 20 30 $ 40 60 $

####################################################################################Solution#####################################################################################
*/

// Solution 1
class Level_Order_Traverse
{
    static void levelOrder(Node node) 
    {
        if(node == null)
            return;
        
        Queue<Node> q = new LinkedList<>();
        q.add(node);
        q.add(null);
        
        while(q.size()>1){
            Node curr = q.poll();
            if(curr != null)
                System.out.print(curr.data+" ");
            else{
                System.out.print("$ ");
                q.add(null);
                continue;
            }
            
            if(curr.left != null)
                q.add(curr.left);
                
            if(curr.right != null)
                q.add(curr.right);
        }
        System.out.print("$ ");
    }
}

// Solution 2
class Level_Order_Traverse
{
    static void levelOrder(Node node) 
    {
        if(node == null)
            return;
        
        Queue<Node> q = new LinkedList<>();
        q.add(node);
        
        while(!q.isEmpty()){
            int count = q.size();
            for(int i=0;i<count;i++){
                Node curr = q.poll();
                System.out.print(curr.data+" ");
                
                if(curr.left != null)
                    q.add(curr.left);
                
                if(curr.right != null)
                    q.add(curr.right);
            }
            
            System.out.print("$ ");
        }  
    }
}
