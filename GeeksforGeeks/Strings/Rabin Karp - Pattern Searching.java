/*
Rabin Karp - Pattern Searching
Given a string S and a pattern P of lowercase characters. The task is to check if the pattern is present in string or not.

Input:
The first line of input contains the number of test cases T. For each testcase, the first line of input contains string S and the next line contains pattern P.

Output:
For each testcase, print "Yes" if the pattern is found in the string else print "No".

Your Task:
This is a function problem. You need to complete the function search which takes 3 arguments(S, P and prime q) and returns true if the pattern is found else returns false.

Expected Time Complexity: O(N + M).
Expected Auxiliary Space: O(1).
Note: N = |S|, M = |P|.

Constraints:
1 <= T <= 100
1 <= |S|, |P| <= 104

Example:
Input:
2
aabaacaadaabaaba
aaba
aabaacaadaabaaba
asdfa
Output:
Yes
No

Explanation:
Testcase 1: You can find the patter at starting at index 12.
Testcase 2: Pattern doesn't exist in the given string S.

###############################################################Solution#################################################################
*/

class match
{
    static int d= 256;
    
    static boolean search(String pat, String txt, int q)
    {
        int h = 1;
        int t = 0;
        int p = 0;
        
        int N = txt.length();
        int M = pat.length();
        
        if(N<M)
            return false;
        
        for(int i=1;i<=M-1;i++)
            h = (h*d)%q;
            
        for(int i=0;i<M;i++){
            t = (t*d + txt.charAt(i))%q;
            p = (p*d + pat.charAt(i))%q;
        }
        
        for(int i=0;i<=N-M;i++){
            if(t==p){
                int j;
                for(j=0;j<M;j++)
                    if(txt.charAt(i+j) != pat.charAt(j))
                        break;
                        
                if(j==M)
                    return true;
            }
            
            if(i<N-M){
                t = ((t-txt.charAt(i)*h)*d + txt.charAt(i+M))%q;
                if(t<0)
                    t+=q;
            }
        }
        
        return false;
    }
}
