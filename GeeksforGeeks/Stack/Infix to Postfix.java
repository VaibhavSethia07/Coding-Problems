/*
Given an infix expression in the form of string str. Conver this infix expression to postfix expression.

Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
​Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. 
Input:
The first line of input contains an integer T denoting the number of test cases. The next T lines contain an infix expression. The expression contains all characters and ^,*,/,+,-. 

Output:
For each testcase, in a new line, output the infix expression to postfix expression.

Your Task:
This is a function problem. You only need to complete the function infixToPostfix() that takes a string as a parameter and returns the postfix expression. The printing is done automatically by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= length of str <= 103

Example:
Input:
2
a+b*(c^d-e)^(f+g*h)-i
A*(B+C)/D
Output:
abcd^e-fgh*+^*+i-
ABC+*D/

Explanation:
Testcase 1: After converting the infix expression into postfix expression , the resultant expression will be abcd^e-fgh*+^*+i-
Testcase 2: After converting the infix expression into postfix expression , the resultant expression will be ABC+*D/

#############################################################################Solution############################################################################################
*/

class solve{
	public static String infixToPostfix(String exp) {
	    String res = "";
	    Stack<Character> st = new Stack<>();
	    
		for(int i=0;i<exp.length();i++){
		    char chr = exp.charAt(i);
		    
		    if(Character.isLetterOrDigit(chr))
		        res += chr;
		    else if(chr == '(')
		        st.push(chr);
		    else if(chr == ')'){
		        while(!st.isEmpty() && st.peek() != '(')
		            res += st.pop();
		           
		        if(!st.isEmpty() && st.peek() == '(')
		            st.pop();
		    }
		    
		    else{ 
		    
		        while(!st.isEmpty() && precedence(chr) <= precedence(st.peek()))
		            res += st.pop();
		        
		        st.push(chr);
		    }
		}
		
		while(!st.isEmpty())
		    res += st.pop();
		    
		return res;
	}
	
	static int precedence(char chr){
	    switch(chr){
	        case '^' : return 3;
	        
	        case '*':
	        case '/': return 2;
	        
	        case '+': 
	        case '-': return 1;
	            
	        default :  return -1;
	        
	    }
	}
}
