/*
Repeating Character - First Appearance Leftmost
You are given a string S (both uppercase and lowercase characters). You need to print the repeated character whose first appearance is leftmost.

Input:
The first line of input contains T denoting the number of test cases. T test cases follow. Each testcase contains one line of input containing String S.

Output:
For each testcase, in a new line, print the character.

Your Task:
This is a function problem. You only need to complete the function repeatedCharacter() that takes a string as a parameter and returns the index of the character. If no character repeats then return -1.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Number of distinct characters).

Constraints:
1 <= T <= 100
1 <= |S| <= 100

Examples:
Input:
2
geeksforgeeks
abcd
Output:
g
-1

Explanation:
Testcase1: We see that both e and g repeat as we move from left to right. But the leftmost is g so we print g.
Testcase2: No character repeats so we print -1.

#################################################################Solution###############################################################
*/
//Solution 1

class Repeatation
{
    static int repeatedCharacter(String S)
    {
        int count[] = new int[256];
        Arrays.fill(count,-1);
        int result = Integer.MAX_VALUE;
        
        for(int i=0;i<S.length();i++){
            if(count[S.charAt(i)] == -1)
                count[S.charAt(i)] = i;
            else
                result = Math.min(result,count[S.charAt(i)]);
        }
        
        if(result == Integer.MAX_VALUE)
            return -1;
        return result;
    }
}

//Solution 2

class Repeatation
{
    static int repeatedCharacter(String S)
    {
        int count[] = new int[256];
        int result = -1;
        Arrays.fill(count,-1);
        
        for(int i=S.length()-1;i>=0;i--){
            if(count[S.charAt(i)] == -1)
                count[S.charAt(i)] = i;
            else
                result = count[S.charAt(i)];
        }
        return result;
    }
}
