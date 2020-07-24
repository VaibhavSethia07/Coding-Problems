/*
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Print from leftmost node to rightmost node.

Input Format:

First line of input contains the number of test cases T. For each test case, there will be two lines: 

First line of each test case will be an integer N denoting the number of parent child relationships.

Second line of each test case will print the level order traversal of the tree in the form of N space separated triplets. The description of triplets is as follows:

Each triplet will contain three space-separated elements of the form (int, int, char).

The first integer element will be the value of parent. 

The second integer will be the value of corresponding left or right child. In case the child is null, this value will be -1.

The third element of triplet which is a character can take any of the three values ‘L’, ‘R’ or ‘N’. L denotes that the children is a left child, R denotes that the children is a Right Child and N denotes that the child is NULL.

Please note that the relationships are printed only for internal nodes and not for leaf nodes. 

Output Format:
For each test case, in a new line, print top view of the binary tree level wise. The nodes should be separated by space.

Your Task:
Since this is a function problem. You don't have to take input. Just complete the function printTopView() that takes root node as parameter and prints the top view. The newline is automatically appended by the driver code.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N).

 Constraints:
1 <= T <= 30
1 <= N <= 105
1 <= Node Data <= 105
Sum of all testcases doesn't exceed 105

Example:
Input:
2
2
1 2 L 1 3 R
6
10 20 L 10 30 R 20 40 L 20 60 R 30 90 L 30 100 R

Output:
2 1 3
40 20 10 30 100

Explanation:
Testcase 1:

           1

        /     \

      2        3

For the above test case the top view is: 2 1 3
Test case 2:

            10

         /        \

     20          30

   /      \       /     \

40      60 90     100

TopView is: 40 20 10 30 100

#####################################################################################Solution####################################################################################
*/

class View
{
    // function should print the topView of the binary tree
    static void topView(Node root)
    {
        if(root == null)
            return;
            
        Queue<Pair> q = new LinkedList<>();
        TreeMap<Integer,Integer> tm = new TreeMap<>();
        q.add(new Pair(root,0));
        
        buildTopView(q,tm);
        treeMapTraversal(tm);
    }
    
    static void buildTopView(Queue<Pair> q,TreeMap<Integer,Integer> tm){
        while(!q.isEmpty()){
            Pair pair = q.poll();
            Node curr = pair.node;
            int hd = pair.hd;
            
            if(!tm.containsKey(hd))
                tm.put(hd,curr.data);
                
            if(curr.left != null)
                q.add(new Pair(curr.left,hd-1));
            
            if(curr.right != null)
                q.add(new Pair(curr.right,hd+1));
        }
    }
    
    static void treeMapTraversal(TreeMap<Integer,Integer> tm){
        Iterator<Map.Entry<Integer,Integer>> itr = tm.entrySet().iterator();
        
        while(itr.hasNext()){
            Map.Entry<Integer,Integer> entry = itr.next();
            System.out.print(entry.getValue()+" ");
        }
    }
}

class Pair{
    Node node;
    int hd;
    Pair(Node node,int hd){
        this.node = node;
        this.hd = hd;
    }
}
