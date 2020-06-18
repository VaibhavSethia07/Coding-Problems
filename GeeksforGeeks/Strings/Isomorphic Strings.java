/*
Isomorphic Strings
Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character of str1 to every character of str2 while preserving the order.
Note: All occurrences of every character in ‘str1’ should map to the same character in ‘str2’

Input:
The first line contains an integer T, depicting the total number of test cases. Each test case contains two strings each in a new line.

Output:
Print "1" if strings are isomorphic and "0" if not.

User Task:
The task is to complete the function areIsomorphic() which checks if two strings are isomorphic. The function returns true if strings are isomorphic else it returns false.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Number of different characters).
Note: N = |str1|.

Constraints:
1 <= T <= 100
1 <= Length of Strings <= 103

Example:
Input:
2
aab
xxy
aab
xyz
Output:
1
0

Explanation:
Testcase 1: There are two different characters in aab and xxy, i.e a and b with frequency 2 and 1 respectively.
Testcase 2: There are two different characters in aab but there are three different characters in xyz. So there won't be one to one mapping between str1 and str2.

###########################################################Solution#####################################################################
*/

class Isomorphic{
    public static boolean areIsomorphic(String S1,String S2)
    {
        if(S1.length() != S2.length())
            return false;
            
        char arr1[] = new char[256];
        char arr2[] = new char[256];
        
        for(int i=0;i<S1.length();i++){
            char c1 = S1.charAt(i);
            char c2 = S2.charAt(i);
            
            if(arr1[c1]=='\u0000' && arr2[c2]=='\u0000'){
                arr1[c1] = c2;
                arr2[c2] = c1;
            }
            else if(arr1[c1]=='\u0000' || arr2[c2]=='\u0000')
                return false;
        }
        return true;
    }
}
