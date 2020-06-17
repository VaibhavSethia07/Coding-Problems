/*
Distinct Pattern Search
Given a string S and a pattern P (of distinct characters) consisting of lowercase characters. The task is to check if pattern P exists in the given string S or not.
Note : Pattern has distinct characters. There might be repetitions in text.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains string S and next line contains pattern P.

Output:
For each testcase, print "Yes" if pattern is found in the given string, else print "No".

User Task:
The task is to complete the function search() which finds for the pattern with distinct characters. The function takes string and pattern as parameters and returns either true or false. Return true if pattern is found else return false.

Expected Time Complexity: O(N + M).
Expected Auxiliary Space: O(1).
Note: N = |S|, M = |P|.

Constraints:
1 <= T <= 100
1 <= |S|, |P| <= 103

Example:
Input:
2
abceabcdabceabcd
abcd
abceabcdabceabcd
gfhij
Output:
Yes
No

##############################################################Solution##################################################################
*/

class Search{
    static boolean search(String pat, String txt)
    {
        int N = txt.length();
        int M = pat.length();
        
        if(N<M)
            return false;
            
        for(int i=0;i<=N-M;){
            int j;
            for(j=0;j<M;j++){
                if(txt.charAt(i+j) != pat.charAt(j)){
                    if(j==0){
                        i++;
                        break;
                    }
                    else{
                        i+=j;
                        break;
                    }
                }
            }
            
            if(j==M)
                return true;
        }
        return false;
    }
}
