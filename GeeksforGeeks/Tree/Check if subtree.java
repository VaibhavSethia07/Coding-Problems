/*
Given two binary trees with head reference as T and S having at most N nodes. The task is to check if S is present as subtree in T.
A subtree of a tree T1 is a tree T2 consisting of a node in T1 and all of its descendants in T1.

Example:

S:          10
              /   \
            4     6
                 /
             30

T:                  26
                      /   \
                    10   3
                   /   \     \

               4       6     3
                       /
                    30

In above example S is subtree of T.

Please note that subtree has to be having same leaves non leaves.

   10
  /
20

For example, above tree is not subtree of

         10
       /     \
    20     50
   /   \
30   40

But a subtree of

         30
       /     \
    10     50
   /  
20  

Input:
First line of input contains the number of test cases T. For each test case, there will be two lines of input each of which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N.

First string denotes tree T and second string denotes tree S.

Output:
For each testcase, there will be a single line containing 0 or 1, depending on the input.

Your Task:
Complete the function isSubtree() that takes two nodes as parameter and returns true or false.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= N <= 104

Example:
Input:
3
1 2 3 N N 4
3 4
26 10 N 20 30 40 60
26 10 N 20 30 40 60
26 10 3 4 6 N 3 N N N 25
10 4 6 N 30
Output:
1
1
0

Explanation:
Testcase 1: Given trees are 
T:                   1                                                        S:                   3
                   /      \                                                                          /
                 2       3                                                                       4
               /    \    /   
             N    N  4
S is the subtree in T.
Testcase 2: Given trees are
T:                    26                                                         S:                              26
                    /        \                                                                                     /       \
                  10       N                                                                                 10       N
                 /      \                                                                                      /       \
               20    30                                                                                  20      30
             /      \                                                                                      /       \
          40     60                                                                                  40      60
S is present as subtree in T.
Testcase 3: Given trees are
T:                                   26                                                      S:                                      10
                                     /    \                                                                                               /   \
                                   10    3                                                                                           4    6
                                    / \      \                                                                                            \
                                   4  6     3                                                                                          30
                                         \
                                          25
10 is root node of tree. Left child of 10 is 4 and right child of 10 is 6. Right child of 4 is 30.

##################################################################################Solution#######################################################################################
*/
// Naive Solution
class Tree {
    public static boolean isSubtree(Node T, Node S) {
        if(T==null && S==null)
            return true;
        else if(T==null && S!=null)
            return false;
        else if(T!=null && S==null)
            return false;
        boolean lc; 
        boolean rc;
        
        if(T.data==S.data){
             lc = isSubtree(T.left,S.left);
             rc = isSubtree(T.right,S.right);
             if(lc && rc)
                return true;
            else{
                return isSubtree(T.left,S) || isSubtree(T.right,S);
            }
        }
        else{
             lc = isSubtree(T.left,S);
             rc = isSubtree(T.right,S);
             if(!lc && !rc)
                return false;
        }
        return true;
    }
}

// Effcient Solution
class Tree {
    public static boolean isSubtree(Node T, Node S) {
        if(T==null && S==null)
            return true;
        else if(T==null && S!=null)
            return false;
        else if(T!=null && S==null)
            return false;
        boolean lc; 
        boolean rc;
        
        if(T.data==S.data){
             lc = isSubtree(T.left,S.left);
             rc = isSubtree(T.right,S.right);
             if(lc && rc)
                return true;
        }
    
        lc = isSubtree(T.left,S);
        rc = isSubtree(T.right,S);
        if(!lc && !rc)
            return false;
                
        return true;
    }
}
