/*
Given an array arr[] of N elements to be inserted into BST and a number X. The task is to check if any pair exists in BST or not whose sum is equal to X.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of elements to be inserted into BST. Next line contains elements to be inserted into BST and last line contains X.

Output:
For each testcase, print "1" (without quotes) if pair with sum X exists in BST, else print "0" (without quotes).

Your Task:
No need to worry about the insert function in BST, just write your code for the boolean function findPair() to check if a pair with given sum X exists in BST or not. The function returns true or false.

Expected Time Complexity: O(Height of the BST)
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= arr[i] <= 105

Example:
Input:
2
5
8 5 1 3 9
4
6
0 1 2 7 8 3
6
Output:
1
0

Explanation:
Testcase 1: For the given input, there exist a pair whose sum is, i.e, (3,1).
Testcase 2: For the given input , there exists no such pair whose sum is 6.

############################################################################Solution#############################################################################################
*/

// Naive Solution
class GFG {

    // This function should return true
    // if there is a pair in given BST with
    // given sum.
    static boolean findPair(Node root, int sum) {
        ArrayList<Integer> res = new ArrayList<>();
        
        inorder(root,res);
        
        int start = 0;
        int end = res.size()-1;
        
        while(start<end){
            int value = res.get(start)+res.get(end);
            if(value==sum)
                return true;
            else if(value>sum)
                end--;
            else
                start++;
        }
        return false;
    }
    
    static void inorder(Node root,ArrayList<Integer> res){
        if(root == null)
            return;
            
        inorder(root.left,res);
        res.add(root.data);
        inorder(root.right,res);
    }
}

// Efficient Solution
class GFG {

    // This function should return true
    // if there is a pair in given BST with
    // given sum.
    static boolean findPair(Node root, int sum) {
        HashSet<Integer> hs = new HashSet<>();
        return getPair(root,sum,hs);
    }
    
    static boolean getPair(Node root,int sum,HashSet<Integer> hs){
        if(root == null)
            return false;
        
        if(hs.contains(sum-root.data))
            return true;
        else
            hs.add(root.data);
        
        return getPair(root.left,sum,hs) || getPair(root.right,sum,hs);
    }
}
