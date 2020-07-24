/*
Given a Binary search tree and a value X,  the task is to complete the function which will return the floor of x.

Note: Floor(X) is an element that is either equal to X or immediately smaller to X. If no such element exits return -1.

Input:
The first line of input contains the number of test cases T. For each test case, there will be only two lines of input, the first line contains a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

The second line of each test case will contain the integer value X.

Output:
For each test case, print the greatest smaller element of X.

Your task:
You don't need to worry about the insert function, just complete the function floor() which should return the floor of X.

Expected Time Complexity: O(Height of the BST)
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= X, Value of Node <= 106

Example:
Input:
2
8 5 9 2 6 N 10
3
3 2 5 N N 4 7 3
1

Output:
2
-1

Explanation:
Testcase 1: Floor of 3 in the given BST is 2
Testcase 2: No smaller element exits

###########################################################################################Solution##############################################################################
*/

// Iterative Solution
class Sol
{
    int floor(Node root, int key) 
    { 
        int res = -1;
        while(root != null){
            if(root.data == key)
                return root.data;
            else if(root.data<key){
                res = root.data;
                root = root.right;
            }
            else
                root = root.left;
        }
        return res;
    } 
}

// Recursive Soltion
class Sol
{
    int floor(Node root, int key) 
    { 
        if(root == null)
            return -1;
            
        if(root.data == key)
            return root.data;
        else if(root.data>key)
            return floor(root.left,key);
        else{
            int potFloor = floor(root.right,key);
            if(potFloor == -1)
                return root.data;
            return potFloor;
        }
    } 
 
}
