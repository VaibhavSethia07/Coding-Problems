/*
Given a postfix expression, the task is to evaluate the expression and print the final value. Operators will only include the basic arithmetic operators like *,/,+ and -.

Input:
The first line of input will contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains an postfix expression.

Output:
For each test case, in a new line, evaluate the postfix expression and print the value.

Your Task:
This is a function problem. You need to complete the function evaluatePostfixExpression() that takes the string denoting the expression as input and returns the evaluated value.

Expected Time Complexity : O(n)
Expected Auixilliary Space : O(n)

Constraints:
1 <= T <= 1000
1 <= length of expression <= 1000

Example:
Input:
2
231*+9-
123+*8-
Output:
-4
-3

Explanation:
Testcase 1: After solving the given expression, we have -4 as result.
Testcase 2: After solving the given postfix expression , we have -3 as result.

#############################################################################Solution###############################################################################################
*/

class solve{
    public static int evaluatePostFix(String exp){
        Stack<Integer> st = new Stack<>();
        
        
        for(int i=0;i<exp.length();i++){
            char ch = exp.charAt(i);
            
            if(Character.isDigit(ch))
                st.push(ch-'0');
            else{
                int y = st.pop();
                int x = st.pop();
                
                switch(ch){
                    case '+': st.push(x+y);
                        break;
                    case '-': st.push(x-y);
                        break;
                    case '*': st.push(x*y);
                        break;
                    case '/': st.push(x/y);
                }
            }
        }
        
        return (int)st.pop();
    }
}

