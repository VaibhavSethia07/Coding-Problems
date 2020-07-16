/*
Complete the function to print spiral order traversal of a tree. For below tree, function should print 1, 2, 3, 4, 5, 6, 7.


 
 

Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
The function should print level order traversal in spiral form.

Your Task:
The task is to complete the function printSpiral() which prints the elements in spiral form of level order traversal. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 30
0 <= Number of nodes <= 105
1 <= Data of a node <= 105

Example:
Input:
2
1 3 2  
10 20 30 40 60 
Output:
1 3 2
10 20 30 60 40 

Explanation:
Testcase1: The tree is
        1
     /      \
   3       2
So, the spiral level order would be 1 3 2
Testcase2: The tree is
                           10
                        /        \
                     20         30
                  /       \
               40       60
So, the spiral level order would be 10 20 30 60 40

##########################################################################################Solution###############################################################################
*/

// Solution 1
class Spiral
{
      void printSpiral(Node node) 
      {
          if(node == null) return;
          
          boolean reverse = true;
          Queue<Node> q = new LinkedList<>();
          Stack<Integer> st = new Stack<>();
          
          q.add(node);
          while(!q.isEmpty()){
              int count = q.size();
              for(int i=0;i<count;i++){
                  Node curr = q.poll();
                  
                  if(reverse)
                    st.push(curr.data);
                  else
                    System.out.print(curr.data+" ");
                    
                  if(curr.left != null)
                    q.add(curr.left);
                  if(curr.right != null)
                    q.add(curr.right);
              }
              
              while(reverse && !st.isEmpty())
                System.out.print(st.pop()+" ");
            
            reverse = !reverse;
          }
          
      }
}

// Solution 2
class Spiral
{
      void printSpiral(Node node)
      {
          if(node == null)
            return;
        
          Stack<Node> s1 = new Stack<>();
          Stack<Node> s2 = new Stack<>();
          
          s1.push(node);
          while(!s1.isEmpty() || !s2.isEmpty()){
              Node curr;
              
              while(!s1.isEmpty()){
                  curr = s1.pop();
                  System.out.print(curr.data+" ");
                  
                  if(curr.right != null)
                    s2.push(curr.right);
                  if(curr.left != null)
                    s2.push(curr.left);
              }
              
              while(!s2.isEmpty()){
                  curr = s2.pop();
                  System.out.print(curr.data+" ");
                  
                  if(curr.left != null)
                    s1.push(curr.left);
                  if(curr.right != null)
                    s1.push(curr.right);
              }
          }
      }
}
