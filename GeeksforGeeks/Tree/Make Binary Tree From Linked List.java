/*
Given a Linked List Representation of Complete Binary Tree. The task is to construct the Binary tree.
Note : The complete binary tree is represented as a linked list in a way where if root node is stored at position i, its left, and right children are stored at position 2*i+1, 2*i+2 respectively.
 



Input:
First line of input contains number of testcases T. For each testcase, first line of input contains length of linked list and next line contains linked list elements.

Output:
Output of each test case will be the level order traversal of the the constructed binary tree.

User Task:
The task is to complete the function convert() which takes head of linked list and root of the tree as the reference. The driver code prints the level order.

Constraints:
1 <= T <= 100
1 <= N <= 103
1 <= Ki <= 103

Example:
Input:
2
5
1 2 3 4 5
5
5 4 3 2 1
Output:
1 2 3 4 5
5 4 3 2 1

Explanation:
Testcase 1: Given tree is 
                            1
                         /      \
                       2        3
                    /      \
                  4        5
Now, the level order traversal of the above tree is 1 2 3 4 5.
Testcase 2: Given tree is  
                            5
                         /      \
                       4        3
                    /      \
                  2        1
Now, the level order traversal of the above tree is 5 4 3 2 1.

################################################################################Solution#########################################################################################
*/

class GfG {
    public static Tree convert(Node head, Tree node) {
        if(head == null)
            return node;
            
        ArrayList<Integer> arr = new ArrayList<>();
        Node curr = head;
        while(curr != null){
            arr.add(curr.data);
            curr = curr.next;
        }
        node = new Tree(arr.get(0));
        convertUtil(node,arr,0);
        return node;
    }
    
    static void convertUtil(Tree root,ArrayList<Integer> arr,int index){
        if(index>=arr.size())
            return;
        if(2*index+1<arr.size())    
            root.left = new Tree(arr.get(2*index+1));
        
        if(2*index+2<arr.size())
            root.right = new Tree(arr.get(2*index+2));
        convertUtil(root.left,arr,2*index+1);
        convertUtil(root.right,arr,2*index+2);
    }
}
