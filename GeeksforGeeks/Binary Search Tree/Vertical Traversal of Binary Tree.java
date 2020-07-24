/*
Given a Binary Tree, print the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Input Format:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:
 
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output Format:
For each testcase, the vertical order traversal of the tree is to be printed. The nodes' data are to be separated by spaces.

Your Task:
You don't need to read input or print anything. Your task is to complete the function verticalOrder() which takes the root node as input and returns an array containing the vertical order traversal of the tree from the leftmost to the rightmost level. If 2 nodes lie in the same vertical level, they should be printed in the order they appear in the level order traversal of the tree.

Expected Time Complexity: O(N log N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 5000

Example:
Input:
3
2 N 3 4 N
1 2 3 4 5 N 6
3 1 5 N 2 4 7 N N N N 6 
Output:
2 4 3
4 2 1 5 3 6
1 3 2 4 5 6 7
Explanation:
Testcase1:
         2
           \
            3
            /
         4
As it is evident from the above diagram that during vertical traversal 2, 4 will come first, then 3. So output is 2 1 5 3
Testcase2:
             1
           /     \
         2       3
      /     \        \
    4       5       6
As it is evident from the above diagram that during vertical traversal 4 will come first, then 2, then 1,5, then 3 and then 6. So the output is 4 2 1 5 3 6.

####################################################################################Solution#####################################################################################
*/

class BinaryTree
{
    static ArrayList <Integer> verticalOrder(Node root)
    {
        if(root == null)
            return new ArrayList<>();
        TreeMap<Integer,ArrayList<Integer>> tm = new TreeMap<>();
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(root,0));
        buildVerticalOrder(q,tm);
        return treeMapTraversal(tm);
        
    }
    
    static void buildVerticalOrder(Queue<Pair> q,TreeMap<Integer,ArrayList<Integer>> tm){
        
        while(!q.isEmpty()){
            Pair pair = q.poll();
            Node curr = pair.node;
            int hd = pair.hd;
            
            if(tm.containsKey(hd))
                tm.get(hd).add(curr.data);
            else{
                ArrayList<Integer> value = new ArrayList<>();
                value.add(curr.data);
                tm.put(hd,value);
            }
            
            if(curr.left != null)
                q.add(new Pair(curr.left,hd-1));
                
            if(curr.right != null)
                q.add(new Pair(curr.right,hd+1));
        }
    }
    
    static ArrayList<Integer> treeMapTraversal(TreeMap<Integer,ArrayList<Integer>> tm){
        ArrayList<Integer> result = new ArrayList<>();
        
        for(Map.Entry<Integer,ArrayList<Integer>> entry : tm.entrySet()){
            for(int ele : entry.getValue())
                result.add(ele);
        }
        
        return result;
    }
}

class Pair{
    int hd;
    Node node;
    Pair(Node node,int hd){
        this.node = node;
        this.hd = hd;
    }
}
