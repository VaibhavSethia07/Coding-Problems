/*
Pangram Checking
Given a string check if it is Pangram or not. A pangram is a sentence containing every letter in the English Alphabet.

Input:
The first line of input contains an integer 'T' denoting the number of test cases then T test cases follow. Each testcase contains a String 'S'.

Output:
For each test case print in a new line 1 if it's a pangram else print 0 .

Your Task:
This is a function problem. You need to complete the function checkPangram that takes a string as a parameter and returns true if the string is a pangram, else it returns false.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Number of distinct characters).

Constraints:
1 <= T <= 100
1 <= |S| <= 104

Example:
Input:
2
Bawds jog, flick quartz, vex nymph
sdfs
Output:
1
0

Explanation :
Testcase 1: In the given input, there are all the letters of the English alphabet. Hence, the output is 1.
Testcase 2: In the given input, there aren't all the letters present in the English alphabet. Hence, the output is 0.

#########################################################Solution#######################################################################
*/

class solve
{
    public static boolean checkPangram  (String s)
    {
        if(s.length()<26)
            return false;
            
        boolean isAnagram[] = new boolean[26];
        
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)-'A'<26 && s.charAt(i)-'A'>=0)
                isAnagram[s.charAt(i)-'A'] = true;
            else if(s.charAt(i)-'a'<26 && s.charAt(i)-'a'>=0)
                isAnagram[s.charAt(i)-'a'] = true;
        }
        
        for(int i=0;i<26;i++)
            if(isAnagram[i] == false)
                return false;
        return true;
    }
}
