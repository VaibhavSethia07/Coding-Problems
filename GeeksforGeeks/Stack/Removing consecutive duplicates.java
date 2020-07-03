/*
Stacks can be used to remove duplicate characters from a string that are stacked next to each other. For example, we take the string aabbccccc and convert it into abc. We can push the first character into a stack and skip if the top of the stack is equal to the current character.
You are given a string str. You need to remove the consecutive duplicates.

Input:
The first line of input contains T denoting the number of test cases. T test cases follow. Each testcase contains one line of input containing string str.

Output:
For each testcase, in a new line, print the modified string.

Your Task:
This is a function problem. You need to complete the function removeConsecutiveDuplicates() that takes a string as a parameter and returns the modified string. The printing is done automatically by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= |str| <= 103

Examples:
Input:
2
aaaaaabaabccccccc
abbccbcd
Output:
ababc
abcbcd

####################################################################################Solution#######################################################################################
*/

class solve
{
    // Function to print string after removing consecutive duplicates
    public static String removeConsecutiveDuplicates(String str){
        Stack<Character> unique = new Stack<>();
        
        for(int i = 0;i<str.length();i++){
            char x = str.charAt(i);
            
            if(unique.isEmpty() || unique.peek() != x)
                unique.push(x);
        }
        
        Iterator<Character> itr = unique.iterator();
        String result = "";
        
        while(itr.hasNext())
            result += itr.next();
        
        return result;
    }
}
