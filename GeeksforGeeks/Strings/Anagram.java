/*
Anagram
Given two strings a and b consisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, “act” and “tac” are an anagram of each other.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case consists of two strings in 'lowercase' only, in a single line.

Output:
Print "YES" without quotes if the two strings are anagram else print "NO".

User Task:
The task is to complete the function isAnagram() which checks if the two strings are an anagram of each other. The function returns true if the strings are anagram else it returns false.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Number of distinct characters).

Constraints:
1 ≤ T ≤ 300
1 ≤ |s| ≤ 105

Example:
Input:
2
geeksforgeeks forgeeksgeeks
allergy allergic
Output:
YES
NO

Explanation:
Testcase 1: Both the string have same characters with same frequency. So, both are anagrams.
Testcase 2: Characters in both the strings are not same, so they are not anagrams.

###############################################################Solution#################################################################
*/

class Anagram{    
    public static boolean isAnagram(String s1,String s2)
    {
        if(s1.length()!= s2.length())
            return false;
        
        int count[] = new int[26];
        
        for(int i=0;i<s1.length();i++){
            count[s1.charAt(i)-'a']++;
            count[s2.charAt(i)-'a']--;
        }
        
        for(int i=0;i<26;i++)
            if(count[i]!=0)
                return false;
        
        return true;
    }
}
