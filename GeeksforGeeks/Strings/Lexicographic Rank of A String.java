/*
Lexicographic Rank Of A String
You are given a string S of lowercase characters, find the rank of the string amongst its permutations when sorted lexicographically. Return 0 if the characters are repeated in the string.
Note: Return the rank%1000000007 as the answer as rank might overflow.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case consists of a string S in 'lowercase' only in a separate line.

Output:
For each testcase, in a new line, print the rank of the string amongst its lexicographically-sorted-permutations.

Your Task:
This is a function problem. You only need to complete the function findRank that takes string S as a parameter and returns the rank.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ T ≤ 50
1 ≤ |S| ≤ 15

Example:
Input:
2
abc
acb
Output:
1
2

Explanation:
Testcase 1: In 'abc' when we sort all the permutations in lexicographic order 'abc' will be at the first position.
Testcase2: In 'acb' .The lexicographically-sorted permutations with letters 'a', 'c', and 'b' will be at second position.

##############################################################Solution##################################################################
*/

class RankOfString
{   static int factorial[] = new int[20];

    static int findRank(String S) 
    {
        int rank = 1;
        int N = S.length();
        
        factorial[0] = 1;
        factorial[1] = 1;
 
        int mul = fact(N,factorial);
        int m = 1000000007;
        
        int count[] = new int[26];
        
        for(int i=0;i<N;i++){
            count[S.charAt(i)-'a']++;
            if(count[S.charAt(i)-'a']>=2)
                return 0;
        }
        
        for(int i=1;i<26;i++)
            count[i]+=count[i-1];
            
        for(int i=0;i<N;i++){
            mul = mul/(N-i);
            if(S.charAt(i)-'a' !=0)
                rank = (rank + mul*count[S.charAt(i)-'a'-1])%m;
                
            for(int j=S.charAt(i)-'a';j<26;j++)
                count[j]--;
        }
        return rank;
    }
    
    static int fact(int N,int [] factorial){
        if(factorial[N] == 0)
            factorial[N] = N*fact(N-1,factorial);
            
        return factorial[N];  
    }
}
