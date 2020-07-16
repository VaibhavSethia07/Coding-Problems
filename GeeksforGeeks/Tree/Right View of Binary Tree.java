/*
Given a Binary Tree, print Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

Right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /   \      /    \
  4     5   6    7
    \
     8

Input :
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output :
For each test case, in a new line, print the right view of the binary tree.

Your Task:
This is a function problem. You don't have to take input. Just complete the function rightView() that takes node as parameter and prints the right view. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 105
1 <= Data of a node <= 105

Example:
Input:
2
1 3 2
10 20 30 40 60
Output:
1 2
10 30 60

Explanation:
Test case 1: Below is the given tree

           1
         /     \
      3        2
For the above test case the right view is: 1 2
Test case 2: Below is the given tree

            10
         /        \
     20          30
   /      \      
40      60

Right View is: 10 30 60.

##################################################################################Solution#######################################################################################
*/

// Method 1
class Level{
    int maxLevel;
    
    Level(int maxLevel){
        this.maxLevel = maxLevel;
    }
}
class Tree{
    void rightView(Node node) {
        rightViewUtil(node,1,new Level(0));
    }
    
    static void rightViewUtil(Node root,int level,Level obj){
        if(root == null) return;
        
        if(obj.maxLevel<level){
            System.out.print(root.data+" ");
            obj.maxLevel = level;
        }
        rightViewUtil(root.right,level+1,obj);
        rightViewUtil(root.left,level+1,obj);
    }
}

//Method 2
class Tree{
    void rightView(Node root) {
        if(root == null) return;
        
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            int count = q.size();
            Node curr = null;
            for(int i=0;i<count;i++){
                curr = q.poll();
                
                if(curr.left != null)
                    q.add(curr.left);
                if(curr.right != null)
                    q.add(curr.right);
            }
            System.out.print(curr.data+" ");
        }
    }
}
