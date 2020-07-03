/*
You are given a string str. You need to remove the pair of duplicates.
Note: The pair should be of adjacent elements and after removing a pair the remaining string is joined together. 

Input:
The first line of input contains T denoting the number of test cases. T test cases follow. Each testcase contains one line of input containing string str.

Output:
For each testcase, in a new line, print the modified string. If the final string is empty, then print "Empty String".

Your Task:
This is a function problem. You only need to complete the function removePair() that takes a string as a parameter and returns the modified string. Return an empty string if the whole string is deleted.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
N = length of string.

Constraints:
1 <= T <= 100
1 <= |str| <= 103

Examples:
Input:
2
aaabbaaccd
aaaa
Output:
ad
Empty String

Explanation:
Testcase1: Remove (aa)abbaaccd =>abbaaccd
Remove a(bb)aaccd => aaaccd
Remove (aa)accd => accd
Remove a(cc)d => ad
Testcase 2: Remove (aa)aa => aa
Again removing pair of duplicates then (aa) will be removed and we will get 'Empty String'.

################################################################################Solution#########################################################################################
*/

class solve
{
    // Function to print string after removing consecutive duplicates
    public static String removePair(String str){
        Stack<Character> st = new Stack<>();
        
        for(int i=str.length()-1;i>=0;i--){
            char x = str.charAt(i);
            if(st.isEmpty())
                st.push(x);
            else if(st.peek() == x)
                st.pop();
            else
                st.push(x);
        }
        
        String result = "";
        while(!st.isEmpty())
            result += st.pop();
            
        return result;
    }
}
