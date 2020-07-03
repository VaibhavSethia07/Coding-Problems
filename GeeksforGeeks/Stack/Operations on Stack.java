/*
Given a stack of integers and Q queries. The task is to perform the operation on stack according to the query.

Input:
The first line of input contains the number of test cases T. For each testcase, the first line of input contains Q, the number of queries. The next line contains Q queries separated by space. Queries are as follows:

i x: (adds element x in the stack).

r: (removes the topmost element from the stack).

h: Prints the topmost element.

f y: (check if the element y is present or not in the stack). Print "Yes" if present, else "No".

Output:
For each testcase, perform Q queries and print the output wherever required.

Your Task:
Your task is to complete functions insert(), remove(), headOf_Stack() which takes a stack as input parameter and find() which takes a stack and value as input parameter, to insert, remove returning top element, and finding the element in stack respectively.

Expected Time Complexity: For find(): O(N), For others: O(1).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= Q <= 103

Example:
Input:
2
6
i 2 i 4 i 3 i 5 h f 8
4
i 3 i 4 r f 3
Output:
5
No
Yes

Explanation:
Testcase 1: Inserting 2, 4, 3, and 5 onto the stack. Returning top element which is 5. Finding 8 will give No, as 8 is not in the stack.
Testcase 2: Inserting 3 and 4 onto the stack. Finding 3 will give Yes as output because 3 is available in the stack.

#########################################################################Solution################################################################################################
*/

class Geeks
{
    // Function to insert element to stack
    public static void insert(Stack<Integer> st, int x)
    {
        st.push(x);
    }
    
    // Function to pop element from stack
    public static void remove(Stack<Integer> st)
    {
        int x = st.pop();
        
    }
    
    // Function to return top of stack
    public static void headOf_Stack(Stack<Integer> st)
    {
        int x = st.peek();
        System.out.println(x + " ");
    }
    
    // Function to find the element in stack
    public static boolean find(Stack<Integer> st, int val)
    {
        boolean exists = false;
        if(st.search(val) != -1)
            exists = true;
        
        return exists;
        
    }
}
