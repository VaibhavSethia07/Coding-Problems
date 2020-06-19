/*
Given two strings s1 and s2. Modify both the strings such that all the common characters of s1 and s2 are to be removed and the uncommon characters of s1 and s2 are to be concatenated.
Note: If all characters are removed print -1.

Input:
The first line consists of an integer T i.e number of test cases. The first line of each test case consists of a string s1. The next line consists of a string s2. 

Output:
Print the concatenated string.

User Task:
The task is to complete the function concatenatedString() which removes the common characters, concatenates, and returns the string. If all characters are removed then return -1.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Number of distinct characters).

Constraints: 
1 <= T <= 200
1 <= |Length of Strings| <= 104

Example:
Input:
2
aacdb
gafd
abcs
cxzca
Output:
cbgf
bsxz

Explanation:
Testcase 1:The common characters of s1 and s2 are: a, d. The uncommon characters of s1 and s2 are c, b, g and f. Thus the modified string with uncommon characters concatenated is cbgf.
Testcase 2: The common characters of s1 and s2 are: a,c. The uncommon characters of s1 and s2 are b,s,x and z. Thus the modified string with uncommon characters concatenated is bsxz.

###################################################################Solution#############################################################
*/

class RemoveCommon{
    
    public static String concatenatedString(String s1,String s2){
        int count1[] = new int[256];
        int count2[] = new int[256];
        
        String result= "";
        
        for(int i=0;i<s1.length();i++)
            count1[s1.charAt(i)]++;
            
        for(int i=0;i<s2.length();i++)
            count2[s2.charAt(i)]++;
         
        for(int i=0;i<s1.length();i++)
            if(count2[s1.charAt(i)] == 0)
                result+=s1.charAt(i);
                
        for(int i=0;i<s2.length();i++)
            if(count1[s2.charAt(i)] == 0)
                result+=s2.charAt(i);
        if(result.equals(""))
            System.out.print(-1);
        return result;
        
    }
}
