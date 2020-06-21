/*
Pattern Search KMP
Given a string S and a pattern P of all lowercase characters. The task is to check if the pattern exists in the string or not.

Input:
The first line of input contains the number of test cases T. For each testcase, the first line of input contains string S and the next line contains pattern P.

Output:
For each testcase, print "Yes" if the pattern is found in the string, and "No" if the pattern is not found in the string.

Your Task:
The task is to complete the function KMPSearch() which returns true or false depending on whether pattern is present in the string or not, and computeLPSArray() which computes the longest prefix suffix for every index.

Expected Time Complexity: O(N+M).
Expected Auxiliary Space: O(M).
Note: N = |S|, M = |P|.

Constrsaints:
1 <= T <= 100
1 <= |S|, |P| <= 104

Example:
Input:
2
aabaacaadaabaaba
aaaab
aabaacaadaabaaba
caada
Output:
No
Yes

Explanation:
Testcase 1: Given pattern is not found in the given string S.
Testcase 2: Given pattern is found in the given string S.

####################################################################Solution############################################################
*/

class match
{
    // Fills lps[] for given patttern pat[0..M-1] 
    void computeLPSArray(String pat, int M, int lps[]) 
    { 
        int len = 0;
        lps[0] = 0;
        int i=1;
        
        while(i<M){
            if(pat.charAt(i) == pat.charAt(len)){
                len++;
                lps[i++] = len;  
            }
            else{
               if(len == 0)
                    lps[i++] = 0;
                else
                    len = lps[len-1];
            }
        }
    }
    
    boolean KMPSearch(String pat, String txt)
    {
        int i=0,j=0;
        int N = txt.length();
        int M = pat.length();
        
        if(N<M)
            return false;
            
        int lps[] = new int[M];
        
        computeLPSArray(pat,M,lps);
        
        while(i<N){
            if(txt.charAt(i) == pat.charAt(j)){
                i++;
                j++;
            }
            
            if(j==M)
                return true;
            else if(i<N && txt.charAt(i) != pat.charAt(j)){
                if(j==0)
                    i++;
                else
                    j = lps[j-1];
            }
        }
        return false;
    }
}
